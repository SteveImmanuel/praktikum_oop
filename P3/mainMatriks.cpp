#include "Matriks.h"
#include <iostream>

using namespace std;

int main(){
	Matriks M1(3,3);
	for(int i=0;i<M1.GetBrs();i++){
		for(int j=0;j<M1.GetKol();j++){
			int x;
			cin>>x;
			M1.SetData(i,j,x);
		}
	}
	M1.print();
	cout<<endl;
	Matriks M2(2,2);
	for(int i=0;i<M2.GetBrs();i++){
		for(int j=0;j<M2.GetKol();j++){
			int x;
			cin>>x;
			M2.SetData(i,j,x);
		}
	}
	M2.print();
	cout<<endl;
	Matriks M3=M2-M1;
	M3.print();
	cout<<endl;
	// Matriks M3(10,20);
	// M3=M1;
	// M3.print();

	return 0;
}
