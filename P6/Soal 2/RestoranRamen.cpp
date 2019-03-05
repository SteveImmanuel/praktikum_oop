#include <iostream>
#include "RestoranRamen.hpp"
using namespace std;

void RestoranRamen::tambahOrder(int n,int p){
	map<int,int>::iterator itr;
	itr=daftarMeja.find(n);
	if(itr==daftarMeja.end()){
		daftarMeja.insert(pair<int,int>(n,p));
	}else{
		itr->second+=p;
	}
}

int RestoranRamen::tutupOrder(int n){
	int temp=daftarMeja[n];
	daftarMeja.erase(n);
	return temp;
}

int RestoranRamen::cekTotal(int n){
	return daftarMeja[n];
}

int RestoranRamen::totalMeja(){
	return daftarMeja.size();
}

void RestoranRamen::cetakMeja(){
	map<int,int>::iterator itr;
	if(totalMeja()>0){
		for(itr=daftarMeja.begin();itr!=daftarMeja.end();itr++){
			cout<<"Meja "<<itr->first<<" = "<<itr->second<<endl;
		}
	}else{
		cout<<"Restoran kosong"<<endl;
	}
}
