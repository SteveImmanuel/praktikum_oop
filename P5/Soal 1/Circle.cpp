//Nama/NIM	: Steve Andreas Immanuel/13517039
//Tanggal	: 21-Feb-2019
//Topik		: Polimorfisme, Template

#include <iostream>
#include "Circle.hpp"
using namespace std;

Circle::Circle(float radius){
	this->radius=radius;
}

float Circle::getRadius() const{
	return this->radius;
}
void Circle::setRadius(float radius){
	this->radius=radius;
}

// implementasi area (method untuk menghitung luas)
    // untuk nilai phi gunakan nilai 3.14
float Circle::area(){
	return 3.14*radius*radius;
}

    // implementasi perimeter (method untuk menghitung keliling)
    // untuk nilai phi gunakan nilai 3.14
float Circle::perimeter(){
	return 2*3.14*radius;
}
	
    // implementasi print (method untuk menampilkan informasi)
    //format: CIRCLE(radius) diahkhiri endline
    //contoh: CIRCLE(7)
void Circle::print(){
	cout<<"CIRCLE("<<radius<<")"<<endl;
}
