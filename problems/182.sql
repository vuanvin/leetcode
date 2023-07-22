SELECT email AS Email
FROM (
        SELECT email,
            COUNT(email) AS cnt
        FROM Person
        GROUP BY email
    ) AS stat
WHERE cnt > 1;
---
SELECT Email
FROM Person
GROUP BY email
HAVING count(Email) > 1;