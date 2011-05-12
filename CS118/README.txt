© 2010 Chris Miller
/------------------------------------------------------------------------------\
|                                   DEC2BIN																		 |
\------------------------------------------------------------------------------/

Works on both GNU GCC (C97) and MSVC++, as well as CLang/LLVM.

Use clang dec2bin.c -o dec2bin, or cl /Tp dec2bin.c on MSVC++.

Run it like so:
	Z:\CS118\dec2bin.exe 123
	1111011

or on Unix:
	cmiller@~: dec2bin 123
	1111011

/------------------------------------------------------------------------------\
|                                   DEC2HEX																		 |
\------------------------------------------------------------------------------/

Works on both GNU GCC (C97) and MSVC++, as well as CLang/LLVM.

Use clang dec2hex.c -o dec2hex or cl /Tp dec2hex.c on MSVC++.

Run it like so:
	Z:\CS118\dec2hex.exe 123
	0x7B

or on Unix:
	cmiller@~: dec2hex 123
	0x7B