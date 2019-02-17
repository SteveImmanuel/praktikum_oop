#include <iostream>
#include "Matriks.h"

using namespace std;

Matriks::Matriks():num_brs(DEFSIZE),num_kol(DEFSIZE){
	b=new int*[num_brs];
	for(int i=0;i<num_brs;i++){
		b[i]=new int[num_kol];
		for(int j=0;j<num_kol;j++){
			b[i][j]=0;
		}
	}	
}

Matriks::Matriks(int n, int m):num_brs(n),num_kol(m){
	b=new int*[num_brs];
	for(int i=0;i<num_brs;i++){
		b[i]=new int[num_kol];
		for(int j=0;j<num_kol;j++){
			b[i][j]=0;
		}
	}
}

Matriks::Matriks(const Matriks &m):num_brs(m.num_brs),num_kol(m.num_kol){
	b=new int*[num_brs];
	for(int i=0;i<num_brs;i++){
		b[i]=new int[num_kol];
		for(int j=0;j<num_kol;j++){
			b[i][j]=m.b[i][j];
		}
	}
	
}

// dtor
Matriks::~Matriks(){
	for(int i=0;i<num_brs;i++){
		delete [] b[i];
	}
	delete [] b;
}



// operator= menjamin tidak bitwise copy.
// dan dapat melakukan assignment m1=m2; prekondisi: ukuran m1=ukuran m2
Matriks& Matriks::operator=(Matriks &m){
	for(int i=0;i<num_brs;i++){
		for(int j=0;j<num_kol;j++){
			b[i][j]=m.b[i][j];
		}
	}
	return *this;
}

// test apakah ukuran sama: true jika m1.num_brs== m2.num_brs && m1.num_kol== m2.num_kol
bool IsEqSize(Matriks m1, Matriks m2){
	return m1.num_brs== m2.num_brs && m1.num_kol== m2.num_kol;
}



// operator+ penjumlahan nilai b dari kedua matriks yg posisinya sama
// Mhasil(i,j) = M1 (i,j) + M2(i,j)
// Proses : jika ukuran m2 tak sama dengan current object,
// yang tak beririsan tidak dijumlahkan, hanya dicopy
// hasilnya adalah matriks yang lebih besar
// ditulis sebagai function member
Matriks Matriks::operator+(Matriks m2){
// 	// cout<<"masuk operator+"<<endl;
// 	if(num_kol>=m2.num_kol && num_brs>=m2.num_brs){
// 		Matriks result(num_brs,num_kol);
// 		for(int i=0;i<num_brs;i++){
// 			for(int j=0;j<num_kol;j++){
// 				if(i<m2.num_brs&&j<m2.num_kol){
// 					result.b[i][j]=b[i][j]+m2.b[i][j];
// 				}else{
// 					result.b[i][j]=b[i][j];
// 				}
// 			}
// 		}
// 		return result;
// 	}else{
// 		// cout<<"m2 lebih besar"<<endl;
// 		Matriks result(m2.num_brs,m2.num_kol);//m2 lebih besar =
// 		for(int i=0;i<m2.num_brs;i++){
// 			for(int j=0;j<m2.num_kol;j++){
// 				if(i<num_brs&&j<num_kol){
// 					result.b[i][j]=b[i][j]+m2.b[i][j];
// 				}else{
// 					result.b[i][j]=m2.b[i][j];
// 				}
// 			}
// 		}
// 		return result;	
// 	}
// }
	int iterateBrs;
	int iterateKol;
	
	if(num_brs>m2.num_brs){
		iterateBrs = num_brs;
	}else{
		iterateBrs = m2.num_brs;
	}
	
	if(num_kol>m2.num_kol){
		iterateKol = num_kol;
	}else{
		iterateKol = m2.num_kol;
	}
	
	Matriks out(iterateBrs, iterateKol);
	
	for(int i = 0;i<iterateBrs;i++){
		for(int j = 0;j<iterateKol;j++){
			if(i<num_brs && i<m2.num_brs && j<num_kol && j<m2.num_kol){
				out.b[i][j] = b[i][j] + m2.b[i][j];
			}else{
				if(i<num_brs && j<num_kol){
					out.b[i][j] = b[i][j];
				}else{
					out.b[i][j] = m2.b[i][j];
				}
			}
		}
	}
	
	return out;
}




