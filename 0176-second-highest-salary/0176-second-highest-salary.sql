# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from employee 
where salary < (select max(salary) from Employee)


-- select
-- ifnull((select distinct salary
-- from Employee
-- order by salary desc
-- limit 1 offset 1), null) as SecondHighestSalary

-- import pandas as pd

-- def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
--     newsalary = employee.sort_values(by = "salary", ascending=False).drop_duplicates(subset="salary", keep='first')
--     if  employee["salary"].nunique() < 2:
--         salary=pd.DataFrame({'SecondHighestSalary':[pd.NA]})
--     else:
--         p = newsalary.iloc[1]["salary"]
--         salary=pd.DataFrame({'SecondHighestSalary':[p]})
--     return salary    
    