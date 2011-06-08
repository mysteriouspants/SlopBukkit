/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20090927, ch 9 drill #1
 */

namespace fsdev {
	
	class Year {
		static const int min = 1800;
		static const int max = 2200;
	public:
		class Invalid { };
		Year(int x) : y(x) { if (x<min || max<x) throw Invalid(); }
		int year() const { return y; }
	private:
		int y;
	};
	
	class Date {
	public:
		enum Month {
			jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
		};
	private:
		Year y;
		Month m;
		int d;
	public:
		Date(Year y, Month _m, int _d);
		void add_day(int _n);
		Month month() const { return m; };
		Year year() const { return y; };
		int day() const { return d; };
	};

	Date today(Year(2009),Date::sep,28);
	
}
