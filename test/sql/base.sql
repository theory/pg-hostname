\set ECHO 0
\i sql/hostname.sql
SELECT COALESCE(length(hostname()), 0) >= 0;
