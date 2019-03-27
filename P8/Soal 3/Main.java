//	Nama/NIM	: Steve Andreas I
// 	Tanggal		: 21-03-2019
//	Topik		: Kelas

import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		System.out.println("----- section 1 -----");
		System.out.println("Number of objects created so far: "+A.getNumOfACreated());
		System.out.println();
		System.out.println("----- section 2 -----");
		A a1=new A();
		A a2=a1.copy();
		A a3=new A(10,5);
		A a4=a3.copy();
		A a5=new A(5,10);
		a5.print();
		a3.print();
		a1.print();
		System.out.println("Number of objects created so far: "+A.getNumOfACreated());
		System.out.println();
		System.out.println("----- section 3 -----");
		A[] arr=new A[100];
		for(int i=0;i<100;i++){
			arr[i]=new A(2*i,(int)Math.pow(i,2));
		}
		System.out.println("Number of objects created so far: "+A.getNumOfACreated());
		System.out.println("----- FIN -----");
	}
}

