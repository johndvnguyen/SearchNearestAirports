/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "p.h"
//extern CLIENT *clntairport;
void
send_coord_prog_1(char *host)
{
	airportList  *result_1;
	searchedCity  coord_1_arg;
	CLIENT *clntairport;
#ifndef	DEBUG
	
	printf("C_CLIENT.C\n");
	clntairport = clnt_create (host, SEND_COORD_PROG, SEND_COORD_VERS, "udp");
	if (clntairport == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}

	printf("After creation of clnt\n");
#endif	
	return;
	/* DEBUG */
	/*printf("c_client");
	result_1 = coord_1(&coord_1_arg, clntairport);
	if (result_1 == (airportList *) NULL) {
		clnt_perror (clntairport, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clntairport);
#endif	*/ /* DEBUG */
}


/*int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	send_coord_prog_1 (host);
exit (0);
}*/
