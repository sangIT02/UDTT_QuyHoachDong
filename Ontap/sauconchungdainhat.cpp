#include<iostream>
#include<algorithm>
using namespace std;

//int f[100][100];
int LengSauCon(string a,string b,int n,int m,int f[][100]){
	for(int i = 0;i <= n;i++) f[i][0] = 0;
	for(int i = 0;i <= m;i++) f[0][i] = 0;
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m ;j++){
			if(a[i-1] == b[j-1]){
				f[i][j] = f[i-1][j-1] +1;
			}
			else{
				f[i][j] = max(f[i-1][j],f[i][j-1]);
			}
		}
	}
	return f[n][m];
}

void truyvet(string a,string b,int i,int j,int f[][100]){
	string xc = "";
	while(f[i][j] != 0){
		if(a[i-1] == b[j-1]){
			xc += a[i-1];
			j--;i--;
		}
		else{
			if(f[i-1][j] > f[i][j-1] ) i--;
			else j--;
		}
	}
	reverse(xc.begin(),xc.end());
	cout<<xc;
}
int main(){
	string a,b;
	cout<<"Nhap chuoi 1: "; getline(cin,a);
	cout<<"Nhap chuoi 2: "; getline(cin,b);
	int n = a.size(), m = b.size();
	int f[100][100];
	int lengthxc = LengSauCon(a,b,n,m,f);
	truyvet(a,b,n,m,f);
	return 0;
}