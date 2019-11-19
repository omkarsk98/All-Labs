DROP TABLE income_state;
CREATE TABLE income_state AS
SELECT 
   f.name state,  
   round(avg(h.hinc),0) AS income  
FROM
   housing h 
JOIN
   fips f
ON
   h.state = f.code
WHERE 
   (h.hinc > 0 )
GROUP BY
    f.name
 DISTRIBUTED BY (income); 
