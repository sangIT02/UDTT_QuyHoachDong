#include<iostream>
using namespace std;

void caitui(int n,int m,int w[],int v[],int f[][100]){
	for(int i = 0;i <= m;i++) f[0][i] = 0;	
	
	for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
			f[i][i] = f[i-1][j];
			if(j >= w[i]){
				f[i][j] = max(f[i][j],f[i-1][j-w[i]] + v[i]);
			}
		}
	}
}

void truyvet(int n,int m,int w[],int f[][100]){
	cout<<"max value: "<<f[n][m]<<endl;
	int i = n, j = m;
	while( i != 0){
		if(f[i][i] != f[i-1][j]){
			cout<<i<<" ";
			j = j - w[i];
		}
		i--;
	}
}
int main(){
	int n,m;
	cout<<"nhap so luong hang: ";cin>>n;
	cout<<"nhap khoi luong: ";cin>>m;
	int w[n] = {0,2,1,4,3};
	int v[n] = {0,3,3,4,2};
	int f[100][100];
	caitui(n,m,w,v,f);
	truyvet(n,m,w,f);
		for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			cout<<f[i][j]<<" ";
	}
	cout<<endl;
	}
	return 0;
}