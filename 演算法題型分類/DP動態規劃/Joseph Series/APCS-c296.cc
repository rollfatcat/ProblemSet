// (20th 測資)極限測資：200000 999997 199998
/* 根據 K 決定是否用DP解法還是模擬移除的方法
 * 剩餘數字過少時就用DP解(參考uva01452)，否則就模擬移除即可
 * 透過觀察可以發現實際這題只需要『動態規劃』即可解出，
 * 但無法證實殺完 N-K+1 個人後下一個活著的號碼可以這樣解出
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, K, num[6];
  scanf("%d %d %d",&N,&M,&K);
  if(N-K<=4){
    vector<int>nodes;
    for(int i=0;i<N;i++)
      nodes.push_back(i+1);
    int idx=0;
    for(M--;K--;N--)
      idx=(idx+M)%N,
      nodes.erase( nodes.begin()+idx );
    printf("%d\n",nodes[idx%N]);
  }else{
    K=N-K;
    num[0]=0;
    int sumN=0, sumT;
    for(int i=1;i<=K;i++){
      sumN+=i, sumT=0;
      for(int j=0;j<i;j++)
        num[j]=(num[j]+M)%i,
        sumT+=num[j];
      num[i]=sumN-sumT; // <- i==num[i]
    }
    for(int t=K+1;t<=N;t++)
      for(int i=0;i<=K;i++)
        num[i]=(num[i]+M)%t;
    vector<int> List;
    for(int i=0;i<=K;i++)
      List.push_back(num[i]+1);
    sort(List.begin(),List.end());
    int idx=lower_bound(List.begin(),List.end(),num[K]+1)-List.begin();
    List.erase( List.begin()+idx );
    printf("%d\n",List[idx%K]);
  }
}