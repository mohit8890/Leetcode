select 
    id, 
    movie,
    description,
    rating
from Cinema c
where c.description <> 'boring' and c.id % 2 <> 0
order by c.rating desc