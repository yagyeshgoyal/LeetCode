# Write your MySQL query statement below
select e.email "Email"
from (select count(*) , email 
        from Person
        group by email 
        having count(*)>1
        ) as e
