#include <iostream>
#include "Pecahan.h"
using namespace std;

int GCD (int nx, int ny) {
  int n1, n2;
  n1=nx; n2=ny;
  while(n1 != n2)
  {
    if(n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  return n1;
}

Pecahan::Pecahan(){
	n=1;
	a=0;
	b=1;
}
Pecahan::Pecahan (int n, int a, int b){
	int kelebihan,pembilang,penyebut,gcd;
	kelebihan=a/b;
	pembilang=a%b;
	penyebut=b;
	gcd=GCD(a,b);
	pembilang/=gcd;
	penyebut/=gcd;
	this->n=n+kelebihan;
	this->a=pembilang;
	this->b=penyebut;
}
int Pecahan::getBulat (){
	return n;
}
int Pecahan::getPembilang (){
	return a;
}
int Pecahan::getPenyebut(){
	return b;
}
void Pecahan::setBulat(int _n){
	n=_n;
}
void Pecahan::setPembilang(int _a){
	a=_a;
}
void Pecahan::setPenyebut(int _b){
	b=_b;
}
bool Pecahan::isValid(int n, int a, int b) //hanya perlu cek apakah n>=0, a>=0, b >1
{
	return n>=0&&a>=0&&b>1;
}
Pecahan Pecahan::addWithThis (Pecahan P) // Menghasilkan P + current objek
{
	Pecahan result(n,a,b);
	// int kelebihan,bulat,pembilang,penyebut,gcd;
	// penyebut=b*P.getPenyebut();
	// pembilang=(a*P.getPenyebut())+(P.getPembilang()*b);
	// kelebihan=pembilang/penyebut;
	// pembilang%=penyebut;
	// bulat=n+P.getBulat()+kelebihan;
	// gcd=GCD(pembilang,penyebut);
	// pembilang/=gcd;
	// penyebut/=gcd;
	// result.setBulat(bulat);
	// result.setPembilang(pembilang);
	// result.setPenyebut(penyebut);
	result.accumulate(P);
	return result;
}

void Pecahan::accumulate(Pecahan P) // Mennambahkan P ke current objek
{
	int gcd;
	a=(a*P.getPenyebut())+(P.getPembilang()*b);
	b=b*P.getPenyebut();
	n=n+P.getBulat()+a/b;
	gcd=GCD(a,b);
	a=(a%b)/gcd;
	b/=gcd;
}

Pecahan Pecahan::add(Pecahan P1, Pecahan P2) /* menghasilkan P1+P2 tanpa menyentuh current object, untuk sementara walau “aneh”, realisasikan */
{
	Pecahan result=P1;
	return result.addWithThis(P2);
}

bool Pecahan::isEQMe(Pecahan P) //true jika P sama dengan current object
{
	return P.value()==value();
}
bool Pecahan::isGTMe(Pecahan P) //true P > current object
{
	return P.value()>value();
}
bool Pecahan::isLTMe(Pecahan P)// trus jika P < current object
{
	return P.value()<value();
}
    //operator lain
float Pecahan::value() // menghasilkan nilai pecahan, misalnya 1 3/4 menjadi 1.75
{
	float result;
	result=n+((float)a/(float)b);
	return result;
}


// void Pecahan::print(){
// 	cout<<n<<" "<<a<<" "<<b<<endl;
// }





















