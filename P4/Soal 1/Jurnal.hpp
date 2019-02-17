#ifndef JURNAL_H
#define JURNAL_H

#include "Artikel.hpp"

class Jurnal{
	private:
		Artikel * data;
		int size;
	public:
		Jurnal();
		Jurnal(Artikel *,int);
		Jurnal(const Jurnal&);
		~Jurnal();
		Jurnal& operator=(const Jurnal&);
		void setData(int,Artikel);
		Artikel getData(int);
		void setSize(int);
		int getSize();
		int findByTahun(int);
		void add(Artikel);
		void insert(int,Artikel);
		void print();
};
#endif
