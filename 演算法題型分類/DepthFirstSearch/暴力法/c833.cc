// 把同一格的Row和Col都設定成不能放('#')
#include<iostream>
using namespace std;

int main(){
  int N, M;
  bool Col[3000]={}, Row[3000]={};
  char ch;

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  cin>>N>>M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++){
      cin>>ch;
      if(ch=='#')
        Row[i]=Col[j]=true;
    }
  for(int i=0;i<N;i++,cout<<endl)
    for(int j=0;j<M;j++)
      cout<<((Row[i]|Col[j])?'#':'X');
}