/* 如果有兩堆相同數目的石頭 => 先守的必輸
 * 如果有兩推不同數目的石頭 => 則先手必贏
 * (5,5) => (3,5) => (3,3) => (2,3) => (2,2) => (1,2) => (1,1) => (0,1) => 後手勝
 */
#include<stdio.h>
using namespace std;

int main(){
  for(int a,b; scanf("%d %d",&a,&b)!=EOF; )
    puts( (a==b)?"= =\"":">\\\\\\<");
}