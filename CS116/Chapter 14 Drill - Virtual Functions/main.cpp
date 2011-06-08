/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091030, Chapter 14 Drill
 */

#include <iostream>

#include "B1.h"
#include "D1.h"
#include "D2.h"
#include "D21.h"
#include "D22.h"

void f(fsdev::B2& arg);

int main (int argc, char * const argv[]) {
	// fsdev::B1 o1; //! commented out in step 6
	// o1.vf();
	// o1.f();
	/* ************ step 1
	 void B1::vf();
	 void B1::f();
	 */
	// fsdev::D1 o2; //! commented out in step 6
	// o2.vf();
	// o2.f();
	/* ************* step 2
	 void B1::vf();
	 void B1::f();
	 void D1::vf();
	 void B1::vf();
	 */
	// fsdev::B1& o3 = o2; //! commented out in step 6
	// o3.vf();
	// o3.f();
	/* ************** step 3
	 void B1::vf();
	 void B1::f();
	 void D1::vf();
	 void B1::f();
	 void D1::vf();
	 void B1::f();
	 */
	/* ************** step 4
	 void B1::vf();
	 void B1::f();
	 void D1::vf();
	 void D1::f();
	 void D1::vf();
	 void B1::f();
	 *! I expected for the
	 *! last line to be
	 *! void D1::f();
	 *! I think it wasn't
	 *! because the virtual
	 *! declaration gave
	 *! vf a higher precedence
	 *! to D1, but without
	 *! the virtual part, it
	 *! simply used the B1 vtable.
	 */ 
	/* ************** step 5
	 *! failed to compile because the
	 *! presence of pvf as a pure
	 *! virtual function made the whole
	 *! class abstract, preventing any
	 *! instantications of B1
	 */
	// fsdev::D2 o4; //! commented out in step 7
	// o4.vf();
	// o4.f();
	// o4.pvf();
	/* ************** step 6
	 void D1::vf();
	 void B1::f();
	 void D2::pvf();
	 */
	fsdev::D21 o5;
	fsdev::D22 o6;
	f(o5);
	f(o6);
	/* ************** step 7
	 void D21::pvf();
	     D21::sz == 
	 void D22::pvf();
	     D22::ii = 0
	 */
    return 0;
}

void f(fsdev::B2& arg) {
	arg.pvf();
}
