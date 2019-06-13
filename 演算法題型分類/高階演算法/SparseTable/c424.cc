/* 判斷I(a,b)的想法等同於：c299(https://zerojudge.tw/ShowProblem?problemid=c299)
 * Sparse Table：
 * 優點Query時間成本是O(1)，但建表時間成本是N㏒N，空間是N㏒N且不支援修改和更新
 * 解法：窮舉每個端點，端點兩個數必須是maxlocal和minlocal且差值剛好是長度便符合要求F(a,b)=I(a,b)
 * 總共 Query 4999+4998+...1 = 12497500次，且testcase約20個
 */
#include<iostream>
#include<cstring>
using namespace std;

int N, maxlocal, minlocal;
int maxST[15][5000]; // maxST[i][st]儲存區間[st, st+2ⁱ-1]的最大值
int minST[15][5000]; // minST[i][st]儲存區間[st, st+2ⁱ-1]的最小值
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void construct(){ // construct
  for(int h=0; (1<<h)<N; h++) // h<㏒N
    for(int st=0; st+(1<<h)<=N; st++) // 有st但不保證ed會落在N以內(更新時會出問題)
      maxST[h+1][st]=max(maxST[h][st],maxST[h][st+(1<<h)]),
      minST[h+1][st]=min(minST[h][st],minST[h][st+(1<<h)]);
}
inline void Query(int Ql,int Qr){
  int h=__lg(Qr-Ql+1);
  maxlocal=max(maxST[h][Ql],maxST[h][Qr-(1<<h)+1]);
  minlocal=min(minST[h][Ql],minST[h][Qr-(1<<h)+1]);
}
int main(){
  int T;
  for(scanInt(T);T--;){
    scanInt(N);
    for(int i=0;i<N;i++)
      scanInt(maxST[0][i]), minST[0][i]=maxST[0][i];
    construct();
    int cnt=0;
    for(int len=1;len<N;len++)
      for(int st=0,ed=st+len; ed<N; st++,ed++){
        int minNum=min(maxST[0][st],maxST[0][ed]);
        int maxNum=max(maxST[0][st],maxST[0][ed]);
        Query(st,ed);
        if((maxlocal-minlocal)==len and minlocal==minNum and maxlocal==maxNum)
          cnt++;
      }
    printf("%d\n",cnt);
  }
}