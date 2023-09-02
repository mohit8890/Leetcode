# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT name AS Employee
FROM Employee e
WHERE salary > (
    SELECT m.salary
    FROM Employee m
    WHERE m.id = e.managerId
);