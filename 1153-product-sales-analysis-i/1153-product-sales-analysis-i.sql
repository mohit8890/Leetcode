# Write your MySQL query statement below
select product_name, year, price 
from Product right JOIN Sales
USING (product_id)