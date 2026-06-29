# Write your MySQL query statement below
WITH allStu AS(
    SELECT s.student_id,s.student_name,sub.subject_name
    FROM Students s
    CROSS JOIN Subjects sub
),


CTE AS(
    SELECT student_id,subject_name,COUNT(*) AS attended_exams
    FROM Examinations
    GROUP BY student_id,subject_name
)

SELECT s.student_id,s.student_name,s.subject_name,COALESCE(t.attended_exams,0) as attended_exams
FROM allStu s
LEFT JOIN CTE t ON s.student_id=t.student_id
AND s.subject_name = t.subject_name
ORDER BY s.student_id,s.subject_name;
