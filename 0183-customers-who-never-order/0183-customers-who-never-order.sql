# Write your MySQL query statement below
SELECT name "Customers"
FROM Customers
WHERE id NOT IN (SELECT customerId FROM Orders);


-- SELECT c.name
-- FROM Customer c
-- LEFT JOIN Orders o
--   ON c.id = o.customerId
-- WHERE o.customerId IS NULL;