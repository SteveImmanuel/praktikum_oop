/**
    Kelas Generik Warna, memiliki tiga atribut R,G dan B.
*/
#include <math.h>

template <class T>
class Warna {
public:
    // Ctor tanpa parameter
	Warna<T>(){
		r=0;
		g=0;
		b=0;
	}
    // Ctor berparameter, parameter berturut-turut R,G,B
    Warna<T>(T _r, T _g, T _b){
		r=_r;
		g=_g;
		b=_b;	
	}
    // cctor
    // Warna<T>(const Warna<T>&)
    // Operator=
    // Warna<T>& operator=(const Warna<T>&);

    // Getter dan setter
    T getRed() const{
		return r;
	}
    T getGreen() const{
		return g;
	}
    T getBlue() const{
		return b;
	}
    
    void setRed(T _r){
		r=_r;
	}
    void setGreen(T _g){
		g=_g;
	}
    void setBlue(T _b){
		b=_b;
	}

    //menghasilkan perbedaan absolut antara nilai R, G, dan B (Warna(abs(r1-r2),abs(g1-g2),abs(b1-b2)))
    T countDifference(Warna<T> W){
		T res=abs(r-W.r)+abs(g-W.g)+abs(b-W.b);
		return res;
	}

    // Operator overloading, mengubah nilai warna
    Warna<T> operator +(const Warna<T>& W) const{
		Warna<T> Result(r,g,b);
		Result.r+=W.r;
		Result.g+=W.g;
		Result.b+=W.b;
		return Result;
	} //rnew=r1+r2, gnew=g1+g2, bnew = b1+b2
    Warna<T> operator -(const Warna<T>& W) const{
		Warna<T> Result(r,g,b);
		Result.r-=W.r;
		Result.g-=W.g;
		Result.b-=W.b;
		return Result;
	} //rnew=r1-r2, gnew=g1-g2, bnew = b1-b2
private:
	T r;
	T g;
	T b;
};

// template <class T>
// Warna<T>::Warna(){
// 	r=0;
// 	g=0;
// 	b=0;
// }

// template <class T>
// Warna<T>::Warna(T _r,T _g,T _b){
// 	r=_r;
// 	g=_g;
// 	b=_b;
// }

// template <class T>
// Warna<T>::Warna(const Warna<T>& W){
// 	r=W.r;
// 	g=W.g;
// 	b=W.b;
// }

// template <class T>
// Warna<T>& Warna<T>::operator=(const Warna<T>& W){
// 	r=W.r;
// 	g=W.g;
// 	b=W.b;
// 	return *this;
// }

// template <class T>
// T Warna<T>::getRed() const{
// 	return r;
// }

// template <class T>
// T Warna<T>::getGreen() const{
// 	return g;
// }

// template <class T>
// T Warna<T>::getBlue() const{
// 	return b;
// }

// template <class T>
// void Warna<T>::setRed(T _r){
// 	r=_r;
// }

// template <class T>
// void Warna<T>::setGreen(T _g){
// 	g=_g;
// }

// template <class T>
// void Warna<T>::setBlue(T _b){
// 	r=_b;
// }

// template <class T>
// T Warna<T>::countDifference(Warna<T> W){
// 	T res=abs(r-W.r)+abs(g-W.g)+abs(b-W.b);
// 	return res;
// }

// template <class T>
// Warna<T> Warna<T>::operator +(const Warna<T>& W) const{
// //rnew=r1+r2, gnew=g1+g2, bnew = b1+b2
// 	// std::cout<<"masuk"<<std::endl;
// 	Warna<T> Result(r,g,b);
// 	Result.r+=W.r;
// 	Result.g+=W.g;
// 	Result.b+=W.b;
// 	return Result;
// }

// template <class T>
// Warna<T> Warna<T>::operator -(const Warna<T>& W) const{
// //rnew=r1-r2, gnew=g1-g2, bnew = b1-b2
// 	Warna<T> Result(r,g,b);
// 	Result.r-=W.r;
// 	Result.g-=W.g;
// 	Result.b-=W.b;
// 	return Result;
// }
