/* 給定可以分配的工作時間Ｔ，以及Ｎ個工作名稱、完成時的報酬和耗費時間，輸出可以獲得的最大報酬和收益比最高的工作名稱？
 * 工作必須完成後才能獲得報酬且工作只能完成一次，收益比最高的工作有若干個相同時以輸入順序優先的為答案。
 * 解題關鍵：01背包問題，注意狀態轉移時的更新判斷
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxT=1e5;
const int MaxN=1e4;
 
int dpt[MaxT+1]={}; // dpt[h]=v ，時間總量ｈ時可獲得的最大報酬ｖ
int opt[MaxT+1]={}; // opt[h]=ID，時間總量ｈ時收益比最高的工作ID
string ss[MaxN+1];
double D[MaxN+1];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int T, N, M, H, ID;
	cin>>T>>N;
	for(int Nid=1; Nid<=N; Nid++){
		cin>>ss[Nid]>>M>>H;
		D[Nid]=(double)M/H;
        /* 狀態轉移時，需要根據 dpt[h-Hi]+Mi 相等或是大於 分開討論
         * 相等時，opt[h] 考慮目前工作ID、opt[h-Hi]紀錄的工作ID、opt[h]本身紀錄的 
         * 大於時，opt[h] 考慮目前工作ID、opt[h-Hi]紀錄的工作ID
         * 考慮＝先比收益比高的，收益比相等時看 ID 小的
         */
		for(int h=T; h>=H; h--){
			if(dpt[h]==dpt[h-H]+M){
				ID=( D[Nid]>D[opt[h-H]] )? Nid: opt[h-H];
				if( D[ID]>D[opt[h]] or D[ID]==D[opt[h]] and ID<opt[h])
					opt[h]=ID;
			}
			if(dpt[h]<dpt[h-H]+M){
				dpt[h]=dpt[h-H]+M;
				opt[h]=(D[Nid]>D[opt[h-H]])? Nid: opt[h-H];
			}
		}
	}
	cout<<dpt[T]<<'\n'<<ss[opt[T]]<<'\n';
}