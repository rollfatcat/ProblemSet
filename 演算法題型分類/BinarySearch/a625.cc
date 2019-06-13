// 二分搜尋練習,  不需要處理精確度
// 輸入的範圍是1.0~5.2, 反推出n最大是277
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define Pn 0.0001

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  //
  vector<double> sum;
  sum.push_back(0.5);
  for(int i=3; sum.back()-5.2<Pn ;i++)
    sum.push_back(sum.back()+1.0/i);
  //
  for(double c; cin>>c; ){
    if(c-sum.front()<Pn){ cout<<"1 card(s)"<<endl; continue; }
    if(c-sum.back()>Pn){ cout<<"276 card(s)"<<endl; continue; }
    int l=0, r=sum.size()-1, m;
    while(l<=r){
      m=(l+r)/2;
      if(sum[m]==c) break;
      else if(sum[m]>c) r=m-1;
      else l=m+1;
    }
    cout<<(m+1)<<" card(s)"<<endl;
  }
}