SELECT 
   SUM(cte1.item_price), 
   cte1.product_category_name
FROM 
(
SELECT 
   ol.*,
   cd.gender
FROM 
   ddemo.order_lineitems ol,
   ddemo.customers_dim cd
WHERE 
    ol.customer_id = cd.customer_id and cd.gender = 'M') cte1

GROUP BY 
    cte1.product_category_name
ORDER BY 
    1 DESC LIMIT 6
;
