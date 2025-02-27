# Write your MySQL query statement below

select T.product_id ,IFNULL(round(sum(IFNULL(price,0) *IFNULL(units,0)) / sum(IFNULL(units,0)),2),0) as average_price 
from(
    select P.product_id , P.price, US.units 
    from Prices P
    left join UnitsSold US on US.product_id = P.product_id and US.purchase_date between P.start_date and P.end_date
) as T
group by T.product_id;