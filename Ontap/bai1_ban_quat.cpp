#include<iostream>
using namespace std;

struct Quat{
	string hangsx;
	string mausac;
	float giaban;
};

int SoLuongQuat(Quat q[],int n, Quat sl[],float tien){

	int dem = 0;
	int i = 0;
	while(tien >= q[i].giaban && i < n){
		sl[dem++] = q[i];
		tien -= q[i].giaban;
		i++;
	}
	return dem;
}


int main(){
	float tien;
	cout<<"Nhap So Tien: ";cin>>tien;

	int n = 6;
	Quat sl[n];
	Quat q[n] = { {"Hang1","den",10000},
				{"Hang2","trang",20000},
				{"Hang3","do",30000},
				{"Hang4","xanh",40000},
				{"Hang5","vang",50000},
				{"Hang6","tim",60000}

	};

	int dem = SoLuongQuat(q,n,sl,tien);

	if(dem > 0){
		cout<<"So Luong Quat ban la: "<<dem<<endl;
		for(int i = 0;i < dem;i++){
			cout<<sl[i].hangsx<<" - "<<sl[i].mausac<<" - "<<sl[i].giaban<<endl;
		}
	}
	else
	cout<<"Khong mua duoc chiec quat nao";
	return 0;
	
}