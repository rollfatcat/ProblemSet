#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
int table[MaxN+1]={0,1};
 
int tabulate(int now){
	if(now>=MaxN)
		return tabulate( (now&1)? (3*now+1):(now>>1) )+1;
	if(table[now]==0)	
		table[now]= tabulate( (now&1)? (3*now+1):(now>>1) )+1;
	return table[now];
}
int main(){
	/* online-query */
	int qL, qR, ans;
	while(scanf("%d %d\n",&qL,&qR)!=EOF){
		printf("%d %d ",qL,qR);
		if(qL>qR) swap(qL,qR);
		for(ans=tabulate(qL++); qL<=qR; qL++)
			ans=max(ans,tabulate(qL));
		printf("%d\n",ans);
	}
}