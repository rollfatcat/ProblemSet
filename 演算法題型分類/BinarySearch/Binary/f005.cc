/* 改編於 ZJa465-UVa12405
 * 輸出稻草人數量後需要在括號內輸出稻草人放置的位置。
 * 規則：若要保護的可用田地，有兩個位置的選項可以放置同一個稻草人時，則以位置編號較大者為放置位置。
 * 規則的意思：稻草人可以放置的位置不能超過Ｌ
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=100;
const int MaxL=100+2;
char ss[MaxL];
int main(){
	int caseT, L;
	scanf("%d\n",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d\n%s\n",&L,ss);
		/* 貪婪法：若目前的格子是'.'時代表下一格(若沒有超過範圍)放置稻草人
         * 並且可以一次cover包含這格之後的連續３格。
         */
        int cnt=0;
		vector<int> pos;
		for(int now=0;now<L; )
			if(ss[now]=='.')
				cnt++, pos.push_back(now+2), now+=3;
			else
				now++;
        /* 若最後一個位置超過Ｌ時則往前一格
         * Ｌ=2, ss[]=".#"
         */
		if(cnt>0 and pos.back()>L) pos.back()=L;
		// 根據格式輸出：括號內是稻草人的位置
        printf("Case %d: %d",caseI,cnt);
		if(cnt>0) printf("(%d",pos[0]);
		for(int i=1;i<cnt;i++)
			printf(",%d",pos[i]);
		if(cnt>0) putchar(')');
		putchar('\n');
	}
}