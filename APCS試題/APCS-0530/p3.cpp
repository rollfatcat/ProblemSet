#include<bits/stdc++.h>
using namespace std;

const int MaxSZ=25e4;
const int MaxQ=2e5;
const int MaxV=1e3;

int main(){
	int R, C, v, Q;
	
	scanf("%d %d",&R,&C);
	vector<vector<int>> odd(R+1,vector<int>(C+1));
	vector<vector<int>> eve(R+1,vector<int>(C+1));
	for(int r=1; r<=R; r+=1)
		for(int c=1; c<=C; c+=1){
			scanf("%d",&v);
			odd[r][c]=odd[r][c-1]+odd[r-1][c]-odd[r-1][c-1]+((r+c)&1 ? v: 0);
			eve[r][c]=eve[r][c-1]+eve[r-1][c]-eve[r-1][c-1]+((r+c)&1 ? 0: v);
		}
	
	scanf("%d",&Q);
	int a, b, c, d;
	while(Q-->0){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("%d\n",( (a+b)&1 )? odd[c][d]-odd[c][b-1]-odd[a-1][d]+odd[a-1][b-1] : eve[c][d]-eve[c][b-1]-eve[a-1][d]+eve[a-1][b-1] );
	}
}