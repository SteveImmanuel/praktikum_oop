//	Nama/NIM	: Steve Andreas I
// 	Tanggal		: 21-03-2019
//	Topik		: Kelas

public class Matriks{
	private int n;
	private int m;
	private int[][] data;
	
	public Matriks(){
		n=0;
		m=0;
		data=new int[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				data[i][j]=0;
			}
		}
	}
	public Matriks(int _n,int _m){
		n=_n;
		m=_m;
		data=new int[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				data[i][j]=0;
			}
		}
	}
	public int getBrs(){
		return n;
	}
	public int getKol(){
		return m;		
	}
	public int getData(int x,int y){
		return data[x][y];		
	}
	public void setData(int x,int y,int z){
		data[x][y]=z;
	}
	public Boolean isEqSize(Matriks M){
		return M.getBrs()==n&&M.getKol()==m;
	}
	public Matriks tambah(Matriks M){
		int newbrs=(n>M.n)?n:M.n;
		int newkol=(m>M.m)?m:M.m;
		Matriks res=new Matriks(newbrs,newkol);
		for(int i=0;i<newbrs;i++){
			for(int j=0;j<newkol;j++){
				if(i<n&&j<m){
					if(i<M.n&&j<M.m){
						res.data[i][j]=data[i][j]+M.data[i][j];
					}else{
						res.data[i][j]=data[i][j];
					}
				}else{
					if (i<M.n && j<M.m){
						res.data[i][j]=M.data[i][j];
					}
				}
			}
		}
		return res;
	}
	public Matriks kurang(Matriks M){
		int newbrs=(n>M.n)?n:M.n;
		int newkol=(m>M.m)?m:M.m;

		Matriks res=new Matriks(newbrs,newkol);
		for(int i=0;i<newbrs;i++){
			for(int j=0;j<newkol;j++){
				if(i<n&&j<m){
					if(i<M.n&&j<M.m){
						res.data[i][j]=data[i][j]-M.data[i][j];
					}else{
						res.data[i][j]=data[i][j];
					}
				}else{
					if (i<M.n && j<M.m){
						res.data[i][j]=M.data[i][j];
					}
				}
			}
		}
		return res;
	}
	public Matriks kali(int x){
		Matriks res=new Matriks(n,m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				res.data[i][j]=data[i][j]*x;
			}
		}		
		return res;
	}
	public Boolean isSimetri(){
		return n==m;
	}
	
} 
