import cv2
import numpy as np
import tensorflow as tf
from tensorflow import keras
import matplotlib.pyplot as plt
import random

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("웹캠을 열 수 없습니다.")
    exit()

digits = []
password = random.sample(range(10), 4)
print("password:", password)
B = 0
S = 0
history = []

# 학습된 모델 불러오기
load_model = keras.models.load_model("my_first_DNN_model.keras")

def capture_and_predict(roi, load_model):
    gray_image = cv2.cvtColor(roi, cv2.COLOR_BGR2GRAY)
    gray_image = np.flip(gray_image, 1)
    #cv2.imwrite("gray_image.png", gray_image)
    gaussian_blur = cv2.GaussianBlur(gray_image, (5, 5), 3)
    # 2진화
    _, otsu_thread = cv2.threshold(gaussian_blur, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)
    #cv2.imshow("otsu_thread", otsu_thread)
    # Morph, 전처리
    kernel = np.ones((5, 5), np.uint8)
    erosion = cv2.erode(otsu_thread, kernel, iterations=3)
    #cv2.imshow("erosion", erosion)
    #cv2.imwrite("digit_binary_image.png", erosion)
    # 이미지 자르기
    img = erosion
    h, w = img.shape[:2]
    crop_size = 280
    cx, cy = w //2 , h //2
    half = crop_size // 2
    x1, x2 = cx - half, cx + half
    y1, y2 = cy - half, cy + half
    # 경계면 설정
    x1 = max(0, x1)
    y1 = max(0, y1)
    x2 = min(w, x2)
    y2 = min(h, y2)

    cropped_img = img[y1:y2, x1:x2]
    #cv2.imshow("cropped_img", cropped_img)

    # 이미지 반전
    reversed_img = cv2.bitwise_not(cropped_img)
    #cv2.imshow("reversed_img", reversed_img)
    #cv2.imwrite("reversed_img.png", reversed_img)

    # 28 x 28 resize
    resized_img = cv2.resize(reversed_img, (28, 28))
    #cv2.imshow("resized_img", resized_img)
    #cv2.imwrite("IMAGE_FOR_TEST.png", resized_img)

    # 학습된 모델에 전처리 후 입력
    divided_img = resized_img.astype(np.float32) / 255.0
    predict_image = load_model(divided_img[np.newaxis, :, :], training = False).numpy()
    return int(np.argmax(predict_image))

while True:
    ret, frame = cap.read()
    if not ret:
        print("프레임을 가져올 수 없습니다.")
        break
    flip_frame = cv2.flip(frame,1)
    height, width, _ = frame.shape
    center_x, center_y = width // 2, height // 2
    roi = flip_frame[center_y - 150:center_y + 150, center_x - 150 :center_x + 150]
    cv2.rectangle(flip_frame, (center_x-150, center_y-150), (center_x+150, center_y+150), (0, 0, 255), 2)
    digits_text = "".join(map(str, digits))
    cv2.putText(flip_frame, f"INPUT: {digits_text}", (20, 30),
                cv2.FONT_HERSHEY_PLAIN, 2, (255, 0, 0), 2)
    #history_display = " | ".join(history[-3:])  # 최근 3개만 표시
    cv2.putText(flip_frame, f"HISTORY:", (20, 60),
                cv2.FONT_HERSHEY_PLAIN, 1.5, (255, 0, 0), 2)
    # 최근 5개 기록을 줄바꿈으로 표시
    start_y = 90      # 첫 줄 y좌표
    line_gap = 30     # 줄 간격
    for i, h in enumerate(history[-12:]):
        cv2.putText(flip_frame, h, (20, start_y + i * line_gap), cv2.FONT_HERSHEY_PLAIN,
                    1.3, (255, 0, 0), 2 )
    cv2.imshow("Webcam", flip_frame)
    # 화면 캡쳐를 위한 키 값 받기
    key = cv2.waitKey(1) & 0xFF

    if key in (ord('c'), ord('C')):
        digit = capture_and_predict(roi, load_model)
        digits.append(digit)
        #print(f"입력된 숫자: {digit}")
        if len(digits) == 4:
            #print("최종 입력:", digits)
            if digits == password:
                cv2.putText(flip_frame, "Correct", (20, 70),
                    cv2.FONT_HERSHEY_PLAIN, 2, (0, 255, 0), 2)
                cv2.imshow("Webcam", flip_frame)
                cv2.waitKey(1000)
                break
            else:
                B = 0
                S = 0
                for i in range(4):
                    if digits[i] == password[i]:
                        S += 1
                    elif digits[i] in password:
                        B += 1
                guess = "".join(map(str, digits))
                history.append(f"{guess} -> {B}B {S}S")

                cv2.putText(flip_frame, f"{B}B {S}S", (20, 70),
                            cv2.FONT_HERSHEY_PLAIN, 2, (0, 0, 255), 2)
                cv2.imshow("Webcam", flip_frame)
                cv2.waitKey(1000)
                digits.clear()

    if key in (ord('b'), ord('B')) and digits:
        digits.pop()

    elif key == 27:
        break

cap.release()
cv2.destroyAllWindows()
