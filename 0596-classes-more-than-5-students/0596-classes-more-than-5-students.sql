select class
from 
    (select class, count(distinct student) as num
    from courses
    group by class) as temp
where num >= 5;