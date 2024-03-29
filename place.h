/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PLACE_H_RPCGEN
#define _PLACE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXLEN 255

typedef float latitude;

typedef float longitude;

typedef char *placename;

typedef struct airportNode *airportList;

struct searchedCity {
	char *city;
	char *state;
	latitude lat;
	longitude lon;
};
typedef struct searchedCity searchedCity;

struct airportNode {
	char *code;
	placename name;
	char *state;
	float distance;
	airportList next;
};
typedef struct airportNode airportNode;

struct output {
	searchedCity cityData;
	airportList list;
};
typedef struct output output;

struct readdir_ret {
	int err;
	union {
		output list;
	} readdir_ret_u;
};
typedef struct readdir_ret readdir_ret;

#define SEND_PLACE_PROG 0x33337777
#define SEND_PLACE_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define PLACE 1
extern  readdir_ret * place_1(placename *, CLIENT *);
extern  readdir_ret * place_1_svc(placename *, struct svc_req *);
extern int send_place_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PLACE 1
extern  readdir_ret * place_1();
extern  readdir_ret * place_1_svc();
extern int send_place_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_latitude (XDR *, latitude*);
extern  bool_t xdr_longitude (XDR *, longitude*);
extern  bool_t xdr_placename (XDR *, placename*);
extern  bool_t xdr_airportList (XDR *, airportList*);
extern  bool_t xdr_searchedCity (XDR *, searchedCity*);
extern  bool_t xdr_airportNode (XDR *, airportNode*);
extern  bool_t xdr_output (XDR *, output*);
extern  bool_t xdr_readdir_ret (XDR *, readdir_ret*);

#else /* K&R C */
extern bool_t xdr_latitude ();
extern bool_t xdr_longitude ();
extern bool_t xdr_placename ();
extern bool_t xdr_airportList ();
extern bool_t xdr_searchedCity ();
extern bool_t xdr_airportNode ();
extern bool_t xdr_output ();
extern bool_t xdr_readdir_ret ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PLACE_H_RPCGEN */
