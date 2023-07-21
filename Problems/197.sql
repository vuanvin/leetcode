SELECT w1.id
FROM weather w1
    left join weather w2 on w1.recordDate = DATE_ADD(w2.recordDate, INTERNAL 1 DAY)
WHERE w1.Temperature > w2.Temperature;