/* 戰前有Ｎ位士兵和戰後Ｍ位士兵回報，但士兵回報時會存在重複登錄的情況，輸出準確的存活率和個階級、軍種人數？
 * 名字、軍種、職階都相同時視為同一位士兵重複登錄
 * 解題關鍵：set
 * 當名字不存在登錄名單內時代表這是第一次登錄＝登錄成功，否則這次登錄視為無效
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxM=1e6;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N, M, a, b, v;
	cin>>N>>M;
	set<string> memo[9];
	string name;
	int ans_n=0;
	int ans_c[2][3]={};
	while(M-->0){
		cin>>name>>a>>b;
		v=3*(a-1)+b-1;
		if(memo[v].find(name)!=memo[v].end()) continue;
		ans_n+= 1;
		ans_c[0][a-1]+= 1;
		ans_c[1][b-1]+= 1;
		memo[v].insert(name);
	}
	cout<<"navy:"<<ans_c[0][0]<<" army:"<<ans_c[0][1]<<" air:"<<ans_c[0][2]<<'\n';
	cout<<"officer:"<<ans_c[1][0]<<" sergeant:"<<ans_c[1][1]<<" soldier:"<<ans_c[1][2]<<'\n';
	cout<<"survival rate: "<<fixed<<setprecision(1)<<(100.0*ans_n/N)<<"%\n";
}