-- SELECT 
--   request_at AS Day, 
--   ROUND(
--     SUM(status != 'completed') / COUNT(*), 
--     2
--   ) AS 'Cancellation Rate' 
-- FROM 
--   Trips 
--   LEFT JOIN Users AS Clients ON Trips.client_id = Clients.users_id 
--   LEFT JOIN Users AS Drivers ON Trips.driver_id = Drivers.users_id 
-- WHERE 
--   Clients.banned = 'No' 
--   AND Drivers.banned = 'No' 
--   AND request_at BETWEEN '2013-10-01' 
--   AND '2013-10-03' 
-- GROUP BY Day


-- select 
--     request_at as Day,
--     round(sum(case when status like 'cancelled%' then 1.00 else 0 end) / count(status), 2) as "Cancellation Rate"
-- from (
--     select t.request_at, t.status
--     from Trips t
--     where t.driver_id not in (
--         select u.users_id 
--         from Users u 
--         where u.banned = 'Yes'
--     ) 
--         and t.client_id not in (
--         select u.users_id 
--         from Users u 
--         where u.banned = 'Yes'
--     ) 
--         and request_at between '2013-10-01' AND '2013-10-03'
-- ) as derived_table_alias
-- group by request_at;


-- SELECT 
--   request_at AS Day, 
--   ROUND(
--     SUM(status != 'completed') / COUNT(status), 
--     2
--   ) AS 'Cancellation Rate' 
-- FROM 
--   Trips 
-- WHERE 
--   request_at BETWEEN '2013-10-01' 
--   AND '2013-10-03' 
--   AND driver_id NOT IN (
--     SELECT 
--       users_id 
--     FROM 
--       Users 
--     WHERE 
--       banned = 'Yes'
--   ) 
--   AND client_id NOT IN (
--     SELECT 
--       users_id 
--     FROM 
--       Users 
--     WHERE 
--       banned = 'Yes'
--   ) 
-- GROUP BY 
--   Day

WITH TripStatus AS (
  SELECT 
    Request_at AS Day, 
    T.status != 'completed' AS cancelled 
  FROM 
    Trips T 
    JOIN Users C ON Client_Id = C.Users_Id 
    AND C.Banned = 'No' 
    JOIN Users D ON Driver_Id = D.Users_Id 
    AND D.Banned = 'No' 
  WHERE 
    Request_at BETWEEN '2013-10-01' 
    AND '2013-10-03'
) 
SELECT 
  Day, 
  ROUND(
    SUM(cancelled) / COUNT(cancelled), 
    2
  ) AS 'Cancellation Rate' 
FROM 
  TripStatus 
GROUP BY 
  Day;
