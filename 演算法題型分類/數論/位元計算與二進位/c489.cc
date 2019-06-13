/* 二進位的妙用，很類似大公司的面試題(題目靈活但難以複製作法類推到其他題目)
 * 題目給定1e6個數字(最大是1e9)且保證『某一種數字』缺少『幾個』，要求輸出缺少的數字
 * 每種數字應該出現Ｍ個作法＋找出缺少的數字
 * (1) 找Ｍ的方法：在過程中不斷更新和紀錄最大/最小數值的個數，
 *     因為只會缺一種數字，所以取最大/最小個數中最大的數字即是Ｍ
 * (2) 找出缺少的數字：(感謝inversion)
 *     將給定的數字們轉成二進位，然後求每個冪次各自的和，因為有一種紙包雞有缺，
 *     因此會導致在此種紙包雞的二進位表示法中那些為冪次之總和不為應有數量的倍數。
 */
#include<stdio.h>
using namespace std;
#define max(a,b) (a>b)?a:b

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int maxv=0, minv=1<<30;
  int max_cnt=0, min_cnt=0;
  int N, x;
  int cnt[32]={};

  scanInt(N);
  for(int i=0;i<N;i++){
    scanInt(x);
    if(maxv==x) max_cnt++;
    else if(maxv<x) maxv=x, max_cnt=1;
    if(minv==x) min_cnt++;
    else if(minv>x) minv=x, min_cnt=1;
    for(int j=0; x; j++,x>>=1)
      if(x&1)
        cnt[j]++;
  }
  int M=max(max_cnt,min_cnt);
  int lack=0;
  for(int i=0;i<=30;i++)
    if(cnt[i]%M)
      lack+=(1<<i);
  printf("%d\n",lack);
}