/* 給定Ｎ棟高樓，輸出每棟高樓可以看到的其他高樓數量總和？
 *      高樓Ａ可以看到高樓Ｂ的條件：高樓Ａ和Ｂ之間其他的高樓都不超過高樓Ａ和Ｂ
 *      min(h[A],h[B]) ≥ max(h[A+1],h[A+2], ..., h[B-1])
 * 解題關鍵：monotonic stack(單調棧) ... 非嚴格遞減
 * 高樓Ａ可以看到高樓Ｂ時＝彼此可以互相看到(由左而右掃描時計算的次數＝右到左)
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxH=1e9;
int main(){
	int N, hgt;
 
	while(scanf("%d",&N)!=EOF){
		long ans=0;
		stack<int> Sh; // 紀錄高樓的高度
		stack<int> Sn; // 紀錄高樓的數量
		for(int i=0;i<N;i+=1){
			scanf("%d",&hgt);
			// 維護非嚴格遞減(將相同高度合併處理)
            // 該棟高樓右側的其他大樓無法看到低於該高樓左側的部分
            while(Sh.empty()==0 and Sh.top()<hgt){
				ans+= Sn.top();
				Sh.pop();
				Sn.pop();
			}
            // 維護的高度是嚴格遞減，所以討論是否要併入數量
            // (若存在)高於目前高樓的部分只能看到１棟但是一樣高時可以看到全部
			if(Sn.empty()==0 and Sh.top()==hgt){
				ans+=Sn.top();
				Sn.top()++;
                ans+= Sn.size()>1; // 除了目前高度還存在更高的高樓
			}else{
                ans+= Sn.empty()==0;
				Sh.push(hgt);
				Sn.push(1);
			}
		}
		printf("%ld\n",ans<<1);
	}
}