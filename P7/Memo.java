// Nama/NIM	:Steve Andreas I/13517039
// Tanggal	: 11 Maret 2019
// file: Memo.java
// sebuah kelas menyimpan sebuah value
// lengkapilah dengan package yang diperlukan

class Memo {
private int val;

// ctor
public Memo(int _val) { 
	this.val=_val;
};

// getter
public int getVal() { 
	return this.val;
}; // mengirim nilai val

// setter
public void setVal(int _val) { 
	this.val=_val;
}; // set nilai val

// fungsi lain, jika anda tak sempat membuat dg benar, tutup sebagai komentar
public void mirror() { 
	int sum=0;
	int temp=this.val;
	while(temp>0){
		sum=sum*10+temp%10;
		temp/=10;		
	}
	this.val=sum;
}; // "membalik" atribut val, misalnya 123 menjadi 321

public String toString() { 
	return String.valueOf(this.val);
}; // membentuk String dari angka 
// misalnya val=8 dituliskan 8

}


