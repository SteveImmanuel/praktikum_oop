// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class AddServer implements Server{
	private final int constant;
	private static int numAddServerCreated=0;
	public AddServer(){
		this.constant=0;
		this.numAddServerCreated++;
	}
	public AddServer(int c){
		this.constant=c;
		this.numAddServerCreated++;
	}
	public int processRequest(int request){
		int hasil;
        
        System.out.print("Server "+numAddServerCreated+" execute ");
        
        if(constant<=0){
            System.out.print(request+" ");
            hasil = request+request;
        }else{
            System.out.print(constant+" ");
            hasil = constant + request;
        }
        
        if(request>=0){
            System.out.println("+ "+request);
        }else{
            System.out.println("- "+request*-1);
        }
        
        return hasil;
	}	
}