#include<bits/stdc++.h> 
using namespace std;
 
const int MaxN=2e1;
const int MaxM=5e2;
char opt[MaxM+2];
char grd[MaxN+1][MaxN+2];
inline bool IsNumber(char &c){ return '0'<=c and c<='9'; }

int main(){
	int N, M, now_x, now_y;
	// input
	scanf("%d\n",&N);
	for(int i=1; i<=N; i+=1)
		scanf("%s",grd[i]+1);
	
	scanf("%d %d\n%d\n",&now_x,&now_y,&M);
	scanf("%s",opt);
	
	int ans=0;
	for(int i=0; opt[i]!='\0'; i+=1){
		switch(opt[i]){
			case 'U':
				while(now_x>1 and IsNumber(grd[now_x-1][now_y]))
					now_x-=1;
				ans+= grd[now_x][now_y]-'0';
				grd[now_x][now_y]='0';
				break;
			case 'D':
				while(now_x<N and IsNumber(grd[now_x+1][now_y]))
					now_x+=1;
				ans+= grd[now_x][now_y]-'0';
				grd[now_x][now_y]='0';
				break;
			case 'L':
				while(now_y>1 and IsNumber(grd[now_x][now_y-1]))
					now_y-=1;
				ans+= grd[now_x][now_y]-'0';
				grd[now_x][now_y]='0';
				break;
			case 'R':
				while(now_y<N and IsNumber(grd[now_x][now_y+1]))
					now_y+=1;
				ans+= grd[now_x][now_y]-'0';
				grd[now_x][now_y]='0';
				break;
			case 'B':
				if(opt[i-1]=='U' and grd[now_x-1][now_y]=='*')
					grd[now_x-1][now_y]='0';
				if(opt[i-1]=='D' and grd[now_x+1][now_y]=='*')
					grd[now_x+1][now_y]='0';
				if(opt[i-1]=='L' and grd[now_x][now_y-1]=='*')
					grd[now_x][now_y-1]='0';
				if(opt[i-1]=='R' and grd[now_x][now_y+1]=='*')
					grd[now_x][now_y+1]='0';
                break;
		}
	}
	printf("%d\n",ans);
}



