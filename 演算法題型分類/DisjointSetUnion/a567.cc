// 先講線性搜尋的做法再說利用 Disjoint-Set 來加速至 O(n㏒n)
/* Greedy : 每個工作都會佔走一天的時間所以就依照收益最高的優先做
 * 透過 Disjoint-set 來加速至 O(n㏒n)，remDay[i] 來記錄 deadline=i 時，可填的時間區間。
 * 每次填入後，代表此可行區間又少一個可填的，所以將它和上一個天數的區間合併
 * (將 remDay[i] 指向找到有空的那天，永遠都是大數指向小數(有空的天數一定比較小))。
 */
/* 給定Ｎ個工作的最後期限和收益，每個工作會佔用一天的時間，輸出如何安排工作順序可收取最大化收益？
 * 解題關鍵：貪婪法＋Ｏ(㏒Ｎ)：利用查並集，搜尋前一個未被占有的空檔
 * 貪婪法 : 每個工作都會佔走一天的時間，所以就依照收益最高的優先處理，只要期限內完成即可＝能拖就拖避免佔用到太前面的空檔。
 * 查並集 : 狀態紀錄空檔(從這個日期往前能找到的第一個空檔)
 * 		   DSU - FindRoot() : Ｏ(㏒Ｎ)
 * 		   DSU - Union() : Ｏ(1)，這個空檔被用掉，所以這個空檔的狀態和這個空檔前一天的狀態做合併。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxD=1e4;
int preDay[MaxD+1];
struct DATA{
	int due, profit;
} data[MaxN];
 
bool compare(DATA A, DATA B){ return A.profit>B.profit; }
int FindPreDay(int x){ return (preDay[x]==x)? x: preDay[x]=FindPreDay(preDay[x]); }
int main(){
	int N, maxDue;
	while(scanf("%d\n",&N)!=EOF){
		maxDue=0;
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i].due,&data[i].profit),
			maxDue=max(maxDue,data[i].due);
		/* 依據收益高到低排序，初始化查並集的陣列 */
		sort(data,data+N,compare);
    	for(int i=0;i<=maxDue;i++) 
			preDay[i]=i;
		int ans=0;
		for(int i=0;i<N;i++){
			/* 搜尋目前日期往前推算的第一個空檔 */
      		int nowDay=FindPreDay(data[i].due);
			if(nowDay>0) 
				preDay[nowDay]=FindPreDay(nowDay-1), 
				ans+=data[i].profit;
		}
		printf("%d\n",ans);
	}
}