WITH cte AS(
    SELECT st.student_id as student_id,st.student_name AS student_name,sub.subject_name AS subject_name
    FROM Students st
    CROSS JOIN Subjects sub
)
SELECT c.student_id,c.student_name,c.subject_name,COUNT(e.student_id) AS attended_exams
FROM cte c
LEFT JOIN Examinations e on e.subject_name=c.subject_name AND e.student_id = c.student_id
GROUP BY c.student_id,c.student_name,c.subject_name
ORDER BY c.student_id,c.subject_name;
