#include <iostream>
#include "Time.h"
using namespace std;

int Time::n_time=0;

Time::Time(){
	hour=0;
	minute=0;
	second=0;
	n_time++;
}

Time::Time(int x,int y,int z){
	hour=x;
	minute=y;
	second=z;
	n_time++;
}

Time::Time(const Time& T){
	hour=T.hour;
	minute=T.minute;
	second=T.second;
	n_time++;
}

Time::~Time(){
	n_time--;
}

void Time::setHour(int x){
	hour=x;
}
void Time::setMinute(int y){
	minute=y;
}
void Time::setSecond(int z){
	second=z;
}
int Time::getHour() const{
	return hour;
}
int Time::getMinute() const{
	return minute;
}
int Time::getSecond() const{
	return second;
}

int Time::countTimeInstance(){
	return n_time;
}
int Time::convertToSecond() const{
	return 3600*hour+60*minute+second;
}
void Time::printTime(){
	printf("%.2d:%.2d:%.2d\n",hour,minute,second);
}
void Time::addTime(const Time& T){
	int Totaltime;
	Totaltime=3600*hour+60*minute+second+3600*(T.hour)+60*(T.minute)+(T.second);
	hour=(Totaltime/3600)%24;
	minute=(Totaltime%3600)/60;
	second=(Totaltime%3600)%60;
}
void Time::decreaseTime(const Time& T){
	int time1,time2,Totaltime;
	time1=3600*hour+60*minute+second;
	time2=3600*(T.hour)+60*(T.minute)+(T.second);
	if(time2<=time1){
		Totaltime=time1-time2;
		hour=Totaltime/3600;
		minute=(Totaltime%3600)/60;
		second=(Totaltime%3600)%60;
	}
}

bool Time::earlierThan(const Time& T){
	int time1,time2;
	time1=this->convertToSecond();
	time2=T.convertToSecond();
	return time1<time2;
}

bool Time::laterThan(const Time& T){
	int time1,time2;
	time1=this->convertToSecond();
	time2=T.convertToSecond();
	return time1>time2;
}