// operator- pengurangan nilai b dari kedua matriks yg posisinya sama
// Mhasil(i,j) = M1 (i,j) - M2(i,j)
// Proses : jika ukuran m2 tak sama dengan current object,
// yang tak beririsan tidak dijumlahkan, hanya dicopy
// hasilnya adalah matriks yang lebih besar
// ditulis sebagai friend function
Matriks operator-(const Matriks &m1, const Matriks &m2){
// 	if(m1.num_kol>=m2.num_kol&& m1.num_brs>=m2.num_brs){//object lebih besar
// 		Matriks result(m1.num_brs,m1.num_kol);
// 		for(int i=0;i<result.num_brs;i++){
// 			for(int j=0;j<result.num_kol;j++){
// 				if(i<m2.num_brs&&j<m2.num_kol){
// 					result.b[i][j]=m1.b[i][j]-m2.b[i][j];
// 				}else{
// 					result.b[i][j]=m1.b[i][j];
// 				}
// 			}
// 		}
// 		return result;	
// 	}else{
// 		Matriks result(m2.num_brs,m2.num_kol);//m2 lebih besar =
// 		for(int i=0;i<result.num_brs;i++){
// 			for(int j=0;j<result.num_kol;j++){
// 				result.b[i][j]=m2.b[i][j];
// 				if(i<m1.num_brs&&j<m1.num_kol){
// 					result.b[i][j]=m1.b[i][j]-m2.b[i][j];
// 				}else{
// 					result.b[i][j]=m2.b[i][j];
// 				}
// 			}
// 		}
// 		return result;	
// 	}
// }
	int iterateBrs;
	int iterateKol;
	
	if(m1.num_brs>m2.num_brs){
		iterateBrs = m1.num_brs;
	}else{
		iterateBrs = m2.num_brs;
	}
	
	if(m1.num_kol>m2.num_kol){
		iterateKol = m1.num_kol;
	}else{
		iterateKol = m2.num_kol;
	}
	
	Matriks out(iterateBrs, iterateKol);
	
	for(int i = 0;i<iterateBrs;i++){
		for(int j = 0;j<iterateKol;j++){
			if(i<m1.num_brs && i<m2.num_brs && j<m1.num_kol && j<m2.num_kol){
				out.b[i][j] = m1.b[i][j] - m2.b[i][j];
			}else{
				if(i<m1.num_brs && j<m1.num_kol){
					out.b[i][j] = m1.b[i][j];
				}else{
					out.b[i][j] = m2.b[i][j];
				}
			}
		}
	}
	
	return out;
}


// operator* perkalian dengan sebuah bilangan konstanta
// ditulis sebagai function member
Matriks Matriks::operator*(const int n){
	Matriks result(num_brs,num_kol);
	for(int i=0;i<result.num_brs;i++){
		for(int j=0;j<result.num_kol;j++){
			result.b[i][j]=b[i][j]*n;
		}		
	}
	return result;	
}



// operator* perkalian dengan sebuah bilangan konstanta
// diimplementasikan untuk memenuhi sifat komutatif
// ditulis sebagai frined function
Matriks operator*(const int n, const Matriks m2){
	Matriks result(m2.num_brs,m2.num_kol);
	for(int i=0;i<result.num_brs;i++){
		for(int j=0;j<result.num_kol;j++){
			result.b[i][j]=m2.b[i][j]*n;
		}		
	}
	return result;	
	
} 

// isikan nilai v di posisi data[i,j], i dan j terdefinisi
void Matriks::SetData(int i, int j, int v){
	this->b[i][j]=v;
}

// ambil elemen v di posisi data[i,j], i dan j terdefinisi
int Matriks::GetData(int i, int j) const{
	return this->b[i][j];
}

// Mengembalikan num_brs
int Matriks::GetBrs() const{
	return this->num_brs;
}
// Mengembalikan num_kol
int Matriks::GetKol() const{
	return this->num_kol;
}
// Mengecek apakah num_brs sama dengan num_kol
bool Matriks::IsSimetri() const{
	return this->num_brs==this->num_kol;
}

// void Matriks::print(){
// 	for(int i=0;i<num_brs;i++){
// 		for(int j=0;j<num_kol;j++){
// 			cout<<b[i][j]<<"	";
// 		}
// 		cout<<endl;
// 	}

// }