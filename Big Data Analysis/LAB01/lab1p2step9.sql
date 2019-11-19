\a
\o lab1_02.txt
SELECT 
  educ AS Education_Level
  , SUM(white) AS White 
  , SUM(black) AS Black 
  , SUM(aian) AS American_Indian_Alaska_Native 
  , SUM(asian) AS Asian
  , SUM(nhpi) AS Hawaii_Pacific_Islander
  , SUM(other) AS Others 
FROM
  persons 
WHERE
  age > 17
  AND educ > 0 
GROUP BY educ 
ORDER BY educ
;
