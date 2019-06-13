// 不用Stack
#include<iostream>
#include<stack>
using namespace std;

struct nn{ int h, x; };
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, h[10000];
  cin>>N;
  for(int i=0; i<N; i++)
    cin>>h[i];
  int maxArea=0, w;
  for(int i=0;i<N;i++){
    int w=1;
    for(int j=i+1; j<N  and h[j]>=h[i]; j++, w++); //向右增加寬度
    for(int j=i-1; j>=0 and h[j]>=h[i]; j--, w++); //向左增加寬度
    int tmpArea=h[i]*w;
    maxArea=max(maxArea,tmpArea);
  }
  cout<<maxArea<<endl;
}