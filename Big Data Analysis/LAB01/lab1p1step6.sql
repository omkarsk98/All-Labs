SELECT
  c.gender
  , AVG(o.item_price) AS avg_price 
FROM
  ddemo.order_lineitems o 
JOIN
  ddemo.customers_dim c 
   ON o.customer_id = c.customer_id 
GROUP BY c.gender 
;

