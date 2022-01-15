#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxT=1e9;
map<int,vector<int>> tpos;
vector<vector<int>> ansT;
int main(){
    int N, G, S, T ;
    scanf("%d",&N);
    for(int i=0; i<N; i+=1){
        scanf("%d %d %d",&G,&S,&T);
        if(tpos.find(S)==tpos.end()) tpos[S]={0,0};
        tpos[S][G-1]+=1;
        if(tpos.find(T)==tpos.end()) tpos[T]={0,0};
        tpos[T][G-1]-=1;
    }
    
	bool s=false;
    int preT=-1;
    int p0=0, p1=0;
    for(auto nowT: tpos){
        p0+=nowT.second[0];
        p1+=nowT.second[1];
        if(p0>0 and p1==0 and s==0){ // update
            preT=nowT.first;
            s=1;
        }
        if(s==1 and (p1>0 or p0==0)){
            ansT.push_back( {preT,nowT.first} );
            s=0;
        }
    }
    printf("%d\n",ansT.size());
    for(auto T: ansT)
    	printf("%d %d\n",T[0],T[1]);
}