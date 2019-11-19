SELECT
  SUM(c) as total_records 
  , SUM(case when c>1 THEN c-1 ELSE 0 END) AS total_dupes 
  , COUNT(*) AS total_uniques 
FROM( 
  SELECT
    count(*) AS c
  FROM
    housing
  GROUP BY
    serialno, state 
) dupes 
; 
