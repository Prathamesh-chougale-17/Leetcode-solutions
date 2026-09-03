# Write your MySQL query statement below
SELECT
PERSON_NAME FROM
(
    SELECT 
    person_name,
    SUM(weight) OVER (ORDER BY turn) AS running_total
    FROM Queue
) AS V
WHERE V.RUNNING_TOTAL<=1000
ORDER BY V.RUNNING_TOTAL DESC
LIMIT 1;