/*
	A PostgreSQL function for getting the hostname.
	Based on https://wiki.postgresql.org/wiki/hostname
    With thanks to seanc on Freenode for improvements.
*/

#include "postgres.h"
#include <unistd.h>
#include "fmgr.h"
#if PG_VERSION_NUM >= 160000
#include "varatt.h"
#endif

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1( hostname );

Datum hostname( PG_FUNCTION_ARGS );

Datum hostname( PG_FUNCTION_ARGS )
{
	const int max_len = sysconf(_SC_HOST_NAME_MAX);
	size_t length = 0;
	char *server_hostname = NULL;
	text *t = NULL;

    /* Set up the buffer for the host name. */
	server_hostname = palloc(max_len + 1);
	server_hostname[max_len] = '\0';

	if ( gethostname( server_hostname,  max_len ) != 0 )
	{
		/* Just return null if we can't determine the host name. */
		PG_RETURN_NULL();
	}

    /* Return text. */
	length = strlen( server_hostname );
	t = (text *) palloc(VARHDRSZ + length );
	SET_VARSIZE( t, VARHDRSZ + length );
	memcpy( VARDATA(t), server_hostname, length );

	PG_RETURN_TEXT_P( t );
}
