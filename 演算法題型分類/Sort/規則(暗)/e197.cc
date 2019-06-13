/* 題目規定每位學生每次倒回收時最多拿兩個桶子
 * 想法：貪婪法，紀錄 M 種回收區和各自回收區距離以及#桶子(0 ≦ M ≦ 1e5，0 ≦ dis ≦ 1e9，0 ≦ cnt ≦ 1e4 )
 * 由距離最遠排序，每趟取兩個桶子，這樣需要 #桶子/2 趟，個數是奇數要多走一趟
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001

struct DATA{
  int dis, cnt;
  bool operator<(const DATA &rhs)const{ return dis>rhs.dis; }
} data[MAXN];
int main(){
  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d%d",&N,&N);
    for(int i=0;i<N;i++)
      scanf("%d",&data[i].dis);
    for(int i=0;i<N;i++)
      scanf("%d",&data[i].cnt);
    sort(data,data+N);
    long ans_sum=0;
    for(int i=0;i<N;i++){
      ans_sum+=(long)data[i].dis*(data[i].cnt>>1)<<1;
      if(data[i].cnt&1)
        ans_sum+=data[i].dis<<1,
        data[i+1].cnt--;
    }
    printf("%ld\n",ans_sum);
  }
}
/*
2
3 3
3 2 1
2 2 2
1 5
1 5 4 3 2
2 1 1 1 2
*/