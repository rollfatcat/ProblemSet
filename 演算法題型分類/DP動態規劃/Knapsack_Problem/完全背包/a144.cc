// 雖然題目保證 n<100，但測資不會這麼大
#include<iostream>
using namespace std;

int bag[100];
void Divide(int rem,int maxN,int num){
  if(rem==0 or maxN==1){
    for(int i=0;i<num;i++)
      cout<<bag[i]<<' ';
    for(int i=rem;i>0;i--)
      cout<<1<<' ';
    cout<<endl; return;
  }
  for(int i=maxN;i>0;i--)
    bag[num]=i, Divide(rem-i,min(i,rem-i),num+1);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n; cin>>n;)
    Divide(n,n,0);
}