#include <iostream>
#include "ArtistUser.h"

using namespace std;

int main(){
	char* j;
	char* p;
	char* p2;
	j=new char[123];
	p=new char[123];
	p2=new char[123];
	strcpy(j,"aaaaa");
	strcpy(p,"1. Starship - Nicki Minaj");
	strcpy(p2,"2. To Be Human - Sia, Labrinth");
    ArtistUser A(j);
    cout<<"no artist: "<<ArtistUser::getNumOfArtist()<<endl;
    A.uploadMusic(p);
    A.uploadMusic(p2);
    cout<<A.getNumOfMusicUploaded()<<endl;
    A.viewUploadedMusicList();
    A.deleteUploadedMusic(p);
    A.deleteUploadedMusic(p2);
    cout<<A.getNumOfMusicUploaded()<<endl;
    A.viewUploadedMusicList();
    delete [] p;
    delete [] j;
    delete [] p2;
	return 0;
}