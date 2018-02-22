/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "p.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

char* airport_host;
extern CLIENT *clntairport;
static void
send_place_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		placeName place_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case PLACE:
		_xdr_argument = (xdrproc_t) xdr_placeName;
		_xdr_result = (xdrproc_t) xdr_readdir_ret;
		local = (char *(*)(char *, struct svc_req *)) place_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	//airport_host = argv[1];
	host = argv[1];
	//send_coord_prog_1 (host);
	printf("svc\n");	
	
	//CLIENT *clntairport;

	printf("Before creation of clnt\n");
	clntairport = clnt_create (host, SEND_COORD_PROG, SEND_COORD_VERS, "udp");
	if (clntairport== NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
	//clntairport = clnt;

	printf("After creation of clnt\n");
	register SVCXPRT *transp;

	pmap_unset (SEND_PLACE_PROG, SEND_PLACE_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, SEND_PLACE_PROG, SEND_PLACE_VERS, send_place_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (SEND_PLACE_PROG, SEND_PLACE_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, SEND_PLACE_PROG, SEND_PLACE_VERS, send_place_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (SEND_PLACE_PROG, SEND_PLACE_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
