// Qsort+Queue版本

#include<bits/stdc++.h>
using namespace std;

const int MAXN=30001;
int num_idx, N;
int num[MAXN];
queue<long> Q;
inline long LeastNumber(){
  if(Q.empty())
    return num[num_idx++];
  if(num_idx==N or Q.front()<=num[num_idx]){
    int rem=Q.front(); Q.pop();
    return rem;
  }
  return num[num_idx++];
}
int main(){
  scanf("%d",&N);

  for(int i=0;i<N;i++)
    scanf("%d",&num[i]);
  // 採用一般的Qsort
  sort(num,num+N);
  // 每次從兩個Queue裡面選小的合併後丟到Q裡面
  num_idx=0;
  long sum=0, min_one, min_two;
  for(int t=1; t<N; t++){
    min_one=LeastNumber(),
    min_two=LeastNumber(),
    sum+=min_one+min_two;
    Q.push(min_one+min_two);
  }
  printf("%ld\n",sum);
}