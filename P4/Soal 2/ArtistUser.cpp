// Nama/NIM		: Steve Andreas I/13517039
// Tanggal		: 14 Feb 2019
// Topik		: Inheritence

#include <iostream>
#include "ArtistUser.h"

using namespace std;

int ArtistUser::num_of_artist=0;
//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* _name):User(_name){
	num_of_music_uploaded=0;
        uploaded_music_list=new char*[256];
        num_of_artist++;
}
        
        // cctor
ArtistUser::ArtistUser(const ArtistUser& A):User(A){
        num_of_music_uploaded=A.num_of_music_uploaded;
        uploaded_music_list=new char*[A.num_of_music_uploaded];
        num_of_artist++;
        for(int i=0;i<num_of_music_uploaded;i++){
                uploaded_music_list[i]=new char[strlen(A.uploaded_music_list[i])];
                strcpy(uploaded_music_list[i],A.uploaded_music_list[i]);
        }
}

        // dtor
        // selain implementasi, print juga "Artist user <nama user> deleted"
        // Contoh:
        // Artist user A deleted
ArtistUser::~ArtistUser(){
        cout<<"Artist user "<<getName()<<" deleted"<<endl;
        for(int i=0;i<num_of_music_uploaded;i++){
                delete [] uploaded_music_list[i];        
        }
        delete [] uploaded_music_list;
        num_of_artist--;
}

        // Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* _judul){
        uploaded_music_list[num_of_music_uploaded]=new char[strlen(_judul)];
        strcpy(uploaded_music_list[num_of_music_uploaded],_judul);
        num_of_music_uploaded++;
}
void ArtistUser::deleteUploadedMusic(char* _judul){
        bool found=false;
        int i=0;
        while(i<num_of_music_uploaded&&!found){
                if (strcmp(uploaded_music_list[i],_judul)==0){
                        found=true;
                }else{
                        i++;
                }
        }
        if (found){
                int j=i;
                for(j;j<num_of_music_uploaded-1;j++){
                        delete [] uploaded_music_list[j];
                        uploaded_music_list[j]=new char[strlen(uploaded_music_list[j+1])];
                        strcpy(uploaded_music_list[j],uploaded_music_list[j+1]);
                }
                delete [] uploaded_music_list[j];
                num_of_music_uploaded--;
        }

}

        // format print:
        // <No>. <Judul musik><endl>
        // contoh:
        // 1. Starship - Nicki Minaj
        // 2. To Be Human - Sia, Labrinth
        //
        // jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const{
        if (num_of_music_uploaded==0){
                cout<<"No music uploaded"<<endl;
        }else{
                for(int i=0;i<num_of_music_uploaded;i++){
                        cout<<i+1<<". "<<uploaded_music_list[i]<<endl;
                }
        }

}
int ArtistUser::getNumOfMusicUploaded() const{
        return num_of_music_uploaded;
}
int ArtistUser::getNumOfArtist(){
        return num_of_artist;
}
