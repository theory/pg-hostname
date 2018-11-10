\set ECHO none
\i sql/hostname.sql
SELECT COALESCE(length(hostname()), 0) >= 0;
