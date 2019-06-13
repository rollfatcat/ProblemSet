// bitset 的長度必須宣告是『固定』，不能是變數
// 利用 bitset 的聯集和交集，用暴力法枚舉所有的組合即可。

#include<bits/stdc++.h>
using namespace std;

int main(){
  int num_item, num_attr;
  char ss[1030];
  while(scanf("%d %d",&num_item,&num_attr)==2){
    bitset<512> attr[num_item];
    for(int i=0; i<num_item; i++)
      scanf("%s",ss),
      attr[i]=bitset<512>(ss);
    int ret=0, cross, unions;
    for(int i=0;i<num_item;i++)
      for(int j=i+1;j<num_item;j++){
        cross =(attr[i]&attr[j]).count(),
        unions=(attr[i]|attr[j]).count();
        if( cross*5>=(unions<<2) )
          ret++;
      }
    printf("%.2lf\n",2.0*100.0*ret/num_item/(num_item-1));
  }
}