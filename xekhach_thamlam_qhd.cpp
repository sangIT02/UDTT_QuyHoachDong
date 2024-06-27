#include<iostream>
using namespace std;

struct Xekhach{
	string tenxe;
	int sokhach;
	int tienve;
};

int SoChuyenXe(Xekhach xe[],int n,int p,int &tong){
	int dem = 0;
	for(int i = 1;i <= n;i++){
		if(tong <= p){
			tong += xe[i].tienve;
			dem++;
		}
	}
	if(tong <= p) return 0;
	return dem;
}

void MaxTienVe(Xekhach xe[],int n,int m){
	int f[n+1][m+1] ={0};
	for(int i = 0;i <= m;i++){
		f[0][i] = 0;
	}
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			f[i][j] = f[i-1][j];
			if(j >= xe[i].sokhach){
				f[i][j] = max(f[i][j],f[i-1][j - xe[i].sokhach] + xe[i].tienve);			
			}
		}
	}
	
	int i = n, j = m;
	int maxrs = f[n][m];
	if(maxrs <= 0) cout<<"Khong co chuyen xe nao thoa man"<<endl;
	else
	cout<<"Tong tien ve thu duoc lon nhat la: "<<maxrs<<endl;
	cout<<"cac chuyen xe "<<endl;
	while(i != 0){
		if(f[i][j] != f[i-1][j]){
			cout<<i<<" ";
			j -= xe[i].sokhach;
		}
		i--;
	}
}
int main(){
	int n = 8;
	Xekhach xe[n+1] = {{"",0,0}, 
 					  {"xe01",5,8},	
 					  {"xe02",6,7},	
 					  {"xe03",1,6},	
 					  {"xe04",4,5},	
 					  {"xe05",3,4},	
 					  {"xe06",2,3},	
 					  {"xe07",4,2},	
 					  {"xe08",5,1}
					   };
    int m = 10;
    int p = 0;
    int soxe = SoChuyenXe(xe,n,m,p);
    if(soxe == 0) cout<<"Khong co xe nao thoa man"<<endl;
    else{
    	cout<<"so luong xe it nhat sao cho tong tien lon hon "<<m<<" la: "<<soxe<<endl;
    	cout<<"so tien lon nhat la: "<<p<<endl;
	}
	int k = 2;
	MaxTienVe(xe,n+1,k);
	return 0;
}
