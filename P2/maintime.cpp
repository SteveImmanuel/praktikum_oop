#include <iostream>
#include "Time.hpp"
using namespace std;

int main(){
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	Time T1;
	T1.printTime();
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	Time T2(12,24,50);
	T2.printTime();
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	T1.addTime(T2);
	T1.printTime();
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	Time T3=T1;
	T3.addTime(T2);
	T3.printTime();
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	Time *T4=new Time(1,2,3);
	T4->printTime();
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	delete T4;
	cout<<"objek time:"<<Time::countTimeInstance()<<endl;
	return 0;
}
