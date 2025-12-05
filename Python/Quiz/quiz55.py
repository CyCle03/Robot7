score = int(input("학점 입력:"))

if score < 0 or 100 < score:
    print("잘못 입력하셨습니다.")
elif 90 <= score <= 100:
    print("A")
elif 80 <= score:
    print("B")
elif 70 <= score:
    print("C")
elif 60 <= score:
    print("D")
else:
    print("F")
