#include "warna.h"

/**
    Kelas ArrayWarna, menyimpan dua buah array, array pertama berisi objek T dan array kedua berisi objek Warna 
    Ukuran maksimum pada array ditandai dengan atribut size dan jumlah elemen pada array ditandai dengan atribut neff
*/

template <class T>
class ArrayWarna {
public:
    // cctor tanpa parameter dengan ukuran maksimum 10
	ArrayWarna<T>(){
		size=10;
		neff=0;
		data=new T[size];
		warna=new Warna<T>[size];	
	}
    // Membuat sebuah ArrayWarna dengan ukuran maksimum n
    ArrayWarna<T>(int n){
		size=n;
		neff=0;
		data=new T[size];
		warna=new Warna<T>[size];
	}
    // cctor
    ArrayWarna<T>(const ArrayWarna<T>& AW){
		size=AW.size;
		neff=AW.neff;
		data=new T[size];
		warna=new Warna<T>[size];
		for(int i=0;i<neff;i++){
			data[i]=AW.data[i];
			warna[i]=AW.warna[i];
		}
	}
    // Operator=
    ArrayWarna<T>& operator=(const ArrayWarna<T>& AW){
		size=AW.size;
		neff=AW.neff;
		data=new T[size];
		warna=new Warna<T>[size];
		for(int i=0;i<neff;i++){
			data[i]=AW.data[i];
			warna[i]=AW.warna[i];
		}
		return *this;
	}

    // true jika array penuh
    bool isFull(){
		return neff==size;
	}
    // true jika array kosong
    bool isEmpty(){
		return neff==0;
	}

    // Getter
    int getSize() const{
		return size;
	}
    int getNeff() const{
		return neff;
	}
    
    // Menambahkan elemen warna dan data di akhir array
    void addElement(T da, Warna<T> wa){
		if(!isFull()){
			setElement(da,wa,neff);
			neff++;
		}
	}
    // Mengubah warna dan data pada index ke n
    void setElement(T da, Warna<T> wa, int n){
		data[n]=da;
		warna[n]=wa;
	}

    // Mengembalikan data pada index ke n; n TIDAK mungkin di luar index
    T getData(int n){
		return data[n];
	}
    
    // Mengembalikan warna pada index ke n; n TIDAK mungkin di luar index
    Warna<T> getWarna(int n){
		return warna[n];
	}
private:
	T *data;
	Warna<T> *warna;
	int size;
	int neff;
};

// template <class T>
// ArrayWarna<T>::ArrayWarna(){
// 	size=10;
// 	neff=0;
// 	data=new T[size];
// 	warna=new Warna<T>[size];
// }

// template <class T>
// ArrayWarna<T>::ArrayWarna(int n){
// 	size=n;
// 	neff=0;
// 	data=new T[size];
// 	warna=new Warna<T>[size];
// }

// template <class T>
// ArrayWarna<T>::ArrayWarna(const ArrayWarna<T>& AW){
// 	size=AW.size;
// 	neff=AW.neff;
// 	data=new T[size];
// 	warna=new Warna<T>[size];
// 	for(int i=0;i<neff;i++){
// 		data[i]=AW.data[i];
// 		warna[i]=AW.warna[i];
// 	}
// }

// template <class T>
// ArrayWarna<T>& ArrayWarna<T>::operator=(const ArrayWarna<T>& AW){
// 	size=AW.size;
// 	neff=AW.neff;
// 	data=new T[size];
// 	warna=new Warna<T>[size];
// 	for(int i=0;i<neff;i++){
// 		data[i]=AW.data[i];
// 		warna[i]=AW.warna[i];
// 	}
// 	return *this;
// }

// template <class T>
// bool ArrayWarna<T>::isFull(){
// 	return neff==size;
// }

// template <class T>
// bool ArrayWarna<T>::isEmpty(){
// 	return neff==0;
// }

// template <class T>
// int ArrayWarna<T>::getSize() const{
// 	return size;
// }

// template <class T>
// int ArrayWarna<T>::getNeff() const{
// 	return neff;
// }


// template <class T>
// void ArrayWarna<T>::addElement(T da,Warna<T> wa){
// 	if(!isFull()){
// 		setElement(da,wa,neff);
// 		neff++;
// 	}
// }

// template <class T>
// void ArrayWarna<T>::setElement(T da,Warna<T> wa,int n){
// 	data[n]=da;
// 	warna[n]=wa;
// }

// template <class T>
// T ArrayWarna<T>::getData(int n){
// 	return data[n];
// }

// template <class T>
// Warna<T> ArrayWarna<T>::getWarna(int n){
// 	return warna[n];
// }
