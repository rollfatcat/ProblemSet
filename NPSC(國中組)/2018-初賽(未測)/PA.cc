// 最多取5名(25名以內的隊伍)
#include<iostream>
using namespace std;

const int max_cnt=5;
int main(){
  int N, x, cnt;
  cin>>N;
  while(N--){
    cin>>x;
    if(x<=25)
      cnt++;
  }
  cout<<min(cnt,max_cnt)<<'\n';
}