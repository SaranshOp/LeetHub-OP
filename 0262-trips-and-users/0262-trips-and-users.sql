select 
    request_at as Day,
    round(sum(case when status like 'cancelled%' then 1.00 else 0 end)/count(status), 2) as "Cancellation Rate"
from Trips t
    join Users u on t.client_id = u.users_id and u.banned = 'No'
    join Users us on t.driver_id = us.users_id and us.banned = 'No'
where request_at between '2013-10-01' AND '2013-10-03'
    and u.banned = 'No'
group by request_at;


-- select 
--     request_at as Day,
--     round(sum(case when status like 'cancelled%' then 1.00 else 0 end) / count(status), 2) as "Cancellation Rate"
-- from (
--     select t.request_at, t.status
--     from Trips t, Users u, (
--         select u.users_id 
--         from Users u 
--         where u.banned = 'No'
--     ) as us
--     where us.users_id = t.client_id 
--         and us.users_id = t.driver_id 
--         and request_at between '2013-10-01' AND '2013-10-03'
-- ) subquery
-- group by request_at;
