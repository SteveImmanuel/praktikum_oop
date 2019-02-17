#include <iostream>
#include "Pecahan.h"
using namespace std;


int main(){
	Pecahan P1(2,13,7);
	cout<<"P1= ";P1.print();
	Pecahan P2(3,6,7);
	cout<<"P2= ";P2.print();
	cout<<P1.value()<<"   "<<P2.value()<<endl;
	cout<<"P1=P2: "<<P1.isEQMe(P2)<<endl;
	Pecahan P3=Pecahan::add(P1,P2);
	cout<<"P3= ";P3.print();
	cout<<P3.value()<<endl;
	P1.accumulate(P2);
	P1.print();
	return 0;
}
