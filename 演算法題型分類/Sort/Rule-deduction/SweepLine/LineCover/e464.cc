/* 視野的半徑是R，現在有n個士兵，你只能在有士兵的位置放石頭，求最少要用幾顆石頭？
 * 解題關鍵：掃描線+ 
 */
#include<bits/stdc++.h>
using namespace std;

int main() {
	int R, n, x;
	while(scanf("%d %d",&R,&n) and R>=0 and n>=0){
		vector<int> pos(n);
		for(int i=0;i<n;i++)
			scanf("%d",&pos[i]);
		sort(pos.begin(),pos.end());
		int cnt=0;
		for(int frt=0, bck=0; frt<n and bck<n; cnt++){
            // 找到第一個和 bck 相隔距離 ≤ R 時距離最遠的石頭
			for(; frt<n and pos[frt]-pos[bck]<=R; frt++);
            // 上述迴圈會找到大於Ｒ所以要倒回一格，再找和 frt 相隔距離超過Ｒ的第一個石頭
			for(frt--;bck<n and pos[bck]-pos[frt]<=R; bck++);
		}
		printf("%d\n",cnt);
	}
}