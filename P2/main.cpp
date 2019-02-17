#include "Paper.hpp"
#include <iostream>
using namespace std;

int main(){
	Paper a('A');
	Paper b('B');
	Paper c('C');
	Paper d=c;
	a.fold();
	b.fold();
	c.fold();
	c.glue();
	
	c.setName('X');
	d.fold();
	d.glue();
	return 0;
}
/*
ctor A
ctor B
ctor C
cctor C
fold A(1)
fold B(1)
fold C(1)
glue C
fold C(2)
setName C => X
fold C(1)
glue C
fold C(2)
dtor C
dtor X
dtor B
dtor A
*/
