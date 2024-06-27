#include<iostream>

using namespace std;

bool check(int a[],int l,int r,int x){
	if(l > r) return false;
	int m = (l+r)/2;
	if(a[m] == x) return true;
	else if(a[m] > x){
		return check(a,l,m-1,x);
	}
	else{
		return check(a,m+1,r,x);
	}
}


float mu(float a,int n){
	if(n == 0) return 1;
	else if(n % 2 == 0) return mu(a,n/2)*mu(a,n/2);
	else return mu(a,n/2)*mu(a,n/2)*a;
}
int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	
	bool c = check(a,0,8,1);
	cout<<c<<endl;
	if(!c) cout<<"khong co";
	else 
	cout<<"co"<<endl;
	
	cout<<mu(2,0)<<endl;
	return 0;
}
