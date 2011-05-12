/*! Assignment #9, Linking to Assembler from C
 *! (C) 2010 Chris Miller, All Rights Reserved.
 *! Academic endorsement.
 */

#ifdef __cplusplus
	#pragma message("Using C++")
	#include <cmath>
	#include <iostream>
#else
	#pragma message("Using C")
	#include <math.h>
	#include <stdio.h>
	typedef unsigned short bool;
	#define true 0
	#define false 1
#endif

#if !(defined(_M_IX86) || defined(_M_IA64) || defined(_M_X64))
	#error Only works on x86
#endif

unsigned int rdtsc_lo, rdtsc_hi;
unsigned long long int r;
#ifdef __cplusplus
extern "C" {
#endif
	inline
	unsigned long long int rdtsc() {
		__asm {
			cpuid
			rdtsc
			mov rdtsc_lo,eax
			mov rdtsc_hi,edx
		}
		r = 0L;
		r = ((r | (unsigned long long int)rdtsc_hi) << 32) | (unsigned long long int)rdtsc_lo;
		return r;
	}
#ifdef __cplusplus
}
#endif

extern "C"
bool isPrime_asm(unsigned int num);

bool isPrime_cpp(unsigned int num);

int main(unsigned int args, char ** argv) {
	unsigned int in;
	unsigned long long int tsc_start_cpp,
						   tsc_start_asm,
						   tsc_end_cpp,
						   tsc_end_asm;
	bool res_asm, res_cpp;
	do {
#ifdef __cplusplus
		std::cout << "Please enter a number to test the primality of" << std::endl
				  << "or 0 to exit: ";
		std::cin >> in;
#else
		scanf("Please enter a number to test the primality of\r\nor 0 to exit: %ud", in); 
#endif

		if(in<1)
			break;
			
		tsc_start_cpp = rdtsc();
		res_cpp = isPrime_cpp(in);
		tsc_end_cpp = rdtsc();

		tsc_start_asm = rdtsc();
		res_asm = isPrime_asm(in);
		tsc_end_asm = rdtsc();
		
#ifdef __cplusplus
		std::cout << "C++ time:   " << (tsc_end_cpp - tsc_start_cpp) << std::endl;
		std::cout << "asm time:   " << (tsc_end_asm - tsc_start_asm) << std::endl;
		std::cout << "C++ result: " << res_cpp << std::endl;
		std::cout << "asm result: " << res_asm << std::endl;
#else
		printf("C time:     %uL\r\n", (tsc_end_cpp - tsc_start_cpp));
		printf("asm time:   %uL\r\n", (tsc_end_asm - tsc_start_asm));
		printf("C result:   %d\r\n", res_cpp);
		printf("asm result: %d\r\n", res_asm);
#endif

	} while (true);
	
	return 0;
}


bool isPrime_cpp(unsigned int num) {
	unsigned int sqrt_num = (unsigned int)sqrt(((double)num));
	for(register unsigned int n = 2; n <= sqrt_num; ++n)
		if(num%n==0)
			return false;
	return true;
}
