# Write your MySQL query statement below
select requester_id as id, COUNT(accepter_id) as num from
(select requester_id, accepter_id
 from requestaccepted
 UNION
 select accepter_id, requester_id
 from requestaccepted
) temp
group by requester_id
order by num DESC
limit 1

