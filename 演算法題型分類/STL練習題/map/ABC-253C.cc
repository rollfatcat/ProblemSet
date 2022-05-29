#include<bits/stdc++.h>
using namespace std;
 
const int MaxQ=2e5;
const int MaxA=1e9;
 
map<int,int> memo;
int main(){
	int Q, o, x, c;
	
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d",&o);
		if(o==1){
			scanf("%d",&x);
			memo[x]+=1;
		}else if(o==2){
			scanf("%d %d",&x,&c);
			if(memo.find(x)!=memo.end()){
				if( memo[x]<=c ){
					memo.erase( memo.find(x) );
				}else
					memo[x]-=c;
			}
		}else{ // o==3
			printf("%d\n",(*memo.rbegin()).first-(*memo.begin()).first);
		}
	}
}