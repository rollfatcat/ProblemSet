// BackTrace
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MaxN 30
#define MaxW 20000

int N, W;
vector<int>w(MaxN);
int optimal_weight(){
  vector<int> c(W+1);
  for(int i=0; i<N; i++)
    for(int j=W; j>=w[i]; j--)
      c[j]=max(c[j], c[j-w[i]]+w[i]);
  return c[W];
}

int main(){
  cin>>W>>N;
  for(int i=0; i<N; i++)
    cin>>w[i];
  cout<< W-optimal_weight() <<endl;
}