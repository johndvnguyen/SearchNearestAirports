/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "send_coord.h"

char **
coord_1_svc(float *argp, struct svc_req *rqstp)
{

	static char* result;
	printf("the number is %f \n", *argp);
	char sentence[50];
	sprintf(sentence, "the number is %f", *argp);
	printf("the sentence is %s \n", sentence);
	result = sentence;
	return &result;
}