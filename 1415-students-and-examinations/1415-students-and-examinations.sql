# Write your MySQL query statement below
select stu.student_id, stu.student_name, SU.subject_name, count(exams.student_id) as attended_exams 
from Students stu
CROSS JOIN Subjects SU
left join Examinations exams 
    on stu.student_id = exams.student_id 
    and SU.subject_name = exams.subject_name

group by stu.student_name, SU.subject_name
ORDER BY stu.student_id, stu.student_name, SU.subject_name