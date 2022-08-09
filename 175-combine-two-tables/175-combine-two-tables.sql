# Write your MySQL query statement below
# select p.firstName , p.lastName , a.city , a.state from Person p , Address a where p.personId = a.personId;
select p.firstName , p.lastName , a.city , a.state from Person p left outer join Address a on p.personId = a.personId;