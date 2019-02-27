#include <iostream>
#include "Unggas.hpp"
using namespace std;

Unggas::Unggas(char *a){
	nama=new char[strlen(a)];
	strcpy(nama,a);
	printf("Unggas bernama %s menetas! :D\n",nama);
}

Unggas::Unggas(const Unggas& U){
	nama=new char[strlen(U.nama)];
	strcpy(nama,U.nama);
}

Unggas& Unggas::operator=(const Unggas& U){
	delete [] nama;
	nama=new char[strlen(U.nama)];
	strcpy(nama,U.nama);
	return *this;
}

Unggas::~Unggas(){
	printf("Unggas bernama %s mati T.T\n",nama);
}

Bebek::Bebek(char *a):Unggas(a){
	printf("Bebek bernama %s menetas! :D\n",nama);
}

Bebek::~Bebek(){
	printf("Bebek bernama %s mati T.T\n",nama);
}

Ayam::Ayam(char *a):Unggas(a){
	printf("Ayam bernama %s menetas! :D\n",nama);
}

Ayam::~Ayam(){
	printf("Ayam bernama %s mati T.T\n",nama);
}

AyamJago::AyamJago(char *a):Ayam(a){
	printf("AyamJago bernama %s menetas! :D\n",nama);
}
AyamJago::~AyamJago(){
	printf("AyamJago bernama %s mati T.T\n",nama);
}
void Bebek::bersuara(){
	printf("%s: \"Kwek kwek!\"\n",nama);
}
void Ayam::bersuara(){
	printf("%s: \"Tok petok petok!\"\n",nama);
}
void AyamJago::bersuara(){
	printf("%s: \"Kukuruyuk!!\"\n",nama);
}
