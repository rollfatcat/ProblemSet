// 用帕斯卡三角形加速累加的過程
#include<iostream>
#include<vector>
using namespace std;

int main(){
  // 產生帕斯卡三角形
  vector<int> pascal[51];
  pascal[1].push_back(1),
  pascal[1].push_back(1);
  for(int h=2;h<=50;h++){
    pascal[h].push_back(1);
    for(int j=1;j<pascal[h-1].size();j++)
      pascal[h].push_back((pascal[h-1][j-1]+pascal[h-1][j])%10);
    pascal[h].push_back(1);
  }
  // 主程式
  int checkBit[3]={1,0,0};
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(string ss; cin>>ss; ){
    int ST=1;
    for(; ST<=10000; ST++){
      vector<int> num;
      for(int i=0;i<ss.length();i++){
        vector<short> oneN;
        for(int N=ss[i]-'A'+ST; N; N/=10)
          oneN.push_back(N%10);
        for(int j=oneN.size()-1; j>=0; j--)
          num.push_back(oneN[j]);
      }
      int jump=num.size()-3, idx=0;
      while(idx<3){
        for(int j=1;j<pascal[jump].size();j++)
          num[idx]+=(num[idx+j]*pascal[jump][j]);
        if(num[idx]%10==checkBit[idx]) idx++;
        else  break;
      }
      if(idx==3)  break;
    }
    if(ST>10000)
      cout<<":("<<endl;
    else
      cout<<ST<<endl;
  }
}