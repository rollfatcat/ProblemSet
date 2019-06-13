// 給定一個數列(原本是等差數列)，但輸入的部分會遺漏某一個值並補上某個重複的數值
#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT;
  string input;
  cin>>caseT>>ws;
  while(caseT--){
    getline(cin,input);
    stringstream ss(input);
    int x, sum=0, minv=(1<<31)-1, maxv=1<<31;
    vector<int> number;
    while(ss>>x)
      sum+=x,
      minv=min(minv,x),
      maxv=max(maxv,x),
      number.push_back(x);
    sort(number.begin(),number.end());
    int should=(maxv+minv)*number.size()/2;
    int rd, idx=1;
    for(;idx<number.size() and number[idx-1]!=number[idx];idx++);
    cout<<should-sum+number[idx]<<' '<<number[idx]<<'\n';
  }
}
/*
2
7 9 1 3 7
3 9 1 3 7
5000 8000 9000 8000 7000
*/