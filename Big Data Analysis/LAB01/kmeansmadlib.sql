DROP TABLE IF EXISTS myschema.data;
CREATE  TABLE 
   myschema.data (
        pid INT, 
        position FLOAT8[]) 
   DISTRIBUTED BY (pid);

INSERT INTO myschema.data (pid, position[1])
SELECT 
   h.state  
   ,round(avg(h.hinc),0) 
FROM
   housing h 
WHERE 
   (h.hinc > 0 )
GROUP BY
   h.state;


--SELECT * FROM madlib.data;

SET SEARCH_PATH to madlib,public,myschema;

SELECT madlib.kmeans('myschema.data', 3, 1, 'mytestrun', 'myschema');

SELECT * FROM myschema.kmeans_out_centroids_mytestrun;
--SELECT * FROM myschema.kmeans_out_points_mytestrun;
