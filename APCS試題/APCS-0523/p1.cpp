#include<bits/stdc++.h> 
using namespace std;
 
const int MaxX=1e6;
const int MaxY=1e6;
int main(){
	int x, y, h, t;
	scanf("%d %d %d",&x,&h,&y);
	for(t=0; t<h; t+=1){
		x-=(t+9)/10;
		if(y>=x) break;
	}
	(y>=x)? printf("%d\n",t): puts("IMPOSSIBLE");
}