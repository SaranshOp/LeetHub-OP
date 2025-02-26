# Write your MySQL query statement below
select ea.name from Employee ea
join Employee eb on ea.id = eb.managerId
group by ea.id, ea.name
having count(eb.id) >= 5;
