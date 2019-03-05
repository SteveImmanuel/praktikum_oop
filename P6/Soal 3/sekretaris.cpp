#include <iostream>
#include "sekretaris.h"
using namespace std;

/*
	Membuat objek Sekretaris dengan nilai energi dan tinta
	default. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris(){
	energi=ENERGI_MAX;
	tinta=TINTA_DEFAULT;
	kertas=KERTAS_DEFAULT;
	memoLength=0;
	memo=new Memo[1000];
}
/*
	Membuat objek Sekretaris dengan nilai energi dan tinta
	sesuai yang diberikan. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris::Sekretaris(int kertas, int tinta)
{
	this->energi=ENERGI_MAX;
	this->tinta=tinta;
	this->kertas=kertas;
	this->memoLength=0;
	this->memo=new Memo[1000];
}
/*
	Dealokasi variabel-variabel yang perlu didealokasi.
	Jika tidak perlu, hapus metode ini.
*/

Sekretaris::~Sekretaris()
{
	delete [] memo;
}

/*
	Membuat memo dengan isi sesuai yang diberikan. Metode ini
	menggunakan metode pakaiKertas, pakaiTinta, dan pakaiEnergi.
	Untuk membuat 1 memo akan menghabiskan 1 kertas, 1 energi,
	dan tinta sebanyak jumlah karakter pesan.

	Ada beberapa penyebab memo gagal dibuat, yaitu:
	- Jika kertas habis, akan mengeluarkan pesan dari exception,
		ditambah dengan ", segera isi kertas"
	- Jika tinta kurang, akan mengeluarkan pesan dari exception,
		ditambah dengan ", segera isi tinta"
	- Jika energi habis, akan mengeluarkan pesan dari exception,
		ditambah dengan ", segera istirahat"
	- Jika pesan terlalu panjang, akan mengeluarkan pesan dari
		exception, ditambah dengan ", perpendek pesannya"

	Jika memo gagal dibuat, maka tinta, kertas, dan energi tidak
	berkurang. Gunakan metode batalPakaiKertas, batalPakaiTinta,
	dan batalPakaiEnergi.

	Jika berhasil, maka memo akan dimasukkan ke daftar memo serta
	menampilkan pesan "Memo [<nomor_memo>] untuk <untuk> berhasil
	dibuat"

	Keterangan:
	<...> -> ganti dengan nilai yang sesuai.
*/
void Sekretaris::buatMemo(string pesan, string untuk){
	try{
		pakaiKertas();
		pakaiTinta(pesan.length());
		pakaiEnergi();
		Memo m(pesan,untuk);
		memo[memoLength]=m;
		memoLength++;
		cout<<"Memo ["<<memoLength<<"] untuk "<<untuk<<" berhasil dibuat"<<endl;
	// }catch(KertasHabisException e){
	// 	batalPakaiKertas();
	// 	cout<<e.what()<<", segera isi kertas"<<endl;
	// }catch(TintaKurangException e){
	// 	batalPakaiKertas();
	// 	batalPakaiTinta(pesan.length());
	// 	cout<<e.what()<<", segera isi tinta"<<endl;
	// }catch(EnergiHabisException e){
	// 	batalPakaiKertas();
	// 	batalPakaiTinta(pesan.length());
	// 	batalPakaiEnergi();
	// 	cout<<e.what()<<", segera istirahat"<<endl;
	// }catch(PesanKepanjanganException e){
	// 	batalPakaiKertas();
	// 	batalPakaiTinta(pesan.length());
	// 	batalPakaiEnergi();
	// 	cout<<e.what()<<", perpendek pesannya"<<endl;
	// }
	} catch (PesanKepanjanganException e) {
		cout<<e.what()<<", perpendek pesannya"<<endl;
		batalPakaiEnergi();
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
	} catch (EnergiHabisException e){
		batalPakaiKertas();
		batalPakaiTinta(pesan.length());
		cout<<e.what()<<", segera istirahat"<<endl;
	} catch (TintaKurangException e) {
		batalPakaiKertas();
		cout<<e.what()<<", segera isi tinta"<<endl;
	} catch (KertasHabisException e){
		cout<<e.what()<<", segera isi kertas"<<endl;
	}
}
/*
	Menggunakan 1 kertas.

	Jika kertas tidak cukup, maka metode ini akan melemparkan
	KertasHabisException.
*/
void Sekretaris::pakaiKertas(){
	// kertas--;
	// if(kertas<0){
	// 	throw KertasHabisException();
	// }
	if(kertas>0){
		kertas--;
	}else{
		throw KertasHabisException();
	}
}
/*
	Menggunakan tinta sebanyak num.

	Jika tinta tidak cukup, maka metode ini akan melemparkan
	TintaKurangException.
*/
void Sekretaris::pakaiTinta(int num){
	// tinta-=num;
	// if(tinta<0){
	// 	throw TintaKurangException();
	// }
	if(tinta>=num){
		tinta-=num;
	}else{
		throw TintaKurangException();
	}
}
/*
	Menggunakan 1 energi.

	Jika energi tidak cukup, maka metode ini akan melemparkan
	EnergiHabisException.
*/
void Sekretaris::pakaiEnergi(){
	// energi--;
	// if(energi<0){
	// 	throw EnergiHabisException();
	// }
	if(energi>0){
		energi--;
	}else{
		throw EnergiHabisException();
	}
}
/*
	Membatalkan penggunaan 1 kertas.
*/
void Sekretaris::batalPakaiKertas(){
	kertas++;
}
/*
	Membatalkan penggunaan tinta sebanyak num.
*/
void Sekretaris::batalPakaiTinta(int num){
	tinta+=num;
}
/*
	Membatalkan penggunaan 1 energi.
*/
void Sekretaris::batalPakaiEnergi(){
	energi++;
}
/*
	Menambahkan jumlah tinta sebanyak num.
*/
void Sekretaris::isiTinta(int num){
	tinta+=num;
}
/*
	Menambahkan jumlah kertas sebanyak num.
*/
void Sekretaris::isiKertas(int num){
	kertas+=num;
}
/*
	Istirahat mengembalikan energi menjadi maksimum.
*/
void Sekretaris::istirahat(){
	energi=ENERGI_MAX;
}
/*
	Menampilkan status dari sekretaris. Berikut adalah format tampilan:
	<...> -> tampilkan nilai yang sesuai
	(...) -> komentar, tidak termasuk output

	--------------
	Status
		Energi : <jumlah_energi>
		Tinta : <jumlah_tinta>
		Kertas : <jumlah_kertas>
		Memo : <jumlah_memo>
		(untuk setiap memo ke-i, mulai dari 1)
		Memo [<i>]
			Pesan : <pesan_memo_i>
			Untuk : <untuk_memo_i>
	--------------

	(Output tidak termasuk ---------- di awal dan akhir)
*/
void Sekretaris::printStatus(){
	cout<<"Status"<<endl;
	cout<<"  Energi : "<<energi<<endl;
	cout<<"  Tinta : "<<tinta<<endl;
	cout<<"  Kertas : "<<kertas<<endl;
	cout<<"  Memo : "<<memoLength<<endl;
	for(int i=0;i<memoLength;i++){
		cout<<"    Memo ["<<i+1<<"]"<<endl;
		cout<<"      Pesan : "<<memo[i].getPesan()<<endl;
		cout<<"      Untuk : "<<memo[i].getUntuk()<<endl;
	}
	
}
