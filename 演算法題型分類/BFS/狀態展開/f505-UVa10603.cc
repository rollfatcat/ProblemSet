/* 給定３個水杯Ａ/Ｂ/Ｃ，一開始ＡＢ是空的Ｃ是滿的，輸出能形成「不超過Ｄ的最大水量」的最少水量變化？
 * 倒法：自己這一杯水倒到另一杯時只能是自己空掉 或是 另一杯滿了為止
 * 問題盲點：觀察可以知道倒法時水量不會改變，３杯水的總水量等於Ｃ，
 *         所以紀錄某個狀態是否算過時，只要枚舉２個維度(Ａ的水量變化ｘＢ的水量變化)
 * 解題關鍵：BreathFirstSearch + memorization
 * 狀態描述：３杯水當下的水量＋形成這個局面時的水量變化
 * 狀態轉移：枚舉２杯倒水( from -> to )，共有６種可能
 * 倒水的過程中，更新「不超過Ｄ」時的最少水量變化。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxS=200;
int memo[MaxS][MaxS];
int ansv[MaxS]={};
struct STATUS{
	int v[3], d;
} bound, now, nxt;
inline void MaxD(int a,int b,int c,int d){
	int pvt=-1;
	if(bound.d>=a) pvt=max(pvt,a);
	if(bound.d>=b) pvt=max(pvt,b);
	if(bound.d>=c) pvt=max(pvt,c);
	if(pvt>=0 and ansv[pvt]>d) ansv[pvt]=d; 
}
int main(){
	int caseT, dv;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d %d %d",&bound.v[0],&bound.v[1],&bound.v[2],&bound.d);
		/* init */
		for(int i=0;i<=bound.v[0];i++)
			for(int j=0;j<=bound.v[1];j++)
				memo[i][j]=INT_MAX;
		for(int i=1;i<=bound.d;i++)
			ansv[i]=INT_MAX;
		
        queue<STATUS> Q;
		Q.push( {0,0,bound.v[2],0} );
		while(Q.empty()==0){
			now=Q.front(); Q.pop();
			if(memo[now.v[0]][now.v[1]]<=now.d) continue;
			/* 總水量是固定的，狀態只要枚舉 v[0],v[1]  */
            memo[now.v[0]][now.v[1]]=now.d;
			/* 取三者水量當中不超過 bound.d 當中水量較高者，紀錄達成這個狀態下最少的水量變化 */
            MaxD(now.v[0],now.v[1],now.v[2],now.d);
            /* Ａ -> Ｂ */
			dv=min(now.v[0],bound.v[1]-now.v[1]);
			nxt={now.v[0]-dv,now.v[1]+dv,now.v[2],now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
            /* Ｂ -> Ａ */
			dv=min(now.v[1],bound.v[0]-now.v[0]);
			nxt={now.v[0]+dv,now.v[1]-dv,now.v[2],now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
            /* Ａ -> Ｃ */
			dv=min(now.v[0],bound.v[2]-now.v[2]);
			nxt={now.v[0]-dv,now.v[1],now.v[2]+dv,now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
            /* Ｃ -> Ａ */
			dv=min(now.v[2],bound.v[0]-now.v[0]);
			nxt={now.v[0]+dv,now.v[1],now.v[2]-dv,now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
            /* Ｂ -> Ｃ */
			dv=min(now.v[1],bound.v[2]-now.v[2]);
			nxt={now.v[0],now.v[1]-dv,now.v[2]+dv,now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
            /* Ｂ -> Ｃ */
			dv=min(now.v[2],bound.v[1]-now.v[1]);
			nxt={now.v[0],now.v[1]+dv,now.v[2]-dv,now.d+dv};
			if(memo[nxt.v[0]][nxt.v[1]]>nxt.d)
				Q.push(nxt);
		}
        
		while(ansv[bound.d]==INT_MAX)
			bound.d--;
		printf("%d %d\n",ansv[bound.d],bound.d);
	}
}