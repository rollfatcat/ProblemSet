// 原題型：BOZJ-1509：樹形動態規劃
// 兩次DFS
#include<bits/stdc++.h>
using namespace std;

const int MAXV=200001;
struct NN{ int n, v; };
vector<NN> Link[MAXV];
int main(){
  int N, M, a, b, v;
  scanf("%d%d",&N,&M);
  while(M--)
    scanf("%d%d%d",&a,&b,&v),
    Link[a].push_back((NN){b,v}),
    Link[b].push_back((NN){a,v});
}
/*
4 3
1 2 1
2 3 1
3 4 1
*/