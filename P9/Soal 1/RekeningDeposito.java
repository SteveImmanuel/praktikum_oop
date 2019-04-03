// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class RekeningDeposito extends Rekening{
	private int bulan;
	
	public RekeningDeposito(String nama, double saldo){
		super(nama,saldo,0.15);
		this.bulan=0;
	}
	@Override
	public void setor(double x){
		System.out.println("Tidak dapat melakukan penyetoran uang untuk rekening ini.");
	}
	@Override
	public void tarik(double x){
		System.out.println("Tidak dapat melakukan penarikan uang sebagian untuk rekening ini.");
	}
	@Override
	public void update(){
		this.bulan++;
		double potongan=super.hitungBiaya();
		if(this.bulan%12==0){
			double bunga=this.saldo*this.sukuBunga;
			this.saldo+=bunga;
		}
		this.saldo-=potongan;
	}
	
	public void tarik(){
		if(this.bulan<12){
			double penalti=0.2*this.saldo;
			System.out.println("Anda terkena penalti sebesar "+penalti+".");
		}
		this.saldo=0;
	}

}
