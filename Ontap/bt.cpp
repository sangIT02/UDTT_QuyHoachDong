#include<iostream>
using namespace std;


int f[50][50];
void LayGoi(int m,int n, int w[],int v[]){
	for(int j = 0;j <= m;j++){
		f[0][j] = 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= m;j++){
			f[i][j] = f[i-1][j];
			if(w[i] <= j){
				int tm = v[i] + f[i-1][j-w[i]];
				if(f[i][j] < tm){
					f[i][j] = tm;
				}
			}
		}
	}
}
void TruyVet(int m,int n,int w[]){
	cout<<"Max value: "<<f[n][m]<<endl;
	int i = n, j = m;
	while(i !=  0){
		if(f[i][j] != f[i-1][j]){
			cout<<i<<" ";
			j = j - w[i];
		} 
		i--;
	}
}

int main(){
	int m,n;cin>>n>>m;
	int w[n]  ={0,1,2,3}; //{2,1,4,3};
	int v[n]  = {0,4,5,6};//{3,3,4,2};
//	for(int i = 1;i <=n;i++)
//	cin>>w[i];
//	for(int i = 1;i <= n;i++)
//	cin>>v[i];
	LayGoi(m,n,w,v);
	//TruyVet(m,n,w);
	cout<<f[n][m]<<"\n";
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			cout<<f[i][j]<<" ";
	}
	cout<<endl;
	}
	
	return 0;
}