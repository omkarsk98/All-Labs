create table  housing_backup 
 as select * from housing Distributed by (serialno,state); 