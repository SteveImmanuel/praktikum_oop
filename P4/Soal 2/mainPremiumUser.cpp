#include <iostream>
#include "PremiumUser.h"

using namespace std;

int main(){
	char* j;
	char* p;
	char* p2;
	j=new char[123];
	p=new char[123];
	p2=new char[123];
	strcpy(j,"aaaaa");
	strcpy(p,"Starship - Nicki Minaj");
	strcpy(p2,"To Be Human - Sia, Labrinth");
    PremiumUser P(j);
    P.downloadMusic(p);
    P.inactivatePremium();
    P.downloadMusic(p2);
    P.activatePremium();
    P.downloadMusic(p2);
    cout<<P.getNumOfMusicDownloaded()<<endl;
    delete [] p;
    delete [] j;
    delete [] p2;
	return 0;
}