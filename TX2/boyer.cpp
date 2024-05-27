#include<iostream>
#include<string>
using namespace std;

// boyer_moore
int char_in_string(char t,string p){
	for(int i = 0;i < p.size();i++){
		if(t == p[i]){
			return i;
		}
	}
	return -1;
}
int boyer_moore(string p,string t){
	int v = p.size(), i = v - 1;
	while(i < t.size()){
		int k = v-1;
		while(t[i] == p[k] && k > -1){
			i--;k--;
		}
		if(k < 0){
			return i+1;
		}
		else{
			int x = char_in_string(t[i],p);
			if(x < 0) i += v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}
bool check(int i,int j,string t,string p){
	while(t[i] == p[j] && j < p.size()){
		i++;
		j++;
	}
	if(j == p.size()){
		return true;
	}
	return false;
}
int main(){
	string t,p;
	cout<<"chuoi 1:"; getline(cin,t);
	cout<<"chuoi 2:"; getline(cin,p);
//	for(int i = 0;i < t.size() ;i++){
//		if(check(i,0,t,p)){
//			cout<<p<<" la sau con cua "<<t;
//			cout<<"\n"<<i;
//			break;
//		}
//	}
//	cout<<p<<" Khong la sau con cua "<<t;
	
	cout<<boyer_moore(p,t);
	
	return 0;
}
