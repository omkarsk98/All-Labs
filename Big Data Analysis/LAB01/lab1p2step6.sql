CREATE TABLE housing_nodupes AS
SELECT 
  DISTINCT ON (serialno, state) * 
FROM 
  housing 
DISTRIBUTED BY(serialno, state)
;
