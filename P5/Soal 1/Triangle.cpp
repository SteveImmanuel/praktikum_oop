//Nama/NIM	: Steve Andreas Immanuel/13517039
//Tanggal	: 21-Feb-2019
//Topik		: Polimorfisme, Template

#include <iostream>
#include "Triangle.hpp"
using namespace std;

// ctor
Triangle::Triangle(float s1, float s2, float s3){
	s=new float[3];
	s[0]=s1;
	s[1]=s2;
	s[2]=s3;
}

    // cctor
    // implementasikan jika diperlukan,
    // jika tidak diperlukan, hapus cctor
Triangle::Triangle(const Triangle& triangle){
	s=new float[3];
	s[0]=triangle.s[0];
	s[1]=triangle.s[1];
	s[2]=triangle.s[2];
}

    // dtor
    // implementasikan jika diperlukan,
    // jika tidak diperlukan, hapus dtor
    // jika diperlukan,
    // selain implementasi, print juga "TRIANGLE DELETED<endl>"
Triangle::~Triangle(){
	delete [] s;
	cout<<"TRIANGLE DELETED"<<endl;
}

    // operator=
    // implementasikan jika diperlukan,
    // jika tidak diperlukan, hapus operator=
Triangle& Triangle::operator=(const Triangle& triangle){
	this->s = new float[3];
	s[0]=triangle.s[0];
	s[1]=triangle.s[1];
	s[2]=triangle.s[2];
	return *this;
}

    // getter & setter
float Triangle::getS1() const{
	return s[0];
}
float Triangle::getS2() const{
	return s[1];
}
float Triangle::getS3() const{
	return s[2];
}
void Triangle::setS1(float s1){
	s[0]=s1;
}
void Triangle::setS2(float s2){
	s[1]=s2;
}
void Triangle::setS3(float s3){
	s[2]=s3;
}

    // memeriksa apakah ketiga sisi dapat membentuk sebuah segitiga
    // Jika panjang sisi-sisi tersebut adalah a, b, dan c
    // serta a<b<c maka ketiga sisi dapat membentuk segitiga jika a+b>c
bool Triangle::isValid(float s1, float s2, float s3){
	// if(s1>=s2&&s1>=s3){
	// 	return (s2+s3)>s1;
	// }else if(s2>=s1&&s2>=s3){
	// 	return (s1+s3)>s2;
	// }else if(s3>=s2&&s3>=s1){
	// 	return (s2+s1)>s3;
	// }	
	return ((s1+s2)>s3)&&((s1+s3)>s2)&&((s3+s2)>s1);
}

    // implementasi area (method untuk menghitung luas)
    // luas segitiga = sqrt(s(s-a)(s-b)(s-c))
    // dengan a,b,c sisi segitiga dan s = 1/2 * keliling
float Triangle::area(){
	float ss=0.5*perimeter();
	return sqrt(ss*(ss-s[0])*(ss-s[1])*(ss-s[2]));
}

    // implementasi perimeter (method untuk menghitung keliling)
float Triangle::perimeter(){
	return s[0]+s[1]+s[2];
}
    // implementasi print (method untuk menampilkan informasi)
    // format: TRIANGLE(s1,s2,s3) diahkhiri endline
    // contoh: TRIANGLE(3,4,5)
void Triangle::print(){
	cout<<"TRIANGLE("<<s[0]<<","<<s[1]<<","<<s[2]<<")"<<endl;
	//printf("TRIANGLE(%f,%f,%f)\n",s[0],s[1],s[2]);
}
