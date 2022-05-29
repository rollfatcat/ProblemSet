/* 給定Ｎ個字串和Ｍ次的查詢，將Ｎ個字串串在一起後每次查詢時輸出對應位置的字母？
 * 題目盲點：無法直接模擬字串串接(記憶體限制的關係)
 * 解題關鍵：prefixsum + binary_search
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxM=1e2;
string ss[MaxN];
int prS[MaxN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, v, tag;
	while(cin>>N>>M and N>0){
		cin>>ss[0];
		prS[0]=ss[0].length();
		for(int i=1;i<N;i++){
			cin>>ss[i];
			prS[i]=prS[i-1]+ss[i].length();
		}
		while(M-->0){
			cin>>v;
			tag=lower_bound(prS,prS+N,v)-prS;
			if(tag) v-=prS[tag-1] ;
			cout<<ss[tag][v-1];
		}
		cout<<'\n';
	}
}