// 先實作『直覺作法』=>做質因數分解，找到最長的子字串，輸出重複次數(44ms)
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(string ss; cin>>ss and ss!=".";){
    int len=ss.length(), subL;
    for(subL=1; subL<=len; subL++)
      if(len%subL==0){
        int t=len/subL, i, j;
        for(i=0; i<subL; i++){
          for(j=1; j<t and ss[j*subL+i]==ss[i]; j++);
          if(j!=t) break;
        }
        if(i==subL) break; //succuss
      }
    cout<<(len/subL)<<endl;
  }
}