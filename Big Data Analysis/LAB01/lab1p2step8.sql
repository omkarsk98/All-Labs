\a
\o lab1_01.txt
SELECT
  serialno
  , hinc
  , rooms 
FROM
  housing_nodupes 
WHERE 
  hinc  > 0
       AND state = 25
;
