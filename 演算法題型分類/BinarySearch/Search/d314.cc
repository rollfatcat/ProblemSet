/* 給定３種類型的操作方式，輸出對應的答案。
 * END   : 輸入結束
 * FIND K: 輸出目前數列內第Ｋ大的數字
 * GIVE X: 將Ｘ加入數列中
 * 題解關鍵：vector 指定位置插入＋二分搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxOptNum=2e5;
const int MaxV=1e7;
int main(){
  char ss[10];
  int N;
  vector<int> num;
  while(scanf("%s",ss)){
    if(ss[0]=='E') break; // 結束輸入
    scanf("%d",&N);
    if(ss[0]=='G'){ // GIVE：插入數字到目前數列中
      num.insert(lower_bound(num.begin(),num.end(),N),N);
    }else // FIND：查詢目前數列中第Ｋ大的數字
      printf("%d\n",num[num.size()-N]);
  }
}