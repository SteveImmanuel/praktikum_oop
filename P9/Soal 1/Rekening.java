// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public abstract class Rekening{
	protected String nama;
	protected double saldo;
	protected double sukuBunga;
	
	public Rekening(String nama, double saldo, double sukuBunga){
		this.nama=nama;
		if(saldo<0){
			this.saldo=0;
		}else{
			this.saldo=saldo;
		}
		this.sukuBunga=sukuBunga;
	}
	public abstract void setor(double x);
	public abstract void tarik(double x);
	public abstract void update();
	public double hitungBiaya(){
		if((this.saldo*0.1)>10){
            return 10;
        }else{
            return this.saldo*0.1;
        }
	}
	public String getNama(){
		return this.nama;
	}
	public double getSaldo(){
		return this.saldo;
	}
	public double getSukuBunga(){
		return this.sukuBunga;
	}



}
