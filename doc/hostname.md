hostname 1.0.0
==============

Synopsis
--------

```sql
CREATE EXTENSION hostname;

SELECT hostname();
      hostname
--------------------
 myhost.example.com
```

Description
-----------

This library contains a single PostgreSQL function, `hostname()`, which
returns the PostgreSQL server host name. The function uses `gethostname()`
to get the host name. If it fails, `NULL` will be returned. If you need it
not to return `NULL`, use `COALESCE()`:

```sql
SELECT COALESCE(NULL, '[unknown]');
 coalesce
-----------
 [unknown]
```

Author
------

[David E. Wheeler](http://www.justatheory.com/), based on code posted to the
[PostgreSQL Wiki by "Brick"](https://wiki.postgresql.org/wiki/Pg_gethostname),
and with many thanks to Sean Chittenden for C implementation advice and
constructive criticism.

Copyright and License
---------------------

Copyright (c) 2013-2025 David E. Wheeler.

This module is free software; you can redistribute it and/or modify it under
the [PostgreSQL License](http://www.opensource.org/licenses/postgresql).

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose, without fee, and without a written agreement is
hereby granted, provided that the above copyright notice and this paragraph
and the following two paragraphs appear in all copies.

In no event shall David E. Wheeler be liable to any party for direct,
indirect, special, incidental, or consequential damages, including lost
profits, arising out of the use of this software and its documentation, even
if David E. Wheeler has been advised of the possibility of such damage.

David E. Wheeler specifically disclaim any warranties, including, but not
limited to, the implied warranties of merchantability and fitness for a
particular purpose. The software provided hereunder is on an "as is" basis,
and David E. Wheeler have no obligations to provide maintenance, support,
updates, enhancements, or modifications.
