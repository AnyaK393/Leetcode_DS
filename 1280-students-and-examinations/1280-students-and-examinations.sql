# Write your MySQL query statement below
#select s.student_id,s.student_name, e.subject_name , sum(attended_exams) from student as s join examination as e on s.student_id=e.student_id group by student_id;

SELECT
    s.student_id,
    s.student_name,
    sub.subject_name,
    COUNT(e.student_id) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS e
    ON s.student_id = e.student_id
    AND sub.subject_name = e.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;