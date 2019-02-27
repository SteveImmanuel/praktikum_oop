#include <iostream>

using namespace std;

template <class T>
void func(T t1,T t2){
	cout<<"Masukan Anda: "<<t1<<" dan "<<t2<<", memiliki tipe yang sama"<<endl;
}

template <class T1,class T2>
void func(T1 t1,T2 t2){
	cout<<"Masukan Anda: "<<t1<<" dan "<<t2<<", mungkin memiliki tipe yang berbeda"<<endl;
}

template<>
void func(char t1,int t2){
	for(int i=0;i<t2;i++){
		cout<<t1<<endl;
	}
}
/*
int main(){
	char a='a';
	int b=2;*/
	//float c,d;
	//func(a,b);
	//func(a,c);
//}
