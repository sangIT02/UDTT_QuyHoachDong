#include<iostream>
using namespace std;

struct HoiThao{
	string chude;
	float time_begin;
	float time_end;
};

int SLHoiThao(HoiThao ht[],HoiThao kq[],int n){
	int dem = 0;
	float last_time = 0;
	for(int i = 0;i < n;i++){
		if(last_time <= ht[i].time_begin){
			last_time = ht[i].time_end;
			kq[dem++] = ht[i];
		}
	}
	return dem;
}

int main(){
	int n = 5;
	HoiThao ht[5] = { {"ki nang song",0,3},
					{"tim viec lam",2,4},
					{"ban hang online",5,6},
					{"live stream",5.5,7},
					{"nang cao ki nang",8,9}
					
	};
	HoiThao kq[5];
	int dem = SLHoiThao(ht,kq,n);

		cout<<"So Luong hoi thao nhieu nhat ma 1 nguoi co the tham gia la: "<<dem<<endl;
		for(int i = 0;i < dem;i++){
			cout<<kq[i].chude<<" - "<<kq[i].time_begin<<" - "<<kq[i].time_end<<endl;
		}
	
	return 0;
}