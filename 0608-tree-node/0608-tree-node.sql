# Write your MySQL query statement below
SELECT 
    id,
    CASE 
        -- Rule 1: If it has no parent, it is the Root
        WHEN p_id IS NULL THEN 'Root'
        
        -- Rule 2: If its id is someone else's parent, it is an Inner node
        WHEN id IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner'
        
        -- Rule 3: Anything else must be a Leaf node
        ELSE 'Leaf'
    END AS type
FROM Tree;
