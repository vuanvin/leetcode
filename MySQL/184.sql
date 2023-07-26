CREATE TABLE Employee (
    id INT,
    name VARCHAR,
    salary INT,
    departmentId INT
);
CREATE TABLE Department (id INT, name VARCHAR);
SELECT d.name AS 'Department',
    ne.name AS 'Employee',
    ne.salary AS 'Salary'
FROM (
        SELECT e.*
        FROM Employee AS e,
            (
                SELECT departmentId AS max_id,
                    MAX(salary) AS max_salary
                FROM Employee
                GROUP BY departmentId
            ) AS m
        WHERE m.max_salary = e.salary
            AND m.max_id = e.departmentId
    ) AS ne
    LEFT JOIN Department AS d ON ne.departmentId = d.id;
SELECT Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM Employee
    JOIN Department ON Employee.DepartmentId = Department.id
WHERE (Employee.DepartmentId, Salary) IN (
        SELECT DepartmentId,
            MAX(Salary)
        FROM Employee
        GROUP BY DepartmentId
    );