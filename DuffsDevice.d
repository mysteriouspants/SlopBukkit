module duffsdevice;

import tango.io.Stdout;

/// tells if anything in the contents of arr1 are present in arr2
/// uses type implicit opCmp for comparison
bool hasAnyOf(T)(T[] arr1,T[] arr2){
	T[] small,large;
	if(arr1.length>arr2.length){
		large=arr1;small=arr2;
	}else{
		large=arr2;small=arr1;
	}
	int lp,rm=large.length%10;
	foreach(T t;small){
		lp=(large.length-1)/10;
		switch(rm){
		case 0: do{
					if(t==large[lp*10+9]) return true;
		case 9:		if(t==large[lp*10+8]) return true;
		case 8:		if(t==large[lp*10+7]) return true;
		case 7:		if(t==large[lp*10+6]) return true;
		case 6:		if(t==large[lp*10+5]) return true;
		case 5:		if(t==large[lp*10+4]) return true;
		case 4:		if(t==large[lp*10+3]) return true;
		case 3:		if(t==large[lp*10+2]) return true;
		case 2:		if(t==large[lp*10+1]) return true;
		case 1: 	if(t==large[lp*10  ]) return true;
				}while(0<--lp);
				break;
		}
	}
	return false;
}

/// same as above, but uses function delegate to compare junk
/// outside the constrains of the default opCmp
/*bool hasAnyOf(T)(T[] arr1,T[] arr2,int delegate(T a,T b) dg){
	T[] small,large;
	if(arr1.length>arr2.length){
		large=arr1;small=arr2;
	}else{
		large=arr2;small=arr1;
	}
	int lp,rm=large.length%10;
	foreach(T t;small){
		lp=large.length/10;
		switch(rm){
		case 0: do{
					if(dg(t,large[lp*10+9])) return true;
		case 9:		if(dg(t,large[lp*10+8])) return true;
		case 8:		if(dg(t,large[lp*10+7])) return true;
		case 7:		if(dg(t,large[lp*10+6])) return true;
		case 6:		if(dg(t,large[lp*10+5])) return true;
		case 5:		if(dg(t,large[lp*10+4])) return true;
		case 4:		if(dg(t,large[lp*10+3])) return true;
		case 3:		if(dg(t,large[lp*10+2])) return true;
		case 2:		if(dg(t,large[lp*10+1])) return true;
		case 1:		if(dg(t,large[lp*10  ])) return true;
				}while(0<--lp);
		default: assert(true==false);
		}
	}
}*/

void main(char[][] argc) {
	if(argc.length>2) {
		Stdout("argc[0]=={}",argc[1]).newline;
		Stdout("argc[1]=={}",argc[2]).newline;
		Stdout("hasAnyOf!(char[])(argc[0],argc[1])=={}",
			hasAnyOf!(char)(argc[1],argc[2])).newline;
	}
}

