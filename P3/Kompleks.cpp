#include <iostream>
#include "Kompleks.h"

using namespace std;

int Kompleks::n_kompleks=0;

Kompleks::Kompleks(){
	real=0;
	imaginer=0;
	n_kompleks++;
}

Kompleks::Kompleks(int real, int imaginer){
	this->real=real;
	this->imaginer=imaginer;
	n_kompleks++;
}

//mengembalikan bagian riil
int Kompleks::GetReal() const{
	return real;
}

// mengembalikan bagian imaginer
int Kompleks::GetImaginer() const{
	return imaginer;
}

// mengisi bagian riil
void Kompleks::SetReal(int r){
	real=r;
}

// mengisi bagian imaginer
void Kompleks::SetImaginer(int i){
	imaginer=i;
}

// operator+ untuk melakukan penjumlahan dengan rumus berikut
    // (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& K1, const Kompleks& K2){
	Kompleks result;
	result.SetReal(K1.real+K2.real);
	result.SetImaginer(K1.imaginer+K2.imaginer);
	return result;
}

// operator- untuk melakukan pengurangan dengan rumus berikut
// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& K1, const Kompleks& K2){
	Kompleks result;
	result.SetReal(K1.real-K2.real);
	result.SetImaginer(K1.imaginer-K2.imaginer);
	return result;	
}

// operator* untuk melakukan perkalian dengan rumus berikut
// (a + bi)(c + di) = ac + bci + adi + bd i^2 = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& K1, const Kompleks& K2){
	Kompleks result;
	result.SetReal(K1.real*K2.real-K1.imaginer*K2.imaginer);
	result.SetImaginer(K1.imaginer*K2.real+K1.real*K2.imaginer);
	return result;
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta
// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& K, const int C){
	Kompleks result;
	result.SetReal(K.real*C);
	result.SetImaginer(K.imaginer*C);
	return result;	
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta (sifat komutatif)
Kompleks operator* (const int C, const Kompleks& K){
	Kompleks result;
	result.SetReal(K.real*C);
	result.SetImaginer(K.imaginer*C);
	return result;	
}

// mengembalikan jumlah instance yang pernah dibuat
int Kompleks::CountKompleksInstance(){
	return n_kompleks;
}


// mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
    // contoh:
    // 3+5i
    // 0+0i
    // -5-4i
void Kompleks::Print(){
	cout<<real;
	if (imaginer>=0){
		cout<<'+'<<imaginer<<'i'<<endl;
	}else{
		cout<<imaginer<<'i'<<endl;
	}
	
	
}








