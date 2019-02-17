// Nama/NIM		: Steve Andreas I/13517039
// Tanggal		: 14 Feb 2019
// Topik		: Inheritence

#include <iostream>
#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser(char* _name):User(_name){
        active=true;
        num_of_music_downloaded=0;
}
        
void PremiumUser::downloadMusic(char* _judul){
	if(!active){
                cout<<"Activate premium account to download music"<<endl;
        }else{
                num_of_music_downloaded++;
                cout<<"Music Downloaded: "<<_judul<<endl;
        }
}
void PremiumUser::inactivatePremium(){
	active=false;
}
void PremiumUser::activatePremium(){
	active=true;
}
        
int PremiumUser::getNumOfMusicDownloaded() const{
	return num_of_music_downloaded;
}

        // mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const{
	return active;
}
