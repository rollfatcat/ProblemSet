// 利用 map<>+pair<> 紀錄斜率和重複的個數

#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, x[700], y[700];
  cin>>caseT>>ws;
  while(caseT--){
    string line;
    int N=0, group[700];
    while(getline(cin,line)){
      stringstream ss(line);
      if(ss>>x[N]) // 至少有讀取到一個數字時則繼續否則跳出迴圈結束讀取
        ss>>y[N++];
      else
        break;
    }
    // 枚舉基點，計算其他點和基點形成的斜率是否相同
    // 記得約分和額外處理水平和垂直時的斜率問題
    int maxCnt=1;
    for(int i=0;i<N;i++){
      map< pair<int,int>,int > table;
      pair<int,int> vec;
      for(int j=i+1;j<N;j++){ // <- 枚舉時若順位前面的點和目前的點形成的向量有其他點共線時，後面的點和現在點構成的向量必定被計算過

        int dx=x[i]-x[j];
        int dy=y[i]-y[j];
        if(dx==0)      vec=make_pair(0,1);
        else if(dy==0) vec=make_pair(1,0);
        else{
          int GCD=__gcd(dx,dy);
          vec=make_pair(dx/GCD,dy/GCD);
        }
        if(table.find(vec)!=table.end())
          table[vec]++,
          maxCnt=max(maxCnt,table[vec]);
        else
          table[vec]=1;
      }
    }
    cout<<maxCnt+1<<endl;
  }
}