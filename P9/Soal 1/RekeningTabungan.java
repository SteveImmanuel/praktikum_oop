// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class RekeningTabungan extends Rekening{
	public RekeningTabungan(String nama, double saldo){
		super(nama,saldo,0.05);
	}
	@Override
	public void setor(double x){
		this.saldo+=x;
	}
	@Override
	public void tarik(double x){
		if(this.saldo>=x){
			this.saldo-=x;
		}
	}
	@Override
	public void update(){
		double bunga=this.saldo*this.sukuBunga;
		double potongan=super.hitungBiaya();
		this.saldo=this.saldo+bunga-potongan;
	}

}
