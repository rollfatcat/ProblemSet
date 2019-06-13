// 算生命靈數,並找出最短差距
// 生命靈數：將數字的各個位數加起來算總和

#include<iostream>
#include<cmath>
using namespace std;

int BitrhNum(string Y,string M,string D){
  int n=0, i;
  for(i=0;i<Y.length();i++)
    n+=Y[i]-'0';
  for(i=0;i<M.length();i++)
    n+=M[i]-'0';
  for(i=0;i<D.length();i++)
    n+=D[i]-'0';
  for(int N=n; N>=10; N=n)
    for( n=0; N>0; N/=10)
      n+=N%10;
  return n;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for(string Y, M, D; cin>>Y>>M>>D; ){
    int t=BitrhNum(Y,M,D), cnt, minD=10,  minI, tmpD;
    cin>>cnt;
    for(int i=1;i<=cnt;i++){
      cin>>Y>>M>>D;
      tmpD=abs(BitrhNum(Y,M,D)-t);
      if(tmpD<minD)
        minI=i, minD=tmpD;
    }
    cout<<minI<<endl;
  }
}