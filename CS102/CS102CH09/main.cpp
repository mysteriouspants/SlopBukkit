/*
 Name:                   Chris Miller
 Class:                  CS102 Wed 6:30 – 9:40	
 Student ID:             0345979
 Assignment #:           9
 Date Due:               4 December 2008
 Date Submitted:         7 December 2008
 Computer/Compiler Used: Darwin (Apple Mac OS X "Leopard") w/Xcode 3,GCC 4.2.0, x86
 File Name:              main.cpp
 */
#include <iostream>
#include <cstring>
#include <vector>

int indexOf(char *src, char *itm);
int rIndexOf(char *src, char *itm);
std::vector<char*>* split(char *src, char *itm);
char* replace(char *src, char *regex, char *sub);
char* titleCase(char *src);
bool verifyPass(char *src);

int main (int argc, char * const argv[]) {
    // unit tests
/*	std::cout << "indexOf(\"farbus\",\"a\") = " << indexOf("farbus","a") << std::endl;
	std::cout << "indexOf(\"farbus\",\"ar\") = " << indexOf("farbus","ar") << std::endl;
	std::cout << "indexOf(\"farbus\",\"ab\") = " << indexOf("farbus","ab") << std::endl;
	std::cout << "indexOf(\"farbus\",\"bus\") = " << indexOf("farbus","bus") << std::endl;
	std::cout << "indexOf(\"farbus\",\"hello\") = " << indexOf("farbus","hello") << std::endl;
	std::cout << "indexOf(\"farbus\",\"pirates\") = " << indexOf("farbus","pirates") << std::endl;
	std::cout << "indexOf(\"farbus\",\"z\") = " << indexOf("farbus","z") << std::endl;
	
	std::cout << "indexOf(\"XxDominatorxX\",\"xX\") = " << indexOf("XxDominatorxX","xX") << std::endl;
	
	std::cout << "rIndexOf(\"Hello\",\"l\") = " << rIndexOf("Hello", "l") << std::endl;
	std::cout << "rIndexOf(\"Hello\",\"ll\") = " << rIndexOf("Hello", "ll") << std::endl;
	std::cout << "rIndexOf(\"Hello\",\"o\") = " << rIndexOf("Hello", "o") << std::endl;
	std::cout << "rIndexOf(\"Hello\",\"ly\") = " << rIndexOf("Hello", "ly") << std::endl;
	std::cout << "rIndexOf(\"Hello\",\"H\") = " << rIndexOf("Hello", "H") << std::endl;*/
	
	
	char input[180];
	do {
		std::cout << "Enter your name in First Last format" << std::endl;
		std::cin.getline(input, 180);
		if(indexOf(input," ")>-1)
			break;
	} while ( true == true ) ;
	std::vector<char*>* split_string = split(input," ");
	
	std::cout << "Hello " << (*split_string)[1] << ", " << (*split_string)[0] << "." << std::endl;
	
	/* // unit tests
	std::cout << "split(\" Oh Darn It  Doesn't Like   Working\",\" \") = " << std::endl;
	std::vector<char*> *chvec = split(" Oh Darn It  Doesn't Like   Working", " ");
	for(std::vector<char*>::iterator iter=(*chvec).begin();iter!=(*chvec).end();++iter){
		std::cout << "    " << *iter << std::endl;
	}*/
	
	/*
	 B. - Write a function that changes all the occurrences
	 of string1 to string2 in string3.
	 Input(1)"is", (2) "is not" (3)"This is it."
	 Output "This is not it."
	 */

	// unit tests
	std::cout << "replace(\"farbus\",\"a\",\"ath\") = " << replace("farbus","a","ath") << std::endl;
	std::cout << "replace(\"XxDominatorxX\",\"xX\",\"Xx\") = " << replace("XxDominatorxX","xX","Xx") << std::endl;
	std::cout << "replace(\"farbus\",\"f\",\"d\") = " << replace("farbus","f","d") << std::endl;
	std::cout << "replace(\"This is it\",\"is\",\"is not\") = " << replace("This is it","is","is not") << std::endl;
	
	/*
	 C. - Write a function that changes the Case of a string to Title Case.
	 Input "This is it"
	 Output "This Is It"*/
	
	std::cout << "titleCase(\"This is it\") = " << titleCase("This is it") << std::endl;
	std::cout << "titleCase(\"this is It\") = " << titleCase("this is It") << std::endl;
	std::cout << "titleCase(\" this is it\") = " << titleCase(" this is it") << std::endl;
	std::cout << "titleCase(\"this  is it\") = " << titleCase("this  is it") << std::endl;
	std::cout << "titleCase(\"this i s i t\") = " << titleCase("this i s i t") << std::endl;
	std::cout << "titleCase(\"This Is It\") = " << titleCase("This Is It") << std::endl;
	
	 /*- Write a function that verifies a password has at least
	 5 characters and starts with an Alpha character contains
	 a capital letter and no punctuation
	 */
	
	std::cout << std::endl;
	
	std::cout << "Password verification function:" << std::endl;
	
	std::cout << "    verifyPass(\"bagfitchde\") = " << ((verifyPass("bagfitchde")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"farbus\") = " << ((verifyPass("farbus")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"baGfitchde\") = " << ((verifyPass("baGfitchde")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"farBus\") = " << ((verifyPass("farBus")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"9livEs\") = " << ((verifyPass("9livEs")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"n9nelives\") = " << ((verifyPass("n9nelives")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"n9nelIves\") = " << ((verifyPass("n9nelIves")==true)?"true":"false") << std::endl;
	std::cout << "    verifyPass(\"foO2\") = " << ((verifyPass("foO2")==true)?"true":"false") << std::endl;
	
	char throwawaychar;
	std::cout << "Press the any key to continue..." << std::endl;
	std::cin.get(throwawaychar);	
    return 0;
}

bool verifyPass(char *src) {
	if(strlen(src)<5)
		return false;
	if((*src<'a'||*src>'z')&&(*src<'A'||*src>'Z'))
		return false;
	bool hasCap=false;
	for(int i=0;i<strlen(src);++i) {
		if(*(src+i)>'A'&&*(src+i)<'Z')
			hasCap=true;
		if((*(src+i)<'a'||*(src+i)>'z')&&(*(src+i)<'A'||*(src+i)>'Z')&&(*(src+i)<'0'||*(src+i)>'9'))
			return false;
	}
	return hasCap;
}

char* titleCase(char *src) {
	char* toReturn = (char*)malloc((strlen(src)+1)*sizeof(char));
	strcpy(toReturn, src);
	for(int i=0;i<strlen(src);++i)
		switch(i) {
			default:	if(*(src+i-1)==' ') {
			case 0:			if(*(src+i)>'a'&&*(src+i)<'z')
								*(toReturn+i)+='A'-'a';
						}
				break;
		}
	return toReturn;
}

/**
 * Replaces all instances of regex with sub in src.
 */
char* replace(char *src, char *regex, char *sub){
	char *end_result = "", *cptr;
	// load the front of result with sub if the first instance of regex is zero
	if(indexOf(src,regex)==0) {
		end_result = (char*)malloc(strlen(sub)*sizeof(char));
		strcpy(end_result,sub);
	}
	// split up src
	std::vector<char*> *spltchar = split(src,regex);
	// start loading on the pieces of spltchar with sub in between
	for(std::vector<char*>::iterator iter=(*spltchar).begin();iter!=(*spltchar).end();++iter){
		cptr = (char*)malloc(strlen(end_result)*sizeof(char));
		strcpy(cptr, end_result);
		end_result = (char*)malloc(strlen(cptr)*sizeof(char)+strlen(*iter)*sizeof(char)); // resize for the old value
		strncpy(end_result, cptr, strlen(cptr)); // copy old value back									 plus the contents of *iter
		strncpy(end_result+strlen(cptr), *iter, strlen(*iter)); // copy the value of *iter
		// if this is the end of the line, and there isn't a trailing index of regex, don't add sub
		if(iter+1!=(*spltchar).end()||rIndexOf(src, regex)==strlen(src)-(strlen(regex)-1)){
			// append sub to end result
			cptr = (char*)malloc(strlen(end_result)*sizeof(char));
			strcpy(cptr, end_result);
			end_result=(char*)malloc(strlen(cptr)*sizeof(char)+strlen(sub)*sizeof(char));
			strncpy(end_result, cptr, strlen(cptr));
			strncpy(end_result+strlen(cptr), sub, strlen(sub));
		}
	}
	
	return end_result;
}

/**
 * Splits a string.
 */
std::vector<char*>* split(char* src, char *itm) {
	std::vector<char*> *toReturn = new std::vector<char*>();
	
	if(indexOf(src,itm)<0) {
		(*toReturn).insert((*toReturn).begin(),src);
		return toReturn;
	}
	
	char *remaining = (char*)malloc(strlen(src)*sizeof(char)), *aptr, *cptr;
	strcpy(remaining,src);
	for(int i=indexOf(remaining,itm);i>=0;i=indexOf(remaining,itm)){
		// copy remaining over so we don't loose it
		cptr=(char*)malloc(strlen(remaining)*sizeof(char));
		strcpy(cptr,remaining);
		
		if(i==0) {
			remaining = (char*)malloc(strlen(cptr)*sizeof(char)-strlen(itm)*sizeof(char));
			strncpy(remaining,cptr+strlen(itm),strlen(cptr)-strlen(itm));
			// go around again
			continue;
		}
		
		aptr = (char*)malloc(i*sizeof(char));
		strncpy(aptr,cptr,i);
		(*toReturn).insert((*toReturn).end(),aptr); // store the first chunk in the vector
		// make remaining the second chunk
		remaining = (char*)malloc(strlen(cptr)*sizeof(char)-(i*sizeof(char)+strlen(itm)*sizeof(char)));
		strncpy(remaining,cptr+i+strlen(itm),strlen(cptr)-(i+strlen(itm)));
		
	}
	
	(*toReturn).insert((*toReturn).end(),remaining);
	
	return toReturn;
}

int rIndexOf(char* src, char *itm){
	if ( strlen(itm) > strlen(src) )
		return -1;
	for (
		 int i = strlen(src) - strlen(itm) ;
		 i >= 0 ;
		 --i
		 ) {
		if ( *(src + i) == *itm ) {
			if(strlen(itm)==1)
				return i;
			for (
				 int j = 1 ;
				 j < strlen(itm) ;
				 ++j
				 ) {
				if ( *(src+i+j) != *(itm+j) )
					break;
				if ( j == strlen(itm)-1 )
					return i;
			}
		}
	}
	return -1;
}

/**
 * Finds the first instance of <b>itm</b> in <b>src</b>,
 * or <b>-1</b> if <b>itm</b> is not present in <b>src</b>.
 */
int indexOf(char* src, char *itm) {
	if ( strlen(itm) > strlen(src) )
		return -1;
	for (
	     int i = 0 ;
	     i <= strlen(src) - strlen(itm) ;
	     ++i
		 ) {
		if ( src[i] == itm[0] ) {
			if(strlen(itm)==1)
				return i;
			for (
			     int j = 1 ;
			     j < strlen(itm) ;
			     ++j
				 ) {
				if ( *(src+i+j) != *(itm+j) )
					break;
				if ( j == strlen(itm)-1 )
					return i;
			}
		}
	}
	return -1;
}

/*
 [Session started at 2008-12-07 02:06:53 -0800.]
 Enter your name in First Last format
 Chris Miller
 Hello Miller, Chris.
 replace("farbus","a","ath") = fathrbus
 replace("XxDominatorxX","xX","Xx") = XxDominatorXx
 replace("farbus","f","d") = darbus
 replace("This is it","is","is not") = This not is not it
 titleCase("This is it") = This Is It
 titleCase("this is It") = This Is It
 titleCase(" this is it") =  This Is It
 titleCase("this  is it") = This  Is It
 titleCase("this i s i t") = This I S I T
 titleCase("This Is It") = This Is It
 
 Password verification function:
 verifyPass("bagfitchde") = false
 verifyPass("farbus") = false
 verifyPass("baGfitchde") = true
 verifyPass("farBus") = true
 verifyPass("9livEs") = false
 verifyPass("n9nelives") = false
 verifyPass("n9nelIves") = true
 verifyPass("foO2") = false
 Press the any key to continue...
 
 
 The Debugger has exited with status 0.
*/
