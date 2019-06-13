// 給一個 dounle形態的序列 找到最大值並記錄位置
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 1000

bool pos[MaxN];
double col[MaxN];
int main(){
  int T, N;
  cin>>T;
  while(T--){
    cin>>N;
    fill(pos,pos+N,0);
    bool flag=true;
    for(int times=0;times<N;times++){
      int max_pos=-1;
      double max_val=0.0;
      double total=0, num;
      for(int j=0;j<N;j++){
        cin>>num;
        num=abs(num);
        total+=num;
        if(max_val<num){
          max_val=num;
          max_pos=j;
        }
      }
      total-=max_val;
      if(pos[max_pos] or total>=max_val)
        flag=false;
      pos[max_pos]=true;
    }
    if(flag)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
}