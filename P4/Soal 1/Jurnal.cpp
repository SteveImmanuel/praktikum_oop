// Nama/NIM		: Steve Andreas I/13517039
// Tanggal		: 14 Feb 2019
// Topik		: Inheritence

#include <iostream>
#include "Jurnal.hpp"

using namespace std;

Jurnal::Jurnal(){
	data=new Artikel[DEFSIZE];
	size=0;
}

Jurnal::Jurnal(Artikel * A,int _size){
	size=_size;
	data=new Artikel[DEFSIZE];
	for(int i=0;i<_size;i++){
		data[i]=A[i];
	}
}

Jurnal::Jurnal(const Jurnal& J){
	size=J.size;
	data=new Artikel[DEFSIZE];
	for(int i=0;i<J.size;i++){
		data[i]=J.data[i];
	}
}

Jurnal::~Jurnal(){
	delete [] data;
}

Jurnal& Jurnal::operator=(const Jurnal& J){
	delete [] data;
	size=J.size;
	data=new Artikel[DEFSIZE];
	for(int i=0;i<J.size;i++){
		data[i]=J.data[i];
	}
	return *this;
}

void Jurnal::setData(int i,Artikel A){
	data[i]=A;
}

Artikel Jurnal::getData(int i){
	return data[i];
}
void Jurnal::setSize(int _size){
	size=_size;
}
int Jurnal::getSize(){
	return size;
}
int Jurnal::findByTahun(int _tahun){
	int found=0;
	int i=0;
	while(found==0&&i<size){
		if (data[i].getTahun()==_tahun){
			found=1;
		}else{
			i++;
		}
	}
	if (found==1){
		return i;
	}else{
		return size;
	}
}

void Jurnal::add(Artikel A){
	data[size]=A;
	size++;
}
void Jurnal::insert(int idx,Artikel A){
	// cout<<"masuk insert"<<endl;
	for(int i=size-1;i>=idx;i--){
		// cout<<i<<endl;
		// data[i].print();
		data[i+1]=data[i];
	}
	data[idx]=A;
	size++;
}
void Jurnal::print(){
	for(int i=0;i<size;i++){
		cout<<"Konten "<<i+1<<endl;
		data[i].print();
	}
}
