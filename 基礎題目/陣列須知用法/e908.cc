/* 給定今天星期幾和Ｎ(1≦Ｎ≦ 2147483647)，問Ｎ天後是星期幾？ 
 */
#include<bits/stdc++.h>
using namespace std;

string days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
inline int StrToDay(string ss){
	for(int i=0;i<7;i++)
		if(ss==days[i])
			return i;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string now_day; int sft;
	while(cin>>now_day>>sft)
		cout<<days[ (sft%7+StrToDay(now_day))%7 ]<<'\n';
}