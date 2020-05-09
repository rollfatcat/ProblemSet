// Histogram找到最大矩形面積

#include<iostream>
#include<stack>
using namespace std;

struct nn{ int h, x; };
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N;  cin>>N;
  stack<nn> S;
  int maxArea=0, tmpArea, now_h;
  for(int x=1; x<=N; x++){
    cin>>now_h;
    while(!S.empty() and S.top().h>now_h){
      tmpArea=S.top().h*(x-S.top().x);
      maxArea=max(maxArea,tmpArea);
      S.pop();
    }
    for(int h=(S.empty())?1:(S.top().h+1); h<=now_h; h++)
      S.push({h,x});
  }
  while(!S.empty()){
    tmpArea=S.top().h*(N+1-S.top().x);
    maxArea=max(maxArea,tmpArea);
    S.pop();
  }
  cout<<maxArea<<endl;
}
/*
5
5
4
5
5
3
*/