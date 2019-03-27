//	Nama/NIM	: Steve Andreas I
// 	Tanggal		: 21-03-2019
//	Topik		: Kelas

import java.util.Scanner;

public class Komputer{
	private int idKomputer;
	private Boolean turnedOn;
	
	public Komputer(int id){
		idKomputer=id;
		turnedOn=false;
	}
	public void turnOn(){
		turnedOn=true;
	}
	public void turnOff(){
		turnedOn=false;
	}
	public Boolean isTurnedOn(){
		return turnedOn;
	}
	public int getIdKomputer(){
		return idKomputer;
	}
	public void setIdKomputer(int id){
		idKomputer=id;
	}
} 
