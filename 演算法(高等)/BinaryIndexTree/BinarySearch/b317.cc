/* 給定Ｎ個魔法陣的半徑ｒ和高度ｈ，可以覆蓋其中Ｋ個魔法陣的條件下輸出最小的體積(2r*2r*h)？
 * 解題關鍵：DP-LIS，滿足 rx ≤ ry and hx ≤ hy 時魔法陣ｙ可以涵蓋魔法陣ｘ
 * 題目限制： r, h ≤ 100
 * 題目盲點： (1) K = 0 的情況 (2) 不能只是檢測存在某個魔法陣的高度 
 * 4 3
 * 1 4
 * 2 3
 * 3 2
 * 4 1
 * 依照半徑小到大(相同時，因為覆蓋規則優先處理高度低的) ... 排序
 * 二分法測試，範圍從目前魔法陣高度到最大高度之間，滿足魔法陣個數總和至少Ｋ個時最小化高度
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxH=1e2;
struct NODE{
	int r, h;
} node[MaxN];

int N, K;
int BIT[101]={};

int lowbit(int x){ return x&-x; }
void Update(int pos,int v){
	for( ; pos<=100; pos+=lowbit(pos))
		BIT[pos]+=v;
}
int Query(int pos,int ret=0){
	for(; 0<pos; pos-=lowbit(pos))
		ret+=BIT[pos];
	return ret;
}

int main(){
	cin>>N>>K;
	for(int n=0; n<N; n++)
		cin>>node[n].r>>node[n].h;
	// lambda 寫法：根據Ｘ座標小到大
	sort(node,node+N,[](NODE lhs,NODE rhs){
		return (lhs.r!=rhs.r)? lhs.r<rhs.r: lhs.h<rhs.h;
	});
	// BIT
	int ans=(K==0)? 0:INT_MAX;
	for(int h, n=0; n<N; n++){
		Update(node[n].h,1);
		// BinarySearch
		int L=node[n].h;
		int R=MaxH;
		while(L<=R){
			int M=L+R>>1;
			if( Query(M)>=K ){
				R=M-1;
				ans=min(ans,node[n].r*node[n].r*M<<2);
			}else
				L=M+1;
		}
	}   
	cout<<ans;
}
