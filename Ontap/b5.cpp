#include<iostream>
using namespace std;

struct Laptop{
	string tenhang;
	string cauhinh;
	float giaban;
};

int char_in_string(char t,string p){
	for(int i = 0;i < p.size();i++){
		if(t == p[i]){
			return i;
		}
	}
	return -1;
}
int boyer_moore(string t,string p){
	int v = p.size(), i = v - 1;
	while(i < t.size()){
		int k = v-1;
		while(p[k] == t[i] && k > -1){
			i--;
			k--;
		}
		if(k < 0) return i+1;
		else{
			int x = char_in_string(t[i],p);
			if(x < 0) i += v;
			else i = i + v - x - 1;
		}
	}
	return -1;
}

int SLlaptop(Laptop l[],Laptop kq[],int n,string s){
	int dem = 0;
	for(int i = 0;i < n;i++){
		if(boyer_moore(l[i].cauhinh,s) != -1){
			kq[dem++] = l[i];
		}
	}
	return dem;
}
int main(){
	int n = 4;
	Laptop l[n] = { {" HP","CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB",15000000},
					{" Asus","CPU 2.5GHz upto 3.5GHz-RAM 32GB-SSD 512GB",18000000},
					{" DELL","CPU 2.5GHz upto 4.0GHz-RAM 16GB-SSD 512GB",20000000},
					{" Lenovo","CPU 2.5GHz upto 3.5GHz-RAM 8GB-SSD 512GB",10000000},
	};
	Laptop kq[n];
	
	int dem = SLlaptop(l,kq,n,"RAM 16GB");
	if(dem != 0){
		cout<<"So luong laptop co cau hinh 16GB RAM la: "<<dem<<endl;
		for(int i = 0;i < dem;i++){
			cout<<kq[i].tenhang<<" - "<<kq[i].cauhinh<<" - "<<kq[i].giaban<<endl;
		}
	}
	return 0;
}