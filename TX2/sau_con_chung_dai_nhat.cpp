#include<iostream>
#include<string.>
#include<algorithm>

using namespace std;


int dp[100][100];
int sauchung(string a,string b){
	
	for(int i = 0;i <= a.size();i++)
	dp[i][0] = 0;
	for(int i = 0;i <= b.size();i++)
	dp[0][i] = 0;
	for(int i = 1;i <= a.size();i++){
		for(int j = 1; j <= b.size();j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[a.size()][b.size()];
}

void truyvet(string a,string b){
	int i = a.size(), j = b.size(),k = 0;
	string xc = "";
	while(dp[i][j] != 0){
		if(a[i-1] == b[j-1]){
			xc += a[i-1];
			k++;i--;j--;
		}
		else{
			if(dp[i-1][j] >= dp[i][j-1]) i--;
			else j--;
		}
		
	}
 	reverse(xc.begin(),xc.end());
	cout<<xc<<endl;
}
int main(){
	string s1;
	string s2;
	cout<<"nhap chuoi 1: ";getline(cin,s1);
	cout<<"nhap chuoi 2: ";getline(cin,s2);
	int dem = sauchung(s1,s2);
	cout<<dem<<endl;
	truyvet(s1,s2);

	for(int i = 0;i <= s1.size();i++){
		for(int j = 0;j <= s2.size();j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

