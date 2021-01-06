/* 給定Ｎ個人(編號０到Ｎ-1)和每個人的好友，輸出有多少個小團體？
 * 好友編號剛好是０到Ｎ-1各自出現１次＝迴圈找一輪回到出發的原點時剛好可以找齊所有成員
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4;
int nxt[MaxN];
bool vis[MaxN]={};

int main(){
    ios::sync_with_stdio;
    cin.tie(0); cout.tie(0);
    
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nxt[i];
    int ans=0;
    for(int i=0;i<N;i++)
        if(vis[i]==0){
            ans+=1;
            vis[i]=1;
            for(int one=nxt[i]; one!=i; one=nxt[one])
                vis[one]=1;
        }
    cout<<ans<<'\n';
}
