// Nama/NIM		: Steve Andreas I / 13517039
// Tanggal 		: 4-4-19
// Topik		: Generic


import java.util.*;

public class Utility{
	public static <T> void printList(T[] array){
		int i=0;
		System.out.print("[");
		for(Object o: array){
			if(i==0){
				System.out.print(o);
			}else{
				System.out.print(", "+o);
			}
			i++;
		}
		System.out.println("]");
	}
	
	public static <T extends Number> Double add(T angka1,T angka2){
		return angka1.doubleValue()+angka2.doubleValue();
	}
	
	public static String add(Object obj1,Object obj2){
		return obj1.toString()+obj2.toString();
	}
	
	public static <T extends Number> Double[] add(T[] arr1,T angka2){
		Double[] result=new Double[arr1.length];
		for(int i=0;i<arr1.length;i++){
			result[i]=arr1[i].doubleValue()+angka2.doubleValue();
		}
		return result;
	}
	
	public static <T extends Number> Double[] add(T angka2, T[] arr1){
		Double[] result=new Double[arr1.length];
		for(int i=0;i<arr1.length;i++){
			result[i]=arr1[i].doubleValue()+angka2.doubleValue();
		}
		return result;
	}

	public static <T extends Number> Double[] add(T[] arr1,T[] arr2){
		int a=(arr1.length>arr2.length)?arr1.length:arr2.length;
		Double[] result=new Double[a];
		for(int i=0;i<a;i++){
			if(i<arr1.length && i<arr2.length){
				result[i]=arr1[i].doubleValue()+arr2[i].doubleValue();
			}else{
				if(i<arr1.length){
					result[i]=arr1[i].doubleValue();
				}else{
					result[i]=arr2[i].doubleValue();
				}
			}
		}
		return result;
	}

	// public static <T1,T2 extends Number> String add(T1 obj1,T2 ang2){
	// 	return obj1.toString()+ang2.toString();
	// }
	
	// public static <T1 extends Number,T2> String add(T1 ang1,T2 obj2){
	// 	return ang1.toString()+obj2.toString();
	// }
	

	
	
	public static <T> String[] add(T[] a,T b){
		String[] result=new String[a.length+1];
		for(int i=0;i<a.length;i++){
			result[i]=a[i].toString();
		}
		result[a.length]=b.toString();
		return result;
	}

	public static <T> String[] add(T a,T[] b){
		String[] result=new String[b.length+1];
		result[0]=a.toString();
		for(int i=1;i<b.length+1;i++){
			result[i]=b[i-1].toString();
		}
		return result;
	}

	public static <T> String[] add(T[] a,T[] b){
		String[] result=new String[a.length+b.length];
		for(int i=0;i<a.length;i++){
			result[i]=a[i].toString();
		}
		for(int i=0;i<b.length;i++){
			result[i+a.length]=b[i].toString();
		}
		return result;
	}
	
	public static void main(String args[]){
		Integer[] a ={1,2,3};
		Integer[] b= {1,2};
		Integer f=235;
		String[] c={"1","2","3"};
		String e="asdad";
		String[] d={"c","b","a"};
		Double[] res;
		String[] res2;
		// res2=add(c,a);
		// printList(res2);
		System.out.println(add(1,1));
		System.out.println(add(1,2));
		System.out.println(add("1","1"));
		System.out.println(add("1",2));
		System.out.println(add(2,"3"));
		printList(add(a,b));
		Double[] g={1.0,2.0,3.0};
		printList(add(g,a));
		printList(add(a,1));
		printList(add(a,c));
		printList(add(c,"A"));
		printList(add("A",c));
		printList(add(c,c));
		printList(add(d,c));
		System.out.println(add("hahaha","hihihi"));
	}
	
	
}
