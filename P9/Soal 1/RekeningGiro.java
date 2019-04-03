// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class RekeningGiro extends Rekening{
	private Boolean penalti;
	
	public RekeningGiro(String nama, double saldo){
		super(nama,saldo,0.07);
		if(saldo<500){
			this.penalti=true;
		}else{
			this.penalti=false;
		}
	}
	@Override
	public void setor(double x){
		this.saldo+=x;
		this.saldo-=0.1;
	}
	@Override
	public void tarik(double x){
		if(this.saldo>=(x+0.1)){
			this.saldo-=x;
			this.saldo-=0.1;
			if(this.saldo<500){
				this.penalti=true;
			}
		}
	}
	@Override
	public void update(){
		double bunga=this.saldo*this.sukuBunga;
		double potongan=super.hitungBiaya();
		this.saldo=this.saldo+bunga-potongan;
		if(this.penalti){
			this.saldo-=10;
		}
		if(this.saldo<500){
			this.penalti=true;
		}else{
			this.penalti=false;
		}
		if(this.saldo<0){
			this.saldo=0;
		}
		
		
	}

}
