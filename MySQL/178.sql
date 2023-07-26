select a.Score as 'score',
    (
        select count(distinct b.Score)
        from Scores b
        where b.Score >= a.Score
    ) as 'rank'
from Scores a
order by a.Score desc;
---
select a.Score,
    count(distinct b.Score) as 'rank'
from Scores a,
    Scores b
where a.Score <= b.Score
group by a.Id
order by 'rank';