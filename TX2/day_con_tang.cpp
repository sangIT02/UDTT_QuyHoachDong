#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <algorithm>  // Thu vi?n ch?a std::reverse

using namespace std;


void daycontang(int a[],int l[],int n,int t[]){
	a[0] = INT_MIN;
	a[n+1] = INT_MAX;
	l[n+1] = 1;
	for(int i = n;i >= 0;i--){
			int jmax = n+1;
		for(int j = i+1;j <= n;j++){
			if(a[j] > a[i] && l[j] > l[jmax]){
				jmax = j;
			}
		}
		l[i] = l[jmax] + 1;
		t[i] = jmax;
	}
}

void truyvet(int a[],int t[],int n){
	 int k = t[0];
	 while(k != n+1){
	 	cout<<a[k]<<" ";
	 	k = t[k];
	 }
}
void showresult(){
	
}
int main(){
	int n;cin>>n;
	int a[n+1];
	int t[n];
	
	for(int i = 1;i <= n;i++)
	cin>>a[i];
	
	int l[n+1];
	daycontang(a,l,n,t);
	
	for(int i = 0;i <= n;i++)
	cout<<l[i]<<" ";
	cout<<endl;
	for(int i = 0;i <= n;i++)
	cout<<t[i]<<" ";
	cout<<endl;

	truyvet(a,t,n);
	return 0;
}
