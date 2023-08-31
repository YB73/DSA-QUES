# Write your MySQL query statement below
select p.project_id, round(sum(e.experience_years)/count(*),2) as average_years from 
Employee as e right join Project as p
on e.employee_id = p.employee_id 
group by p.project_id;