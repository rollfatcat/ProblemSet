/* 給定一個數字(以字串讀取即可)
 * 依據每個位數的數字出現的次數由大到小排序，若相同則優先輸出數值小的數字。
 */
#include<bits/stdc++.h>
using namespace std;

int cnt[10];
int ord[10];
inline bool compare(int a,int b){
	return (cnt[a]==cnt[b])? a<b: cnt[a]>cnt[b];
} 
int main(){
	for(char ss[22];scanf("%s\n",ss)!=EOF;){
		for(int i=0;i<10;i++)
			ord[i]=i, cnt[i]=0;
		for(int i=0;ss[i]!='\0';i++)
			cnt[ ss[i]-'0' ]++;
		sort(ord,ord+10,compare);
		for(int i=0;i<10 and cnt[ord[i]]>0;i++)
			printf("%d ",ord[i]);
		putchar('\n');
	}
}
