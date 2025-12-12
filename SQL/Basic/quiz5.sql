-- **5.1** `Person` 테이블을 나이가 많은 사람이 먼저 오도록 정렬해서 조회해보라. 생일을 알 수 없는 사람은 제외한다.

SELECT * FROM Person WHERE Birthday IS NOT NULL
ORDER BY Birthday;

-- **5.2** `Person` 테이블에서 `Name`이 `김`으로 시작하는 행을 찾아서, 그 값을 `유라`로 바꾸어 보라.
UPDATE Person SET Name = '유라'
WHERE Name like '김%';
