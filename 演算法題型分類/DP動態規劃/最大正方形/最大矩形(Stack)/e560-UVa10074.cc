// 最大矩形面積
#include <bits/stdc++.h>
using namespace std;

const int MaxR=100;
const int MaxC=100;
int mapv[MaxR][MaxC];
int main() {
	int R, C;
	while(scanf("%d %d\n",&R,&C) and R){
		int max_area=0;
		for(int i=0;i<R;i++){
			scanf("%d",&mapv[i][0]);
			mapv[i][0]^=1;
			max_area=max(max_area,mapv[i][0]);
			for(int j=1;j<C;j++){
				scanf("%d",&mapv[i][j]);
				mapv[i][j]=(mapv[i][j]==0)? mapv[i][j-1]+1:0;
				max_area=max(max_area,mapv[i][j]);
			}
		}
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++){
				int now_h=1, now_w=mapv[i][j];
				for(int k=i-1;k>=0 and min(now_w,mapv[k][j])>0;k--){
					now_w=min(now_w,mapv[k][j]);
					max_area=max(max_area,now_w*++now_h);
				}
			}
		printf("%d\n",max_area);
	}
}

