CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE m int;
SET m = N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary from Employee order by salary desc limit m,1
  );
END