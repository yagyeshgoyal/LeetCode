# Write your MySQL query statement below
-- method 1
-- SELECT name "Customers"
-- FROM Customers
-- WHERE id NOT IN (SELECT customerId FROM Orders);


-- method 2
SELECT c.name "Customers"
FROM Customers c
LEFT JOIN Orders o
  ON c.id = o.customerId
WHERE o.customerId IS NULL;