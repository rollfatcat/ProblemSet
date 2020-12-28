// 暴力窮舉三條邊看能不能構成直角三角形，
// 可以接a858 說明不一定要暴力解可以用反推的
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T, N, L[100];
  for(cin>>T; T--;){
    cin>>N;
    for(int i=0;i<N;i++)
      cin>>L[i];
    sort(L,L+N);
    int cnt=0;
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        for(int k=j+1;k<N;k++)
          cnt+=( (L[i]*L[i]+L[j]*L[j])==(L[k]*L[k]) );
    cout<<cnt<<endl;
  }
}