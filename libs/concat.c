#include "include/concat.h"

char* concat(int count, ...) {
	va_list args;
	va_start(args,count);
	size_t total_length = 1;	
	for (int i = 0; i < count; i++)
		total_length+=strlen(va_arg(args,char*));
	va_end(args);
	//Now we have total length. Create a malloc.
	va_start(args,count);
	char *ret = (char *)malloc(total_length*sizeof(char));
	char *val = ret;
	for (int i = 0; i < count; i++) {
		char *arg = va_arg(args,char*);		
		strcpy(val,arg);
		val+=strlen(arg);
	}
	*val=0; //Terminate null
	va_end(args);
	return ret;
}
