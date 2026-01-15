import tensorflow as tf    # tensorflow의 별명은 tf로 한다
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt

# MNIST 데이터를 학습용, 테스트 데이터로 구분하여 읽어옴
mnist = keras.datasets.mnist
(train_images, train_labels), (test_images, test_labels) = mnist.load_data()
# 입력값 전처리 : 0에서 1사이의 값으로 입력 데이터를 가공함
(train_images, test_images) = (train_images / 255, test_images / 255)
model = keras.Sequential([
    keras.layers.Input(shape=(28, 28)),
    keras.layers.Flatten(),
    keras.layers.Dense(256, activation='relu'),
    keras.layers.Dense(128, activation='relu'),
    keras.layers.Dense(64, activation='relu'),
    keras.layers.Dense(10, activation='softmax') # softmax -> 분류 종류가 3가지 이상이구나.
])
model.summary()
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])
model.fit(train_images, train_labels, epochs=10)
test_loss, test_acc = model.evaluate(test_images, test_labels, verbose=2)
model.save("my_first_DNN_model.keras")
load_model = keras.models.load_model("my_first_DNN_model.keras")
load_model.summary()
randIdx = np.random.randint(0, 6000)  # 6000개의 테스트 이미지 중 하나를 선택
rand_test_images = test_images[randIdx]
plt.imshow(test_images[randIdx])
plt.show()
predict_image = load_model.predict(rand_test_images[np.newaxis, :, :])
print(predict_image.argmax())
