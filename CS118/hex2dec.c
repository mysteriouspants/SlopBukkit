#include "vector.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

VECTOR_PROTOTYPE(char, char);

void hex2dec(unsigned int*, char_vector*);

int main(int argc, char ** args) {
	
	char_vector in = char_vector_create(4);
	char_vector_insert_range(&in, 0, args[1], args[1]+strlen(args[1]));
	
	unsigned int out;
	
	hex2dec(&out, &in);
	
	printf("%d\r\n", out);
	
	char_vector_free_stack(&in);
	
	return 0;
	
}

void hex2dec(unsigned int * out, char_vector* in) {
	/* drop the leading 0x if it exists */
	if(in->data[0]=='0'&&in->data[1]=='x')
		char_vector_remove_range(in, 0, 2);
	
	/* put null character at the end of the string to prevent stdc routines
		 from f'ing up the output																						  */
	
	in->data[in->length] = '\0'; /* can do because length is 1-past the end
	 																of the vector, and because of remove calls
																	the vector is guaranteed to have excess */
		
	*out = 0;

	register short int i, order;
	unsigned int tmp;
	char * sztmp = (char*)calloc(2, sizeof(char));
	sztmp[1]='\0';
	for(i=in->length-1,order=0; i>=0; --i,++order) {
		sztmp[0]=in->data[i];
		sscanf(sztmp,"%x",&tmp); /* same story, I could write a custom switch
																statement or something, but that's a lot of
																typing and besides the point */
		*out+=tmp*(unsigned int)pow(16.0, order);
	}
}
