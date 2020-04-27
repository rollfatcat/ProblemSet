/* 給定Ｎ×Ｍ的地圖，將每列(Row)成對的1之間設定為1
 * 1 0 1 0 0 1 1 => 1 1 1 0 0 1 1
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=100;
int v[MaxM];
 
int main(){
	for(int N,M;scanf("%d %d\n",&N,&M)!=EOF;){
		for(int i=0;i<N;i++){
			int pivot=-1, GetPivot=0;
			for(int now=0;now<M;now++){
				scanf("%d",&v[now]);
				if(v[now]==1){
					if(GetPivot==1){
						for(int j=pivot+1;j<now;j++)
							v[j]=1;
					}else
						pivot=now;
					GetPivot^=1;
				}
			}
			
			for(int j=0;j<M;j++)
				putchar(v[j]+'0'),
				putchar(' ');
			putchar('\n');
		}
	}
}
