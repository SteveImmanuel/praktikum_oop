// Nama/NIM		: Steve Andreas I/13517039
// Tanggal		: 14 Feb 2019
// Topik		: Inheritence

#include <iostream>
#include "User.h"

using namespace std;

int User::n_user=0;

User::User(char * _name){
	name=new char[strlen(_name)];
	strcpy(name,_name);
	num_of_favourite_music=0;
	music_list=new char*[256];
	n_user++;
}

User::User(const User& U){
	name=new char[strlen(U.name)];
	strcpy(name,U.name);
	num_of_favourite_music=U.num_of_favourite_music;
	music_list=new char*[U.num_of_favourite_music];
	for(int i=0;i<num_of_favourite_music;i++){
		music_list[i]=new char[strlen(U.music_list[i])];
		strcpy(music_list[i],U.music_list[i]);
	}
	n_user++;
}

User::~User(){
	for(int i=0;i<num_of_favourite_music;i++){
		delete [] music_list[i];
	}
	delete [] music_list;
	cout<<"User "<<name<<" deleted"<<endl;
	n_user--;
}

void User::addFavouriteMusic(char* _judul){
	music_list[num_of_favourite_music]=new char[strlen(_judul)];
	strcpy(music_list[num_of_favourite_music],_judul);
	num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* _judul){
	bool found=false;
	int i=0;
	while(i<num_of_favourite_music&&!found){
		if (strcmp(music_list[i],_judul)==0){
			found=true;
		}else{
			i++;
		}
	}
	if (found){
		int j=i;
		for(j;j<num_of_favourite_music-1;j++){
			delete [] music_list[j];
			music_list[j]=new char[strlen(music_list[j+1])];
			strcpy(music_list[j],music_list[j+1]);
		}
		delete [] music_list[j];
		num_of_favourite_music--;
	}
}
        
void User::setName(char* _name){
	delete[] name;
	name = new char[strlen(name)];
	strcpy(name,_name);
}

char* User::getName() const{
	return name;
}
int User::getNumOfFavouriteMusic() const{
	return num_of_favourite_music;
}

        // format print:
        // <No>. <Judul musik><endl>
        // contoh:
        // 1. Starship - Nicki Minaj
        // 2. To Be Human - Sia, Labrinth
        //
        // jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const{
	if (num_of_favourite_music>0){
		for(int i=0;i<num_of_favourite_music;i++){
			cout<<i+1<<". "<<music_list[i]<<endl;
		}
	}else{
		cout<<"No music in your favourite list"<<endl;
	}
}

int User::getNumOfUser(){
	return n_user;
}










































