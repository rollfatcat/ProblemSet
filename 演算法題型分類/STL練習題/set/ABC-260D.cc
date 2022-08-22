/* 給定Ｎ張堆放面朝下的牌(點數１到Ｎ各出現一次)，(若存在)翻正的牌中大於等於Ｘ的最小點數疊在該牌上面
 * 牌堆疊滿Ｋ張時可以將整疊牌移除並標記每張牌在什麼時候移除的，輸出每個號碼的牌移除的時間(沒移除輸出-1)
 * 解題關鍵：在線查詢-關聯性容器，搜尋翻正的牌中點數大於等於Ｘ的牌堆編號
 * 移除牌堆時要把整堆牌的編號標記為第ｎ次翻正，所以需要紀錄每堆牌中有哪些牌
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxK=2e5;
int pos[MaxN+1];
int ans[MaxN+1]={};
vector<int> up[MaxK];
int main(){
	int N, K, v, tag, pile;
	int size=0;
	set<int> pool;
	set<int>:: iterator it;
	fill(ans,ans+1+MaxN,-1);
	
	cin>>N>>K;
	for(int n=1; n<=N; n++){
		cin>>v;
		if( pool.empty() or (*pool.rbegin())<v ){
			pos[v]=pile=size;
			size++;
		}else{
			tag=*pool.lower_bound(v);
			pool.erase(tag);
			pos[v]=pile=pos[tag];
		}
		pool.insert(v);
		up[pile].push_back(v);
		if( up[pile].size()==K ){
			for(int v: up[pile])
				ans[v]=n;
			pool.erase(v);
		}
	}
	for(int n=1; n<=N; n++)
		cout<<ans[n]<<'\n';
}