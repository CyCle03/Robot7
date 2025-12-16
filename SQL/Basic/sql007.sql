CREATE TABLE employees (
    dept TEXT,
    job TEXT,
    salary INTEGER
);

INSERT INTO employees VALUES
('개발','백엔드',6000),
('개발','백엔드',6500),
('개발','프론트',5500),
('개발','프론트',5200),
('영업','영업사원',4000),
('영업','영업사원',4200),
('영업','팀장',7000),
('인사','인사담당',4500),
('인사','팀장',6000),
('인사','팀장',6200);

SELECT * FROM employees;

SELECT dept FROM employees;

SELECT dept, avg(salary)
FROM employees
GROUP BY dept;

SELECT dept, max(salary)
FROM employees
GROUP BY dept;

SELECT dept, min(salary)
FROM employees
GROUP BY dept;

SELECT dept, min(salary)
FROM employees
GROUP BY dept;

SELECT dept, round(avg(salary),2)
FROM employees
GROUP BY dept
HAVING avg(salary) >=5000;

SELECT dept, count(*)
FROM employees
GROUP BY dept
HAVING count(*) >3;
