SELECT id
FROM
(SELECT id,
        temperature,
        recordDate,
    LAG(temperature,1) OVER(ORDER BY recordDate) as preTemp,
    LAG(recordDate,1) OVER(ORDER BY recordDate) as preDate
FROM Weather) as t
WHERE temperature>preTemp
    AND DATEDIFF(recordDate,preDate)=1;
