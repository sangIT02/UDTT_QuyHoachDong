#include<iostream>

using namespace std;

struct HoiThao{
	string chude;
	float time_begin;
	float time_end;
};

int SoHoiThao(HoiThao ht[],HoiThao tg[],int n){
	int dem = 0 ;
	float last_time = 0;
	
	for(int i = 0;i < n;i++){
		if(ht[i].time_begin >= last_time){
			last_time = ht[i].time_end;
			tg[dem++] = ht[i];
		}
	}
	return dem;
}

int main(){
	HoiThao ht[5] = { {"tim kiem viec lam",0,3}, 
				  	  {"Nang cao ki nang",2,4.5}, 
					  {"hoc hoi lam giau",5,6}, 
					  {" trao doi thong tin",5.5, 6.6}, 
 					  {"doi moi cong nghe",9 ,10}};
	HoiThao kq[5];
	int dem = SoHoiThao(ht,kq,5);
	cout<<"So Hoi Thao 1 Nguoi Co Them Tham Gia La: "<<dem<<endl;
	for(int i = 0;i < dem;i++){
		cout<<kq[i].chude<<" - "<<kq[i].time_begin<<" - "<<kq[i].time_end<<endl;
		
	}
	return 0;
}
