/* 給定Ｎ個工作的最後期限和收益，每個工作會佔用一天的時間，輸出如何安排工作順序可收取最大化收益？
 * 解題關鍵：貪婪法＋Ｏ(Ｎ)搜尋前一個未被占有的空檔
 * 每個工作都會佔走一天的時間，所以就依照收益最高的優先做。
 * 只要期限內完成即可，能拖就拖避免佔用到太前面的空檔期＝從目前工作的期限往前找直到第一個空檔。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxD=1e4;
bool empty[MaxD+1];
struct DATA{
	int due, profit;
} data[MaxN];
 
bool compare(DATA A, DATA B){ return A.profit>B.profit; }
int main(){
	int N, maxDue;
	while(scanf("%d\n",&N)!=EOF){
		maxDue=0;
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i].due,&data[i].profit),
			maxDue=max(maxDue,data[i].due);
		/**/
		sort(data,data+N,compare);
		fill(empty+1,empty+maxDue+1,0);
		int ans=0, pos;
		for(int i=0;i<N;i++){
			for(pos=data[i].due; pos>0 and empty[pos]; pos--);
			if(pos>0) empty[pos]=1, ans+=data[i].profit;
		}
		printf("%d\n",ans);
	}
}