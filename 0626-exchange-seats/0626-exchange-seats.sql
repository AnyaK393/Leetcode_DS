# Write your MySQL query statement below
SELECT 
    CASE 
        -- If id is odd and it is the last row, keep it the same
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id
        -- If id is odd, increment it by 1 to swap with the next even id
        WHEN id % 2 = 1 THEN id + 1
        -- If id is even, decrement it by 1 to swap with the previous odd id
        ELSE id - 1
    END AS id,
    student
FROM Seat
ORDER BY id ASC;
