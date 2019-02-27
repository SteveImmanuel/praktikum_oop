//Nama/NIM	: Steve Andreas Immanuel/13517039
//Tanggal	: 21-Feb-2019
//Topik		: Polimorfisme, Template

#include <iostream>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "ColoredTriangle.hpp"
using namespace std;

int main(){
	Triangle T2(1,2,3);
	T2.print();
	ColoredTriangle T(3,4,5,1,0,1);
	cout<<T.perimeter()<<" "<<T.area()<<endl;
	T.print();
	Circle C(7);
	cout<<C.perimeter()<<" "<<C.area()<<endl;
	C.print();
	cout<<Triangle::isValid(2,1,1.1)<<endl;
	return 0;
}
