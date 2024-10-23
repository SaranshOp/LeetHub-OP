import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    n_employee = employee[["salary"]].drop_duplicates(inplace=False)
    n_employee = n_employee.sort_values(by = "salary" , inplace = False, ascending = False)
    n_employee = n_employee.rename(columns = {"salary":f"getNthHighestSalary({N})"}, inplace = False)
    if n_employee.shape[0] < N or N <= 0:
        return pd.DataFrame([[None]], columns=[f"getNthHighestSalary({N})"])
    else:
        return n_employee[[f"getNthHighestSalary({N})"]].iloc[N-1:N]