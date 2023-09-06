# Write your MySQL query statement below
SELECT customer_number 
FROM Orders 
GROUP BY customer_number
HAVING COUNT(order_number)=
    (SELECT COUNT(order_number) cnt
     FROM Orders
     GROUP BY customer_number
	 ORDER BY cnt DESC
	 LIMIT 1 
    )
