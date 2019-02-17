#include "Box.h"
#include <iostream>

using namespace std;

int main(){
	Box B0(2);
	B0.set(0,50);
	B0.set(1,30);
	B0.show();
	Box B1=B0;
	Box B2(2);
	B2=B1;
	B0.set(0,10);
	B0.show();
	B1.show();
	B2.show();
	Box B3(2);
	if(1==1){
	Box B4=B0+B2;
	Box B5=B4+B1;
	
	B3=B5;
	}
	B3.show();
	/////////////
	//Box B5(2);
	//B5+B2;
	//Box B6(2);
	//B4=B6;
	//B4.show();
	//B0.show();
	return 0;
}
/*
ctor 0
set 0, idx=0, val=50
set 0, idx=1, val=30
show 0: 50 30
cctor 1
ctor 2
assign 2 = 1
set 0, idx=0, val=10
show 0: 10 30
show 1: 10 30
show 2: 50 30
ctor 3
0 + 2
ctor 4
4 + 1
ctor 5
assign 3 = 5
dtor 5
dtor 4
show 3: 70 90
dtor 3
dtor 2
dtor 1
dtor 0
*/
