//	Nama/NIM	: Steve Andreas I
// 	Tanggal		: 21-03-2019
//	Topik		: Kelas

import java.util.Scanner;

public class LabKomputer{
	private String name;
	private Komputer[][] matriksKomputer;
	private final int nBaris;
	private final int nKolom;
	
	public LabKomputer(){
		name="namaLab";
		nBaris=5;
		nKolom=5;
		matriksKomputer=new Komputer[nBaris][nKolom];
		for(int i=0;i<nBaris;i++){
			for(int j=0;j<nKolom;j++){
				matriksKomputer[i][j]=null;
			}
		}
	}
	public LabKomputer(String namaLab,int nbar,int nkol){
		name=namaLab;
		nBaris=nbar;
		nKolom=nkol;
		matriksKomputer=new Komputer[nBaris][nKolom];
		for(int i=0;i<nBaris;i++){
			for(int j=0;j<nKolom;j++){
				matriksKomputer[i][j]=null;
			}
		}
	}
	public LabKomputer copyLab(){
		LabKomputer res=new LabKomputer(name,nBaris,nKolom);
		for(int i=0;i<nBaris;i++){
			for(int j=0;j<nKolom;j++){
				if(matriksKomputer[i][j]!=null){
					res.matriksKomputer[i][j]=new Komputer(matriksKomputer[i][j].getIdKomputer());
					if(matriksKomputer[i][j].isTurnedOn()){
						res.matriksKomputer[i][j].turnOn();
					}
				}
			}
		}
		return res;
	}
	public void addKomputer(int id,int b,int k){
		if(b<nBaris&&k<nKolom&&b>=0&&k>=0){
			if(matriksKomputer[b][k]==null){
				matriksKomputer[b][k]=new Komputer(id);
			}
		}
	}
	public void removeKomputer(int b,int k){
		if(b<nBaris&&k<nKolom&&b>=0&&k>=0){
			matriksKomputer[b][k]=null;
		}
	}
	public Komputer getKomputer(int b,int k){
		if(b<nBaris&&k<nKolom&&b>=0&&k>=0){
			return matriksKomputer[b][k];
		}else{
			return null;
		}
	}
	public Boolean isKomputerExist(int n){
		Boolean found=false;
		int i=0;
		int j=0;
		while(i<nBaris&&!found){
			j=0;
			while(j<nKolom&&!found){
				if(matriksKomputer[i][j]!=null){
					if(matriksKomputer[i][j].getIdKomputer()==n){
						found=true;
					}else{
						j++;
					}
				}else{
					j++;
				}
			}
			i++;
		}
		return found;
	}
	public void printLab(){
		System.out.println(name);
		for(int i=0;i<nBaris;i++){
			for(int j=0;j<nKolom;j++){
				if(j!=0){
					System.out.print(" ");
				}
				if(matriksKomputer[i][j]==null){
					System.out.print("x");
				}else if(matriksKomputer[i][j].isTurnedOn()){
					System.out.print(matriksKomputer[i][j].getIdKomputer());
				}else if(!matriksKomputer[i][j].isTurnedOn()){
					System.out.print(0);
				}
			}
			System.out.println();
		}
	}
	
	public String getName(){
		return name;
	}
	public void setName(String newname){
		name=newname;
	}
	public int getNBaris(){
		return nBaris;
	}
	public int getNKolom(){
		return nKolom;
	}
	public Komputer[][] getMatriksKomputer(){
		return matriksKomputer;
	}
	
	public static void main(String[] args){
		LabKomputer L1=new LabKomputer("abrakadabra",5,7);
		L1.addKomputer(2,4,6);
		L1.getMatriksKomputer()[4][6].turnOn();
		
		System.out.println(L1.isKomputerExist(2));
		LabKomputer L2=L1.copyLab();
		L2.setName("ini kedua");
		L2.addKomputer(5,0,0);
		L2.addKomputer(1,5,5);
		L2.printLab();
		L1.printLab();
		System.out.println(L2.isKomputerExist(5));
		
		L2.removeKomputer(0,0);
		L2.printLab();
		
		System.out.println(L2.isKomputerExist(5));
		
	}
	
} 
