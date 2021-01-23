/* 給定Ｎ位顧客抵達港口時間和願意支付的費用(不依照時間順序)，船家傾向讓付費最多的顧客優先上船，試問船家可以賺的錢？
 * 船隻從時刻Ｔ1到Ｔ2之間固定每Ｋ單位時間會從港口出發，最多搭載Ｐ位乘員。
 * 解題關鍵：優先佇列( PriorityQueue )
 * 依照時間順序模擬顧客抵達港口時間，並在發船時讓付費最高的前Ｐ位顧客上船，沒上船的乘客可以延續到下個班次
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxT=1e4;
const int MaxP=1e2;
const int MaxN=1e5;
struct DATA{
	int t, m;
	bool operator<(const DATA &rhs)const{ return m<rhs.m; }
} data[MaxN];
 
bool compare(DATA a,DATA b){ return a.t<b.t; }
int main(){
	int T1, T2, K, P, N;
	// input
	scanf("%d %d %d %d\n",&T1,&T2,&K,&P);
	for(N=0; scanf("%d %d\n",&data[N].t,&data[N].m)!=EOF; N++);
	//
	sort(data,data+N,compare);
	priority_queue<DATA> PQ;
	int idx=0, ans_m=0, ans_p=0;
	for(int t=T1;t<=T2;t+=K){
		for(; idx<N and data[idx].t<=t; idx++)
			PQ.push(data[idx]);
		for(int p=0; PQ.empty()==0 and p<P; p++,PQ.pop())
			ans_m+=PQ.top().m,
			ans_p+=1;
	}
	printf("%d %d\n",ans_p,ans_m);
}