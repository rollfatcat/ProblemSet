#include<bits/stdc++.h>
using namespace std;

const int MaxM=1e4;
const int MaxT=1e4;
int M, T;
int pos[MaxT][2];
int ord[MaxT];
int val[MaxT+1]={};
int BIT[MaxT+1]={};

bool compare(int a,int b){ return (pos[a][0]==pos[b][0])? pos[a][1]<pos[b][1]: pos[a][0]<pos[b][0]; }

inline int Query(int end,int out=0){
	for(int now=end; now>0; now^=now&-now)
		out=max(out,BIT[now]);
	return out;
}
inline void Update(int end,int v){
	for(int now=end; now<=M and BIT[now]<v; now+=now&-now)
		BIT[now]=v;
}
int main(){
 
  scanf("%d %d\n",&M,&T);
  for(int i=0;i<T;i++)
		scanf("%d %d\n",&pos[i][0],&pos[i][1]), ord[i]=i;
	sort(ord,ord+T,compare);
	
	int v, ans=0;
	for(int i=0;i<T;i++){
		v=Query(pos[ ord[i] ][0]);
		if(v+pos[ord[i]][1]-pos[ord[i]][0]>val[pos[ord[i]][1]]){
			val[pos[ord[i]][1]]=v+pos[ord[i]][1]-pos[ord[i]][0];
			ans=max(ans,val[pos[ord[i]][1]]);
			Update(pos[ord[i]][1],val[pos[ord[i]][1]]);
		}
	}
	printf("%d\n",ans);
}


