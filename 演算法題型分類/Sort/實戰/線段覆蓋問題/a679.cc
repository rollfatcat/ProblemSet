// 題目要求計算『有重疊』的線段數量
// 枚舉所有線段的『終點』，二分搜尋可以覆蓋到的線段『起點』加總所有的數量。
#include<iostream>
#include<algorithm>
using namespace std;

int N, num[30000];
struct nn{
  int st,ed;
  bool operator<(const nn &other)const{ return (st<other.st) or (st==other.st and ed<other.ed); }
} line[30000];
inline bool scanInt(int &x){
  char c=getchar();
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
bool compare(int a,int b){ return line[a].st<line[b].st; }
int main(){
  for(int caseN=1; scanInt(N);caseN++){
    for(int i=0;i<N;i++)
      scanInt(line[i].st),
      scanInt(line[i].ed);
    sort(line,line+N);
    for(int i=0;i<N;i++)
      num[i]=line[i].st;
    int cnt=0;
    for(int i=0;i<N;i++)
      cnt+=lower_bound(num,num+N,line[i].ed)-num-i-1;
    printf("Case %d: %d\n",caseN,cnt);
  }
}