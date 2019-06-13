// 嘗試型的探索範圍題目, 找到前65個
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
  int bound=2001;
  bool isIdoneal[bound];
  fill(isIdoneal,isIdoneal+bound,1);
  for(int a=1;a<bound;a++)
    for(int b=a+1;b<bound;b++)
      for(int c=b+1;c<bound;c++){
        int tmp=a*(b+c)+b*c;
        if(tmp<bound)  isIdoneal[tmp]=false;
        else break;
      }
  vector<int> Idoneal;
  for(int i=1;i<bound;i++)
    if(isIdoneal[i])
      Idoneal.push_back(i);
  for(int x;cin>>x;)
    cout<<Idoneal[x-1]<<endl;
}