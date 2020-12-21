/* 給定Ｎ個商品的收益和保存期限，每天只能售出一樣商品，輸出如何安排順序可收取最大化收益？
 * 解題關鍵：貪婪法＋Ｏ(㏒Ｎ)：利用查並集，搜尋前一個未被占有的空檔
 * 貪婪法 : 販售每樣商品都會佔用一天的時間，所以就依照收益最高的優先處理，只要期限內完成即可＝能拖就拖避免佔用到太前面的空檔。
 * 查並集 : 狀態紀錄空檔(從這個日期往前能找到的第一個空檔)
 * 		   DSU - FindRoot() : Ｏ(㏒Ｎ)
 * 		   DSU - Union() : Ｏ(1)，這個空檔被用掉，所以這個空檔的狀態和這個空檔前一天的狀態做合併。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxD=1e4;
int root[MaxD+1];
 
struct ITEM{
	int P, D;
	bool operator<(const ITEM &rhs)const{ return P>rhs.P; }
} item[MaxN];
int PreDay(int x){ return (root[x]==x)? x: root[x]=PreDay(root[x]); }
int main(){
	int N, maxDay;
	while(scanf("%d\n",&N)!=EOF){
		maxDay=0;
		for(int i=0;i<N;i++){
			scanf("%d %d",&item[i].P,&item[i].D);
			maxDay=max(maxDay,item[i].D);
		}
		sort(item,item+N);
 
		for(int i=0;i<=maxDay;i++)
			root[i]=i;
		int ans=0;
		for(int i=0;i<N;i++){
			int nowDay=PreDay(item[i].D);
			if(nowDay==0) continue;
			ans+=item[i].P;
			root[nowDay]=PreDay(nowDay-1);
		}
		printf("%d\n",ans);
	}
}