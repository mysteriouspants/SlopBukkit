#include "vector.h"
#include <stdio.h>
#include <math.h>

VECTOR_PROTOTYPE(char, char);

void dec2hex(char_vector*, register int);

int main(int argc, char ** args) {
	
	int in;
	sscanf(args[1], "%d", &in);
	
	char_vector out = char_vector_create(4);
	
	dec2hex(&out, in);
	
	printf("0x%s\r\n", out.data);
	
	char_vector_free_stack(&out);
	
	return 0;
	
}

void dec2hex(char_vector* out, register int in) {
	char * tmp = (char*)malloc(sizeof(char)*2);
	register short int order = 0;
	
	while(pow(16.0,(double)order++)<=(double)in) { }
	
	--order;
	
	register short res;
	while(--order>=0) {
		res = in/(int)pow(16.0,(double)order);
		sprintf(tmp, "%X", res); /* I could make a switch statement to convert a
																a single digit to a hex digit, but that'd be
																a lot of typing and is besides the point of the
																assignment */
		char_vector_push_back(out, tmp[0]);
		in-=res*(int)pow(16.0,(double)order);															
	}
	
	free(tmp);
	
	char_vector_push_back(out, '\0');
}
