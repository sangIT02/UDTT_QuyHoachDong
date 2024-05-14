#include<iostream>

using namespace std;



int main(){
	int n;
	cin>>n;
	int a[n];
	int l[n] = {1};
	int t[n];
	for(int i = 0;i < n;i++)
	cin>>a[i];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < i;j++){
			if(a[i] > a[j]){
				if(l[i] < l[j] + 1){
					l[i] = l[j] + 1;
					t[i] = j;
				}
			}
		}
	
	}
	int k = t[1];
	cout<<"Day Con: ";
	while(k != n){
		cout<<a[k]<<" ";
		k = t[k];
	}
	return 0;
}
	
