/* 給定Ｎ張卡片的正反面點數但相同的點數只能取一張，透過調整每張牌的朝向面，最大化點數的總和？
 * 解題關鍵：DSU(查並集)+discretization(離散化)
 * 點數＝vertex，同一張牌當中正反面的點數＝edge連接２個點數
 * 分情況討論(屬於每個集合中是否存在環？)
 *   Ｙ，代表每個點數可以被涵蓋到一次
 *   Ｎ，必定有一個點數無法被選取 ... 捨棄整個集合中最小的點數
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxV=1e9; // 點數最大是 1e9
int num[MaxN][2];
int srt[MaxN<<1]; // 離散化

int root[MaxN<<1];
int min_v[MaxN<<1];
bool cycle[MaxN<<1];
int FindRoot(int x){
	return (root[x]==x)? x: root[x]=FindRoot(root[x]); }
void Union(int a,int b){
	int Ra=FindRoot(a);
	int Rb=FindRoot(b);
	if(Ra==Rb){
		cycle[Ra]=1; 
		return;
	}
	 root[Rb]=Ra;
	min_v[Ra]=min(min_v[Ra],min_v[Rb]);
	cycle[Ra]|=cycle[Rb];
}
int main(){
	int N;
	
	scanf("%d",&N);
    for(int n=0; n<N; n+=1){
        scanf("%d %d",&num[n][0],&num[n][1]);
        srt[ n ]=num[n][0];
        srt[N+n]=num[n][1];
    }
    sort(srt,srt+(N<<1));
    int uN=unique(srt,srt+(N<<1))-srt;
    for(int n=0; n<uN; n+=1){
         root[n]=n;
        min_v[n]=srt[n];
        cycle[n]=0;
    }
    for(int n=0; n<N; n+=1)
        Union(lower_bound(srt,srt+uN,num[n][0])-srt,
              lower_bound(srt,srt+uN,num[n][1])-srt);
    
    long ans=0;
    for(int n=0; n<uN; n+=1){
        ans+=srt[n];
        if(root[n]==n and cycle[n]==0)
            ans-=min_v[n];
    }
    printf("%ld\n",ans);
	
}