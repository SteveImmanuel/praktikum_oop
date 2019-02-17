// Nama/NIM		: Steve Andreas I/13517039
// Tanggal		: 14 Feb 2019
// Topik		: Inheritence

#include <iostream>
#include "Artikel.hpp"

using namespace std;

Artikel::Artikel(){
	tahun=0;
	judul=new char[DEFSIZE];
	penulis=new char[DEFSIZE];
	for(int i=0;i<DEFSIZE;i++){
		judul[i]='\0';
		penulis[i]='\0';
	}
}

Artikel::Artikel(char* _judul,char* _penulis,int _tahun){
	judul=new char[DEFSIZE];
	penulis=new char[DEFSIZE];
	strcpy(judul,_judul);
	strcpy(penulis,_penulis);
	tahun=_tahun;	
}

Artikel::Artikel(const Artikel& A){
	judul=new char[DEFSIZE];
	penulis=new char[DEFSIZE];
	strcpy(judul,A.judul);
	strcpy(penulis,A.penulis);
	tahun=A.tahun;
}

Artikel::~Artikel(){
	delete [] judul;
	delete [] penulis;	
}


Artikel& Artikel::operator=(const Artikel& A){
	delete [] judul;
	delete [] penulis;	
	judul=new char[DEFSIZE];
	penulis=new char[DEFSIZE];
	strcpy(judul,A.judul);
	strcpy(penulis,A.penulis);
	tahun=A.tahun;
	return *this;
}
char* Artikel::getJudul(){
	return judul;
}
char* Artikel::getPenulis(){
	return penulis;
}
int Artikel::getTahun(){
	return tahun;
}
void Artikel::setJudul(char* _judul){
	strcpy(judul,_judul);
}
void Artikel::setPenulis(char* _penulis){
	strcpy(penulis,_penulis);
}
void Artikel::setTahun(int _tahun){
	tahun=_tahun;
}
void Artikel::print(){
	cout<<penulis<<". "<<tahun<<". \""<<judul<<"\"."<<endl;
}
		
		
		
		
		
		
