CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    -- Safely handle edge cases where N is 0 or negative
    IF N <= 0 THEN
        RETURN NULL;
     ELSE
         SET N = N - 1;
    END IF;
    RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary
        FROM employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET N

  );
END