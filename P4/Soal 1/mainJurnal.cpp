#include <iostream>
#include "Jurnal.hpp"

using namespace std;

int main(){

	char* j;
	char* p;
	char* p2;
	char* j2;
	j=new char[DEFSIZE];
	p=new char[DEFSIZE];
	j2=new char[DEFSIZE];
	p2=new char[DEFSIZE];
	strcpy(j,"A Tour of C++ (second edition)");
	strcpy(p,"Bjarne Stroustrup");
	strcpy(p2,"asdasdasdasd");
	strcpy(j2,"babbabababab");
	Artikel test(j2,p2,2018);
	Artikel test2(j2,p2,1999);
	Artikel test3(j,p,2018);
	Jurnal J;
	J.add(test);
	J.add(test2);
	cout<<J.getSize()<<endl;
	J.insert(1,test3);
	J.print();
	return 0;
}
