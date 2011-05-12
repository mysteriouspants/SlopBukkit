#include "vector.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

VECTOR_PROTOTYPE(char, char);

void hex2bin(char_vector*, char_vector*);

int main(int argc, char ** args) {
	
	char_vector in = char_vector_create(4);
	char_vector_insert_range(&in, 0, args[1], args[1]+strlen(args[1]));
	
	char_vector out = char_vector_create(0);
	
	hex2bin(&out, &in);
	
	printf("%s\r\n", out.data);
	
	char_vector_free_stack(&in);
	char_vector_free_stack(&out);
	
	return 0;
	
}

void hex2bin(char_vector* out, char_vector* in) {
	/* drop the leading 0x if it exists */
	if(in->data[0]=='0'&&in->data[1]=='x')
		char_vector_remove_range(in, 0, 2);
	
	/* put null character at the end of the string to prevent stdc routines
		 from f'ing up the output																						  */
	
	in->data[in->length] = '\0'; /* can do because length is 1-past the end
	 																of the vector, and because of remove calls
																	the vector is guaranteed to have excess */
	
	/* each hex digit is one four-digit binary number */
	
	register short int i;
	register char tmp;
	char * sztmp = (char*)calloc(5, sizeof(char));
	sztmp[4]='\0';
	for(i=0;i<in->length;++i) {
		tmp=in->data[i];
		switch(tmp) {
			case '0': /* 0000 */
				sztmp[0]='0';
				sztmp[1]='0';
				sztmp[2]='0';
				sztmp[3]='0';
				break;
			case '1': /* 0001 */
				sztmp[0]='0';
				sztmp[1]='0';
				sztmp[2]='0';
				sztmp[3]='1';
				break;
			case '2': /* 0010 */
				sztmp[0]='0';
				sztmp[1]='0';
				sztmp[2]='1';
				sztmp[3]='0';
				break;
			case '3': /* 0011 */
				sztmp[0]='0';
				sztmp[1]='0';
				sztmp[2]='1';
				sztmp[3]='1';
				break;
			case '4': /* 0100 */
				sztmp[0]='0';
				sztmp[1]='1';
				sztmp[2]='0';
				sztmp[3]='0';
				break;
			case '5': /* 0101 */
				sztmp[0]='0';
				sztmp[1]='1';
				sztmp[2]='0';
				sztmp[3]='1';
				break;
			case '6': /* 0110 */
				sztmp[0]='0';
				sztmp[1]='1';
				sztmp[2]='1';
				sztmp[3]='0';
				break;
			case '7': /* 0111 */
				sztmp[0]='0';
				sztmp[1]='1';
				sztmp[2]='1';
				sztmp[3]='1';
				break;
			case '8': /* 1000 */
				sztmp[0]='1';
				sztmp[1]='0';
				sztmp[2]='0';
				sztmp[3]='0';
				break;
			case '9': /* 1001 */
				sztmp[0]='1';
				sztmp[1]='0';
				sztmp[2]='0';
				sztmp[3]='1';
				break;
			case 'A': /* 1010 */
			case 'a':
				sztmp[0]='1';
				sztmp[1]='0';
				sztmp[2]='1';
				sztmp[3]='0';
				break;
			case 'B': /* 1011 */
			case 'b':
				sztmp[0]='1';
				sztmp[1]='0';
				sztmp[2]='1';
				sztmp[3]='1';
				break;
			case 'C': /* 1100 */
			case 'c':
				sztmp[0]='1';
				sztmp[1]='1';
				sztmp[2]='0';
				sztmp[3]='0';
				break;
			case 'D': /* 1101 */
			case 'd':
				sztmp[0]='1';
				sztmp[1]='1';
				sztmp[2]='0';
				sztmp[3]='1';
				break;
			case 'E': /* 1110 */
			case 'e':
				sztmp[0]='1';
				sztmp[1]='1';
				sztmp[2]='1';
				sztmp[3]='0';
				break;
			case 'F': /* 1111 */
			case 'f':
				sztmp[0]='1';
				sztmp[1]='1';
				sztmp[2]='1';
				sztmp[3]='1';
				break;
			default:
				printf("Illegal character in stream, now exiting\n");
				exit(0xDEAD); /* lol */
				break;
		}
		char_vector_insert_range(out, out->length, sztmp, sztmp+4);
	}
	free(sztmp);
	out->data[out->length]='\0';
}
