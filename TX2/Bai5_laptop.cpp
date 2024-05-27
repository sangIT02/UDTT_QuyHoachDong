#include<iostream>
using namespace std;

int char_in_string(char t,string p){
	for(int i = 0;i < p.size() ;i++){
		if(p[i] == t)
		return i;
	}
	return -1;
}

int boyer(string t,string p){
	int ts = t.size(), v = p.size(), i = v-1;
	while(i < ts){
		int k = v-1;
		while(t[i] == p[k] && k > -1){
			i--; k--;
		}
		if(k < 0) return i+1;
		else{
			int x = char_in_string(t[i],p);
			if(x < 0) i += v;
			else{
				i = i + v - x - 1;
			}
		}
		
	}
	return -1;
}

int main(){
	string t,p;
	cout<<"Nhap Chuoi 1: "; getline(cin,t);
	cout<<"Nhap Chuoi 2: "; getline(cin,p);
	cout<<"vi tri: "<<boyer(t,p);
	return 0;
}
