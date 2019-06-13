// BackTrace
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxN 10000

int N;
vector<int>w(MaxN);
vector<int>v(MaxN);
int optimal_weight(){
  int W=100;
  vector<int> c(W+1);
  for(int i=0; i<N; i++)
    for(int j=W; j>=w[i]; j--)
      c[j]=max(c[j], c[j-w[i]]+v[i]);
  return c[W];
}

int main(){
  cin>>N;
  for(int i=0; i<N; i++)
    cin>>w[i]>>v[i];
  cout<< optimal_weight() <<endl;
}