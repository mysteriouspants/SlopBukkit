/*! Chris Miller (cmiller@fsdev.net), CS116
 *! Copyright (C) 2009 FSDEV.  Aw richts pitten by.
 *! Academic endorsement.  This code is not licensed for commercial use.
 *! 20091006, Chapter 10 Drill
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Point {
private:
    double _x, _y;
public:
	Point() {
		
	}
    Point(double x, double y)
	: _x(x), _y(y) {
        
    }
    double x() const { return _x; };
    double y() const { return _y; };
    void setX(double x) { _x = x; };
    void setY(double y) { _y = y; };
};

istream& operator >> (istream& is, Point& p) {
    double x, y;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

ostream& operator << (ostream& os, Point& p) {
    os << p.x() << " " << p.y();
    return os;
}

int main (int argc, char * const argv[]) {
	cout << "Enter seven x-y values" << endl;
    cout << "for example:" << endl;
    cout << "1: 12 11" << endl;
    vector<Point> originalPoints();
    Point p(0,0);
    for(size_t i=0; i<7; ++i) {
        cout << i+1 << ": ";
        cin >> p;
        originalPoints.push_back(p);
    }
	for(size_t i=0; i< originalPoints.size(); ++i) {
        Point p = originalPoints[i];
		cout << i << ": " << p << endl;
    }
	ofstream ost("mydata.txt");
    if(!ost) {
        cerr << "Error opening output file.  Check permissions and space." << endl;
        return -1;
    }
	
    for(size_t i=0; i < originalPoints.size(); ++i)
        ost << originalPoints[i] << " ";
	
	ost.close();
	
    ifstream ist("mydata.txt");
    if(!ist) {
        cerr << "Error reading file.  Check permissions and space" << endl;
        return -2;
    }
    
    vector<Point> processedPoints();
    while(ist) {
        Point p;
        ist >> p;
        processedPoints.push_back(p);
    }
	
	if(processedPoints.size() != originalPoints.size()) {
        cout << "Something is wrong!  The two vectors differ in length." << endl;
    }
    
    for(size_t i=0; i < originalPoints.size() && i < processedPoints.size(); ++i) {
        cout << i << ": Original: " << originalPoints[i] << " Serialized: " << processedPoints[i] << endl;
        if(processedPoints[i].x() != originalPoints[i].x() ||
           processedPoints[i].y() != originalPoints[i].y()) {
            cout << "Something is wrong: points at " << i << " do not match!" << endl;
        }
    }
	
	return 0;
}
