// 數學題
/* 解法：
 * 把數字分配的越小(試想如果每個group人數能一樣，那每組分成2或3乘積為最大)和越鄰近越好(如2,3,4,5..)。
 * 因此就從2開始，2,3,4,5,.....k，直到剩下的數left(=N-(1+2+3+...+k)) < (k+1)為止
 * ，那麼將left從k,k-1....往下分配，把每個數+1，如果分配到2如果left還有剩，再從k+1開始分配
 * ，使得每個數盡量靠近。
 */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int caseNum, n;
  int num[45], len;

  cin>>caseNum;
  while(caseNum--){
    cin>>n;
    len=0;
    for(int i=2; n>=0 ;i++, len++)
      num[len]=(n>=i)?i:n, n-=i;
    len--;
    for(int i=len-1;num[len]>0;num[len]--)
      num[i]++, i=(i==0)?(len-1):(i-1);
    cout<<num[0];
    for(int i=1;i<len;i++)
      cout<<' '<<num[i];
    cout<<endl;
    if(caseNum) cout<<endl;
  }
}