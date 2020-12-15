/* 每行給定加密後位移的下個位置(題目沒有給Ｎ但保證Ｎ不超過1000)，輸出最小加密幾次後會變回明文？
 * 解題關鍵：One-Cycle Partite＋LCM
 * 答案＝所有長度週期的最小公倍數
 * (70ms) 枚舉答案和現在長度的 LCM，依序掃描一遍。
 * (10ms) 取所有長度質因數最高次方的乘積
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
int pos[MaxN];
bool vis[MaxN];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N=0, v;
	while(cin>>pos[0]){
		/* 根據格式讀取，直到抓取的下個字元不是空白，代表這筆測資結束 */
    for(N=1;cin.get()==' ';N++)
			cin>>pos[N];
		fill(vis,vis+N,0);
    /* 枚舉每一群的長度和現在的答案取 LCM (70ms)
     * 加速：除法本身會消耗時間，取所有長度質因數最高次方的乘積(10ms)
     */
		long ans=1, len;
		for(int pvt=0; pvt<N; pvt++)
			if(vis[pvt]==0){
				vis[pvt]=len=1;
				for(int nxt=pos[pvt]; nxt!=pvt; nxt=pos[nxt],len+=1)
					vis[nxt]=1;
				ans=len*ans/__gcd(len,ans);
			}
		cout<<ans<<'\n';
	}
}