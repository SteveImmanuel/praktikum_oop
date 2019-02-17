#include <iostream>
#include "User.h"
#include "PremiumUser.h"
#include "ArtistUser.h"
using namespace std;

int main(){
	char* j;
	char* p;
	char* p2;
	char* p3;
	char* j2;
	j=new char[123];
	p=new char[123];
	p2=new char[123];
	p3=new char[123];
	j2=new char[123];
	strcpy(j,"aaaaa");
	strcpy(j2,"namekedua");
	strcpy(p,"Starship - Nicki Minaj");
	strcpy(p2,"To Be Human - Sia, Labrinth");
	strcpy(p3,"Primavera Portena");
	User a(j);
	a.addFavouriteMusic(p);
	a.addFavouriteMusic(p2);
	a.addFavouriteMusic(p3);
	a.viewMusicList();
	a.deleteFavouriteMusic(p);
	a.viewMusicList();
	a.deleteFavouriteMusic(p2);
	a.viewMusicList();
	a.deleteFavouriteMusic(p3);
	a.viewMusicList();
	return 0;
}
