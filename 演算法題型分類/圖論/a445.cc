// Disjoint Set => 朋友關係視為特殊樹圖, parent Node只有一個
#include<iostream>
using namespace std;
#define MaxN 10001

int N, M, Q, G[MaxN], h[MaxN];
int find(int x){ return(G[x]==x)?x:find(G[x]); }
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while(cin>>N>>M>>Q){
    for(int i=1;i<=N;i++)
      G[i]=i, h[i]=0;
    for(int a,b; M--; ){
      cin>>a>>b;
      int pa=find(a), pb=find(b);
      if(h[pa]>h[pb])
        G[b]=G[pb]=pa;
      else if(h[pa]<h[pb])
        G[a]=G[pa]=pb;
      else{ //高度相同
        if(pa>pb)
          G[a]=G[pa]=pb, h[pb]++;
        else
          G[b]=G[pb]=pa, h[pa]++;
      }
    }
    //把樹壓平,做加速
    for(int i=1;i<=N;i++){
      int pa=find(i);
      if(pa!=G[i])
        G[i]=pa;
    }
    for(int a,b; Q--; )
      cin>>a>>b, cout<<( (G[a]==G[b])?":)":":(" )<<endl;
  }
}