// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class MultiplyServer implements Server{
	private final int constant;
	private static int numMultiplyServerCreated=0;
	public MultiplyServer(){
		this.constant=0;
		this.numMultiplyServerCreated++;
	}
	public MultiplyServer(int c){
		this.constant=c;
		this.numMultiplyServerCreated++;
	}
	public int processRequest(int x){
		int request=x;
		if(this.constant<=0){
			System.out.println("Server "+this.numMultiplyServerCreated+" execute "+request+" * "+request);	
			request*=request;
		}else{
			System.out.println("Server "+this.numMultiplyServerCreated+" execute "+this.constant+" * "+request);
			request*=this.constant;
		}
		return request;
	}	
}
