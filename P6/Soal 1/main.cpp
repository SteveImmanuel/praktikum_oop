#include <iostream>
//#include "Warna.h"
#include "array_warna.h"
using namespace std;

int main(){
	Warna<float> test(-1,-2,-3);
	Warna<float> test2(2,3,4);
	cout<<test.getRed()<<" "<<test.getGreen()<<" "<<test.getBlue()<<endl;
	cout<<test2.countDifference(test)<<endl;
	test=test+test2;
	cout<<test.getRed()<<" "<<test.getGreen()<<" "<<test.getBlue()<<endl;
	ArrayWarna<float> AW;
	AW.addElement(5,test);
	AW.addElement(1,test2);
	cout<<AW.getWarna(0).countDifference(AW.getWarna(1))<<endl;
	return 0;
}
