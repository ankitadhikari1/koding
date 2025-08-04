# Write your MySQL query statement below
select name from Salesperson where sales_id NOT IN
(select sales_id from Orders where com_id = 
(select com_id from company where name='RED')
)