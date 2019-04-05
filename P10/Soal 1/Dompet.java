// Nama/NIM		: Steve Andreas I / 13517039
// Tanggal 		: 4-4-19
// Topik		: Generic


import java.util.*;

public class Dompet<T extends Number> {
    private ArrayList<Transaction<T>> transactions;


     public Dompet() {
        // Constructor tanpa parameter, transactions diinisialisasi dengan array list baru
        transactions=new ArrayList<Transaction<T>>();
    }


    public Dompet(T initialBalance) {
        // Constructor dengan parameter T initialBalance, inisialisasi transactions dengan array list baru dan tambahkan transaksi tambah dengan value initial balance
        /* contoh transaksi tambah: new Transaction<T>('+', initialBalance) */
        transactions=new ArrayList<Transaction<T>>();
        Transaction<T> tambah=new Transaction<T>('+',initialBalance);
        transactions.add(tambah);
    }

    public void addMoney(T money) {
        // Buat prosedur addMoney dengan parameter T money, tambahkan transaksi tambah dengan senilai money
        Transaction<T> tambah=new Transaction<T>('+',money);
        transactions.add(tambah);
    }

    public boolean takeMoney(T money) {
        // Tambahkan transaksi kurang sebesar money (perlu ada pengecekan apakah balance cukup atau tidak)
        // false bila transaksi gagal, true bila berhasil
        Double balance=getBalance();
        if(balance>=money.doubleValue()){
			Transaction<T> kurang=new Transaction<T>('-',money);
			transactions.add(kurang);
			return true;
		}else{
			return false;
		}
    }

    public void setBalance(T balance) {
        // Mengganti transaksi agar bernilai sama dengan balance
        // Tips: inisialisasi ulang transactions, lalu tambahkan transaksi tambah sebanyak balance
        Transaction<T> newBalance;
        transactions=new ArrayList<Transaction<T>>();
        if(balance.doubleValue()<0){
			newBalance=new Transaction<T>('-',balance);
		}else{
			newBalance=new Transaction<T>('+',balance);
		}
        transactions.add(newBalance);
    }

    // Akses nilai Double dilakukan dengan .doubleValue()
    // Contoh: amount.doubleValue()

    public Double getBalance(){
        // Mencari balance dompet dari transaksi dengan cara menghitung total transaksi
        Double sum=0.0;
        for(int i=0;i<transactions.size();i++){
			if(transactions.get(i).getType()=='+'){
				sum+=transactions.get(i).getAmount().doubleValue();
			}else if(transactions.get(i).getType()=='-'){
				sum-=transactions.get(i).getAmount().doubleValue();
			}
		}
		return sum;
    }

    public void printTransactions() {
        // Print seluruh transaksi yang ada pada array
        // Format: Transactions [indeks + 1]: [tipe transaksi] [amount]
        // Contoh: Transactions 3: + 500
        for(int i=0;i<transactions.size();i++){
			System.out.println("Transactions "+(i+1)+": "+transactions.get(i).getType()+" "+transactions.get(i).getAmount());
		}
    }

    public Double getAverageTransaction() {
        // Mencari rata-rata transaksi (jika tidak ada transaksi, berikan hasil null)
        if(transactions.size()==0){
			return null;
		}else{
			return getBalance()/transactions.size();
		}
    }

    public Double getMinimumTransaction() {
        // Mencari nilai minimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        if(transactions.size()==0){
			return null;
		}else{
			Double min=transactions.get(0).getAmount().doubleValue();
			for(int i=1;i<transactions.size();i++){
				if(transactions.get(i).getAmount().doubleValue()<min){
					min=transactions.get(i).getAmount().doubleValue();
				}
			}
			return min;
		} 
    }

    public Double getMaximumTransaction() {
        // Mencari nilai maksimum transaksi (jika tidak ada transaksi, berikan hasil null; hanya perlu membandingkan nilainya saja tanpa peduli type)
        if(transactions.size()==0){
			return null;
		}else{
			Double max=transactions.get(0).getAmount().doubleValue();
			for(int i=1;i<transactions.size();i++){
				if(transactions.get(i).getAmount().doubleValue()>max){
					max=transactions.get(i).getAmount().doubleValue();
				}
			}
			return max;
		} 
    }
}
