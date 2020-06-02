/* 最大矩形面積 - Stack應用題
 */
#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
int hgt[MaxN][MaxN];

int main(){
	for(int R,C;scanf("%d %d\n",&R,&C)!=EOF and R>0;){
		for(int i=0;i<C;i++)
			scanf("%d",&hgt[0][i]),
			hgt[0][i]^=1;
		for(int i=1;i<R;i++)
			for(int j=0;j<C;j++)
				scanf("%d",&hgt[i][j]),
				hgt[i][j]=(hgt[i][j])? 0: hgt[i-1][j]+1;
		int maxRec=0;
		for(int i=0;i<R;i++){
			stack<int> S;
			for(int prev, j=0;j<C;j++){
				for(prev=j; S.empty()==0 and hgt[i][S.top()]>hgt[i][j]; S.pop())
					maxRec=max(maxRec,hgt[i][S.top()]*(j-S.top())),
					prev=S.top();
				S.push(prev);
				hgt[i][prev]=hgt[i][j];
			}
			for(;S.empty()==0 and hgt[i][S.top()]>0;S.pop())
				maxRec=max(maxRec,hgt[i][S.top()]*(C-S.top()));
		}
		printf("%d\n",maxRec);
	}
}


