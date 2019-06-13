// 難在解法想不到= =...
#include<iostream>
#include<vector>
using namespace std;
#define MAXNum 100000
#define MAX(a,b) ((a>b)?a:b)

vector<int> child[MAXNum];
bool isRoot[MAXNum];
int md;

int DFS(int now){
  int numChild=child[now].size();
  if(numChild==0) // leaf nodes回傳0
    return 0;
  else if(numChild==1) // only one child 回傳 depth+1
    return DFS(child[now][0])+1;
  // 有兩個child
  int maxA, maxB, maxC;
  maxA=DFS(child[now][0])+1;
  maxB=DFS(child[now][1])+1;
  if(maxB>maxA){
    maxC=maxB;  maxB=maxA;  maxA=maxC;
  }
  for(int i=2;i<numChild;i++){
    maxC=DFS(child[now][i])+1;
    if(maxA<maxC)
      maxB=maxA, maxA=maxC;
    else if(maxB<maxC)
      maxB=maxC;
  }
  md=MAX(md,maxA+maxB);
  return maxA;
}
int FindRoot(int len){
  for(int i=0;i<len;i++)
    if(isRoot[i])
      return i;
}
int main(void){
  int N, a, b, root, rd;
  while(cin>>N){
    for(int i=0;i<N;i++){
      child[i].clear();
      isRoot[i]=true;
    }
    for(int i=N-1;i;i--){
      cin>>a>>b;
      child[a].push_back(b);
      isRoot[b]=false;
    }
    md=rd=0;
    root=FindRoot(N);
    rd=DFS(root);
    //cout<<rd<<','<<md<<endl;
    cout<<MAX(rd,md)<<endl;
  }
}