// 題目沒有直接給 MaxW的範圍但可以從題目推得
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100
#define MaxW 25000
#define MAX(a,b)((a>b)?a:b)

int main(){
  int M, N, sum, half;
  int w[MaxN], map[MaxW];

  cin>>M;
  while(M--){
    cin>>N;
    sum=0;
    for(int i=0;i<N;i++)
      cin>>w[i], sum+=w[i];
    half=sum/2;
    memset(map,0,sizeof(map));
    for(int i=0;i<N;i++)
      for(int j=half;j>=w[i];j--)
        map[j]=MAX( map[j], map[j-w[i]]+w[i]);
    cout<<(sum-2*map[half])<<endl;
  }
}