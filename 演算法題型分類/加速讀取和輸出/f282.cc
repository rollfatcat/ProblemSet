/* 給定數個數字(介於１到１００之間)，輸出小到大的排序？
 * 解題關鍵：加速讀取和輸出＋CountingSort
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxV=1e2;
int cnt[MaxV+1]={};
inline bool scanInt(int &v){ char c;for(v=0;'0'<=(c=getchar()) and c<='9'; v=(v<<3)+(v<<1)+c-'0'); return c!=EOF; }
inline void prinInt(int v){
	if(v==100){ putchar('1');putchar('0');putchar('0'); putchar(' '); return; }
	if(v>=10) putchar(v/10+'0');
	putchar(v%10+'0');
	putchar(' ');
}
int main(){
	int v;
	while(scanInt(v))
		cnt[v]++;
	
	for(int i=1;i<=MaxV;i++)
		for(int j=1;j<=cnt[i];j++)
			prinInt(i);
	putchar('\n');
}