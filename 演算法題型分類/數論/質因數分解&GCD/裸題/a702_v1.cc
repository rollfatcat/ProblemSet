// 1.4s
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime;
int main(){
  // 建質數表
  int Cprime[100000]={}, len=0;
  vector<int> prime;
  vector<int> p2;
  prime.push_back(2), p2.push_back(4);
  prime.push_back(3), p2.push_back(9);
  prime.push_back(5), p2.push_back(25);
  for(int N=7, idx;len<100000;N+=2){
    for(idx=0;p2[idx]<=N and N%prime[idx];idx++);
    if(p2[idx]>N){
      int prime_num=prime.size();
      if((N-4)==prime.back() or (N-4)==prime[prime_num-2])
        Cprime[len++]=N;
      prime.push_back(N), p2.push_back(N*N);
    }
  }
  //
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for(int n; cin>>n;)
    n--, cout<<'('<<Cprime[n]-4<<", "<<Cprime[n]<< ')'<<endl;
}