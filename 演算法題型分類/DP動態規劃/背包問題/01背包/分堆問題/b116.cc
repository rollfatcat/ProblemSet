// 題目沒有給 MaxW的範圍
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100
#define MaxW 50000
#define MAX(a,b)((a>b)?a:b)

int main(){
  int M, N, sum;
  int w[MaxN], map[MaxW];
  while(cin>>M>>N)
    while(M--){
      sum=0;
      for(int i=0;i<N;i++)
        cin>>w[i], sum+=w[i];
      //總和是奇數, 不可能透過變換正負號加總變成0
      if(sum%2){
        cout<<"No\n";
        continue;
      }
      sum/=2;
      memset(map,0,sizeof(map));
      for(int i=0;i<N;i++)
        for(int j=sum;j>=w[i];j--)
          map[j]=MAX( map[j], map[j-w[i]]+w[i]);
      if(map[sum]==sum)
        cout<<"Yes\n";
      else
        cout<<"No\n";
    }
}