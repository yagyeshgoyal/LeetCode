# Write your MySQL query statement below
select s.name
from SalesPerson s
left join 
(select o.sales_id as id from Company c , Orders o where c.com_id = o.com_id and c.name = 'RED') as t
on s.sales_id = t.id
where t.id is NULL