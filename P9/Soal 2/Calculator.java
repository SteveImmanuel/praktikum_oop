// Nama/NIM	: Steve Andreas I/13517039
// Tanggal	: 28-3-2019
// Tema		: Inheritance

public class Calculator{
	private Server server;
	public Server getServer(){
		return server;
	}

	public int addNumber(int angka1, int angka2){
        server = new AddServer(angka1);
        int hasil = server.processRequest(angka2);
        
        System.out.println("Server returned "+hasil);
        return hasil;
    }
    
    public int doubleNumber(int angka1){
        server = new AddServer(0);
        int hasil = server.processRequest(angka1);
        
        System.out.println("Server returned "+hasil);
        return hasil;
    }
    
    public int multiplyNumber(int angka1, int angka2){
        server = new MultiplyServer(angka1);
        int hasil = server.processRequest(angka2);
        
        System.out.println("Server returned "+hasil);
        return hasil;
    }
    
    public int squareNumber(int angka1){
        server = new MultiplyServer(0);
        int hasil = server.processRequest(angka1);
        
        System.out.println("Server returned "+hasil);
        return hasil;
    }

}
