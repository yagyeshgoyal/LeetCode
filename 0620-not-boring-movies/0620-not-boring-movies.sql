# Write your MySQL query statement below
select t.* from (select * from Cinema order by rating desc) as t

where mod(t.id,2) = 1 && t.description != 'boring';
