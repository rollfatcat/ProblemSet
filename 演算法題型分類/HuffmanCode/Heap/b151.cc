// PriorityQueue版本

#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
int main(){

  priority_queue<int,vector<int>,greater<int>> PQ;
  int N, x;

  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&x),
    PQ.push(x);
  int sum=0, min_one, min_two;
  while(N-->1){
    min_one=PQ.top(), PQ.pop();
    min_two=PQ.top(), PQ.pop();
    sum+=min_one+min_two;
    PQ.push(min_one+min_two);
  }
  printf("%d\n",sum);
}