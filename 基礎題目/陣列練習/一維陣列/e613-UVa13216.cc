/* 給定66的Ｎ次方問最後兩位數(模100)
 * Ｎ＝(0,1e1000)
 * (v) 直覺：規律觀察, 每次乘上66後取餘數100並觀測是否有出現循環
 *     66^1=66   66^2=56   66^3=96  66^4=36   66^5=76   66^6=16 
 *               66^7=56   ...
 * (v) 若不存在規律時則取快速幂次法(大數除法)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=5e3;
const int MaxL=1e3;

int cycle[10]={76,16,56,96,36,76,16,56,96,36};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseT;
	string num;
	cin>>caseT;
	while(caseT--){
		cin>>num;
		if(num=="0") cout<<"1"<<'\n';
		else if(num=="1") cout<<"66"<<'\n';
		else cout<<cycle[num[num.length()-1]-'0']<<'\n';
	}
}