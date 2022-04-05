// 有趣的DFS暴力法
#include<iostream>
#include<cmath>
using namespace std;
#define MaxN 18
#define INF 0x7fffffffffffffff

// 狀態[P][Q]: 在P位數時能被2^Q整除的最大/最小
long long int base[MaxN];
long long int maxNum[MaxN][MaxN];
long long int minNum[MaxN][MaxN];
void DFS(int p,long long int num){
  if(p==MaxN) return;
  long long int num1=10*num+1, num2=10*num+2;
  for(int i=1;i<MaxN and (num1%base[i]==0);i++){
    if(maxNum[p][i]<num1) maxNum[p][i]=num1;
    if(minNum[p][i]>num1) minNum[p][i]=num1;
  }
  for(int i=1;i<MaxN and (num2%base[i]==0);i++){
    if(maxNum[p][i]<num2) maxNum[p][i]=num2;
    if(minNum[p][i]>num2) minNum[p][i]=num2;
  }
  DFS(p+1,num1);
  DFS(p+1,num2);
}

int main(){
  for(int i=1;i<MaxN; base[i]=pow(2,i), i++)
    for(int j=1;j<MaxN;j++)
      maxNum[i][j]=0, minNum[i][j]=INF;
  DFS(1,0);

  int T, p, q;
  cin>>T;
  for(int caseNum=1;T--;caseNum++){
    cin>>p>>q;
    cout<<"Case "<<caseNum<<": ";
    if(minNum[p][q]==INF and maxNum[p][q]==0)
      cout<<"impossible\n";
    else if(minNum[p][q]==maxNum[p][q])
      cout<<minNum[p][q]<<endl;
    else
      cout<<minNum[p][q]<<' '<<maxNum[p][q]<<endl;
  }
}