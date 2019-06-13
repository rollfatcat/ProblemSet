// 避免overflow的GCD，同 d134-uva00530
/* (1) 巴斯卡三角形加法
 * (2) 分子對分母每個數做GCD，把可以約分的部分相除
 */
#include<iostream>
#include<vector>
using namespace std;

int GCD(int a, int b){ return(b)?GCD(b,a%b):a; }
int main(){
  //
  int N, M, maxM, minM, num;
  while(cin>>N>>M and N){
    if(N-M>M) maxM=N-M, minM=M;
    else  maxM=M, minM=N-M;
    vector<int> n;
    for(int i=2;i<=minM;i++)
      n.push_back(i);
    int ans=1;
    for(int i=maxM+1;i<=N;i++){
      num=i;
      for(int j=0;j<n.size() and num>1;j++){
        int x=(num>n[j])?GCD(num,n[j]):GCD(n[j],num);
        if(x>1) num/=x, n[j]/=x;
      }
      ans*=num;
    }
    cout<<ans<<endl;
  }
}