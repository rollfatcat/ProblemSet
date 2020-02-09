// vector 實作(0.48s) vs BIT(0.08s)
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return -x&x; }
int main(){
  int caseN, N, qN;
  for(scanInt(caseN);caseN--;){
    scanInt(N);
    vector<int> num;
    for(int i=1;i<=N;i++)
      num.push_back(i);
    // 第一個數字最容易處理，方便輸出就獨立出來
    scanInt(qN);
    printf("%d",num[qN]);
    num.erase(num.begin()+qN);
    for(int i=1;i<N;i++){
      scanInt(qN);
      printf(" %d",num[qN]);
      num.erase(num.begin()+qN);
    }
    puts("");
  }
}