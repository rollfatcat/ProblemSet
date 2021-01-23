/* 給定Ｋ個單位長度和一個字串，輸出連續Ｋ個單位大小寫交錯的子字串長度？
 * 解題關鍵：貪婪法，將原字串轉變為連續大小寫的字元長度
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
char ss[MaxN+2];
int num[MaxN];
int main(){
	int K, N;
	while(scanf("%d",&K)!=EOF){
		scanf("%s\n",ss);
		/* 轉換為"連續"大小寫字元的長度 */
		N=0; num[0]=1;
		bool now, pre= 'A'<=ss[0] and ss[0]<='Z';
		for(int i=1;ss[i]!='\0';i++, pre=now){
			now='A'<=ss[i] and ss[i]<='Z';
			(pre==now)? num[N]+=1: num[++N]=1;
		}
		/* 貪婪法：從枚舉起點，直到某一段的連續長度不等於Ｋ
		 * 若新節點的長度  等於Ｋ時  nowL可以延伸一個單位
		 * 若新節點的長度不等於Ｋ時，nowL到這邊時就得停止
		 *   此時試著以這個節點作為新起點，往後延伸。
		 * 注意：最後一次時 nowL 可能剛好在延伸而沒有比對到
		 */
		int maxL=0;
		int nowL=0;
		for(int i=0;i<=N;i++){
			if(num[i]==K)
				nowL++;
			else{ 
				maxL=max(maxL,nowL+(num[i]>K));
				nowL= num[i]>K;
			}
		}
		printf("%d\n",max(maxL,nowL)*K);
	}
}