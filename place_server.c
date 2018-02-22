/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "place.h"
#include <errno.h>
#include "coord_client.h"

extern char * airport_host;

readdir_ret *
place_1_svc(placename *argp, struct svc_req *rqstp)
{
	static readdir_ret  result;
	result.err = 0;
	result.readdir_ret_u.list.cityData.city = "Denver";
	result.readdir_ret_u.list.cityData.state = "CO";
	result.readdir_ret_u.list.cityData.lat = 40.1;
	result.readdir_ret_u.list.cityData.lon = 32.4;
	/*
	 * insert server code here
	 */
	//make call to airport client
	printf("using host: %s \n",airport_host);
	send_coord_prog_1 (airport_host);
	printf("host sent: %s \n",airport_host);
	
	return &result;
}
