// 經典題的小變形, n(1 ≤ n ≤ 30000) and k=2
#include<iostream>
using namespace std;

int f[30001]={0};
int josephus(int n){
  if(f[n]==0){
    int m=0, t=2;
    for( ;t<=n;t++)
      m=(m+2)%t;
    f[n]=m+1;
  }
  return f[n];
}
int main(){
  int T, n, s, t;
  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    for(cin>>n, s=josephus(n), t=0; n!=s; t++)
      n=s,  s=josephus(n);
    cout<<"Case "<<caseNum<<": "<<t<<' '<<n<<endl;
  }
}