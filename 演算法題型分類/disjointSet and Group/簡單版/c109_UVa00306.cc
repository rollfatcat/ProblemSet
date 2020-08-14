/* 給定Ｎ和Ｎ個位置的加密方式，每次查詢時會給Ｋ代表要加密的次數和須要加密的字串，輸出加密後的結果
 * 查詢給定Ｋ後接一個空白，之後部分都屬於須要加密的字串(可能包含空白)且長度不足Ｎ時需要補空白。
 * Ｋ極大無法依據規則做線性加密，解題核心： DisjointSet
 * 將Ｎ個加密位移做查並集，屬於同一群的位移，加密次數會依據該群體成員個數形成循環。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=200+1;
const int MaxK=1e9;
int nxt[MaxN];
int sft[MaxN];
int group[MaxN];
vector<int> cycle[MaxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, K, GI;
	string ss, ans;
	while(cin>>N and N>0){
		for(int i=1;i<=N;i++){
			cin>>nxt[i];
			group[i]=-1;
		}
		int GI=0;
		for(int now=1;now<=N;now++)
			if(group[now]==-1){
				cycle[GI].clear();
				int pvt=now, stp=0;
				while(group[pvt]==-1){
					cycle[GI].push_back(pvt);
					group[pvt]=GI;
					sft[pvt]=stp++;
					pvt=nxt[pvt];
				}
				GI++;
			}
		while(cin>>K and K>0){
			getline(cin,ss);
			for(int i=ss.length();i<=N;i++)
				ss+=" ";
			ans=ss;
			for(int i=1;i<=N;i++){
				GI=group[i];
				ans[ cycle[GI][(K+sft[i])%cycle[GI].size()] ]=ss[i];
			}
			for(int i=1;i<=N;i++)
				cout<<ans[i];
			cout<<'\n';
		}
		cout<<'\n';
	}
}