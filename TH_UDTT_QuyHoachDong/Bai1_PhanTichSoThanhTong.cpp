#include<iostream>
using namespace std;

int f[50][50];

int PhanTich(int m,int n){
	f[0][0] = 1;
	for(int i = 1;i <= m;i++){
		for(int j = 0;j <= n;j++){
			if(i > j){
				f[i][j] = f[i-1][j];	
			}
			else{
				f[i][j] = f[i-1][j] + f[i][j-i];
			}
		}
	}
	return f[m][n];
}

int main(){
	int m,n;
	cin>>m>>n;
	cout<<"So Cach Phan Tich La: "<<PhanTich(m,n);
	 return 0;
}