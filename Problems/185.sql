SELECT Department.name AS 'Department',
    e1.name AS 'Employee',
    e1.salary AS 'Salary'
FROM Employee AS e1
    JOIN Department ON e1.DepartmentId = Department.id
WHERE 3 > (
        SELECT COUNT(DISTINCT e2.salary)
        FROM Employee AS e2
        WHERE e2.salary > e1.salary
            AND e1.DepartmentId = e2.DepartmentId
    );