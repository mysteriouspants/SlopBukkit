#include "vector.h"
#include <stdio.h>
#include <math.h>

VECTOR_PROTOTYPE(char, char);

void dec2bin(char_vector*, register int);

int main(int argc, char ** args) {
	
	int in;
	sscanf(args[1], "%d", &in);
	
	char_vector out = char_vector_create(4);
	
	dec2bin(&out, in);
	
	printf("%s\r\n", out.data);
	
	char_vector_free_stack(&out);
	
	return 0;
	
}

void dec2bin(char_vector* out, register int in) {
	register int old_in = in;
	in = (int)abs(in);
	
	char * tmp = (char*)malloc(sizeof(char)*2);
	register short int order = 0;
	
	while(pow(2.0,(double)order++)<=(double)in) { }
	
	--order;
	
	register short res;
	while(--order>=0) {
		res = in/(int)pow(2.0,(double)order);
		sprintf(tmp,"%d",res);
		char_vector_push_back(out,tmp[0]);
		if(res==1)
			in-=(int)pow(2.0, (double)order);
	}
	
	if(old_in<0) {
		register int i;
		for(i = 0; i < out->length; ++i) {
			switch(out->data[i]) {
				case '0':
					out->data[i] = '1';
					break;
				default:
					printf("strange, there shouldn't be something that isn't zero or one in here...\n");
				case '1':
					out->data[i] = '0';
					break;
			}
		}
		/* add one */
		register short int carrybit = 1;
		for(i = out->length - 1; i >= 0 && carrybit != 0; --i) {
			switch(out->data[i]) {
				default:
				case '0':
					carrybit = 0;
					out->data[i] = '1';
					break;
				case '1':
					carrybit = 1;
					out->data[i] = '0';
					break;
			}
		}
		/* if the most significant bit is 1, then drop it */
		if(out->data[0]=='1')
			char_vector_remove(out, 0);
		/* pad output */
		while((out->length+1)%4!=0) {
			char_vector_insert(out, 0, '1');
		}
		char_vector_insert(out, 0, '1');
	} else {
		while((out->length+1)%4!=0)
			char_vector_insert(out, 0, '0');
		char_vector_insert(out, 0, '0');
	}
		
	char_vector_push_back(out, '\0');
	
	free(tmp);
}
