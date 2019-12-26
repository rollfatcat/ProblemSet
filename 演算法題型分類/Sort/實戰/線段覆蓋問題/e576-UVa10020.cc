/* Greedy：題目要求依照Ｌi為考量, 勢必要做Sort
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=5e3;
const int MaxN=1e5;
const int INF=1<<30;
struct LINE{
	int st, ed;
	LINE(int s=0,int e=0):st(s),ed(e){}
	bool operator<(const LINE &rhs)const{
		return (st==rhs.st)? ed<rhs.ed: st<rhs.st;
	}
} line[MaxN];
int ID[MaxN]; // 紀錄選取的線段編號

int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		
		int N=0, M;
		scanf("%d",&M);
		for(int x,y;scanf("%d %d",&x,&y) and x or y;)
			if(!(y<=0 or x>M)) // 線段不落在[0,M]的可以忽略不計
				line[N++]=LINE(x,y);
		sort(line,line+N);
		
		int now_y=0, nxt_y=0;
		int cnt=0, rec=INF;
		/* 枚舉每個線段, 並確保掃描線仍在範圍內
		 * (1) 線段的起點落在現在掃描線的左側, 更新下次的掃描線
		 * (2) 線段的起點落在現在掃描線的右側, 確認是否存在一線段
		 *     若該線段不存在, 代表發生『無法銜接』的狀態
		 *     若該線段存在, 代表記錄下該線段編號後更新掃描線和紀錄
		 */
		for(int idx=0;idx<N and now_y<M;){
			if(line[idx].st<=now_y){
				if(nxt_y<line[idx].ed)
					nxt_y=line[rec=idx].ed;
				idx++;
			}else{
				if(rec==INF)
					break;
				else{
					ID[cnt++]=rec;
					rec=INF;
					now_y=nxt_y;
				}
			}
		}
		if(rec!=INF)
			ID[cnt++]=rec,
			now_y=nxt_y;
		
		if(now_y>=M){
			printf("%d\n",cnt);
			for(int i=0;i<cnt;i++)
				printf("%d %d\n",line[ID[i]].st,line[ID[i]].ed);
		}else  puts("0");
		
		if(caseT) puts(""); // 測資間空一行
	}
}
