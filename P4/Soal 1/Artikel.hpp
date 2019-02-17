#ifndef ARTIKEL_H
#define ARTIKEL_H

#define DEFSIZE 256
#include <cstring>
class Artikel{
	private:
		char* judul;
		char* penulis;
		int tahun;
	public:
		Artikel();
		Artikel(char*,char*,int);
		Artikel(const Artikel&);
		~Artikel();
		Artikel& operator=(const Artikel&);
		char* getJudul();
		char* getPenulis();
		int getTahun();
		void setJudul(char*);
		void setPenulis(char*);
		void setTahun(int);
		void print();
};
#endif
