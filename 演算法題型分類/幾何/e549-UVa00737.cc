/* 輸出立方體彼此重疊的體積(全部共同的重疊區)
 * 該重疊區必定存在題目給定的任意立方體內, 否則輸出重疊區體積＝0
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxL=1e6; //立方體彼此重疊的體積不超過10^6單位。
struct CUBE{
	int x[2], y[2], z[2];
} now;
int main(){
	int x, y, z, L;
	for(int N;scanf("%d",&N) and N;){
		scanf("%d %d %d %d",&x,&y,&z,&L);
		now=(CUBE){x,x+L,y,y+L,z,z+L};
		for(N--;N>0;N--)
			scanf("%d %d %d %d",&x,&y,&z,&L),
			now.x[0]=max(now.x[0],x),
			now.x[1]=min(now.x[1],x+L),
			now.y[0]=max(now.y[0],y),
			now.y[1]=min(now.y[1],y+L),
			now.z[0]=max(now.z[0],z),
			now.z[1]=min(now.z[1],z+L);
		(now.x[1]<now.x[0] or now.y[1]<now.y[0] or now.z[1]<now.z[0]) ?puts("0"):printf("%ld\n",(long)(now.x[1]-now.x[0])*(now.y[1]-now.y[0])*(now.z[1]-now.z[0]));
	}
}