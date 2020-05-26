/* 給定Ｎ×Ｎ的二維矩陣，以２×２為單位做 MaxPool
 * 輸出每個 Pool 內的最大值。
 * 根據讀取時的位置決定執行的內容：設定為初始值 或是 輸出極值？
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=20;
int main(){
	int N, v, maxv[MaxN];
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++){
			if(i&1){
				for(int j=0;j<N;j++)
					scanf("%d",&v),
					(j&1)? printf("%d ",max(maxv[j>>1],v)): maxv[j>>1]=max(maxv[j>>1],v);
				putchar('\n');
			}else{
				for(int j=0;j<N;j++)
					scanf("%d",&v),
					(j&1)? maxv[j>>1]=max(maxv[j>>1],v): maxv[j>>1]=v;
			}
		}
	}
}