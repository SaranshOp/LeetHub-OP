import pandas as pd

# def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
#     newsalary = employee.sort_values(by = "salary", ascending=False).drop_duplicates(subset="salary", keep='first')
#     if  employee["salary"].nunique() < 2:
#         salary=pd.DataFrame({'SecondHighestSalary':[pd.NA]})
#     else:
#         p = newsalary.iloc[1]["salary"]
#         salary=pd.DataFrame({'SecondHighestSalary':[p]})
#     return salary    
    
def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    employee.drop_duplicates(subset=["salary"], inplace=True)
    if employee.shape[0] < 2 :
        return pd.DataFrame([[None]], columns=["SecondHighestSalary"])
    employee.sort_values(by="salary", inplace=True, ascending=False)
    employee = employee[["salary"]]
    employee.rename(columns={"salary" : "SecondHighestSalary"}, inplace=True)
    return employee.iloc[1:2]

    # newsalary = employee.sort_values(by = "salary", ascending=False).drop_duplicates(subset="salary", keep='first')
    # employee.sort_values(by="salary", inplace=True, ascending=False)
    # employee.drop_duplicates(subset=["salary"], inplace=True)
    # employee["salary"].nunique() < 2:
    # employee.shape[0] < 2 :
    # employee.rename(columns={"salary" : "SecondHighestSalary"}, inplace=True)