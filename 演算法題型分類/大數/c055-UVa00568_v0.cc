// 輸出最後一個從右邊數來不為0的數字
/* 初始想法：滾動陣列紀錄前一個和這一個，只紀錄題目要求的最後一位不為0的數字即可
 * (1)數論解：對於2和5的因數抽出來，一個2和一個5可以相消，最後再乘回去即可
 * (2)數論解：只需要保留後6位，因為10000以內擁有最多因數5的乘數是3125(5^5)，相乗後可能會出現0故預留6位
 * 規律解請參考：c901，範圍擴大到10^15 上述的方法皆不管用
 */

#include<iostream>
#include<vector>
using namespace std;
#define MaxN 10001
vector<int> lastBit(MaxN);
vector<long> num[2];
int main(){
  lastBit[0]=lastBit[1]=1;
  num[1].push_back(1);
  int base=100000000;
  for(int idx=2;idx<=10000;idx++){
    bool now=idx&1, pre=1^now;
    int carry=0; num[now].clear();
    for(int i=0;i<num[pre].size();i++)
      num[now].push_back(num[pre][i]*idx+carry),  carry=num[now][i]/base,  num[now][i]%=base;
    if(carry) num[now].push_back(carry);
    long tmp;
    for(tmp=0;num[now][tmp]==0;tmp++);
    for(tmp=num[now][tmp];tmp%10==0;tmp/=10);
    lastBit[idx]=tmp%10;
  }
  ios::sync_with_stdio(0), cin.tie(0);
  for(int n,t=0;cin>>n;t++)
    printf("%d -> %d\n",n,lastBit[n]);
}