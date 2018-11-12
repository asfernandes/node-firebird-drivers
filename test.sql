create database 't.fdb';

select 'a' from rdb$database;

select _utf8 'a' from rdb$database;

select _utf8 'a' collate unicode from rdb$database;
