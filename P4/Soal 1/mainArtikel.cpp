#include <iostream>
#include "Artikel.hpp"

using namespace std;

int main(){
	char* j;
	char* p;
	j=new char[DEFSIZE];
	p=new char[DEFSIZE];
	strcpy(j,"A Tour of C++ (second edition)");
	strcpy(p,"Bjarne Stroustrup");
	Artikel test(j,p,2018);
	test.print();
	return 0;
}
