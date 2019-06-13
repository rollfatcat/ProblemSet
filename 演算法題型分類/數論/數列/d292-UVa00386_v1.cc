// 3層for迴圈找組合找到先存, 之後照a的大小輸出：60ms
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int power[201];
struct set{ int b,c,d; };
int main(){
  vector<set> n[201];
  for(int i=2;i<=200;i++)
    power[i]=pow(i,3);
  for(int b=2;b<139;b++) // pow(8000000/3, 1/3)
    for(int c=b;c<159;c++) // pow(8000000/2, 1/2)
      for(int d=c;true;d++){
        int num=power[b]+power[c]+power[d];
        if(num>8000000) break;
        int root=ceil(pow(num,1.0/3.0));
        if(power[root]==num)
          n[root].push_back({b,c,d});
      }
  //
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for(int i=6;i<=200;i++)
    for(int j=0;j<n[i].size();j++)
      cout<<"Cube = "<<i<<", Triple = ("<<n[i][j].b<<","<<n[i][j].c<<","<<n[i][j].d<<")"<<endl;
}