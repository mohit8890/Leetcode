
# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016
from Insurance I
where tiv_2015 IN (select tiv_2015 from Insurance I2 WHERE I.pid != I2.pid)
and (lat,lon) NOT IN (select lat,lon from Insurance I3 WHERE I.pid != I3.pid)