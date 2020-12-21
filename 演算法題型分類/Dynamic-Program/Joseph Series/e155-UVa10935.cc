// Josephus Problem(題目需要輸出 kill 過程依照順序的號碼)
// 操作規則：丟掉最上面的那張牌，然後把目前最上面的那張牌放到牌堆的最下面。 => 喬瑟夫問題的『跳過』
// 考量Ｎ≤50，以下題解採用『模擬法』=> ZJe183-UVa10940(加強版)Ｎ≤5e5 (動態規劃解)

#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  while(scanf("%d",&N) and N){
    vector<short> number;
    for(int i=1;i<=N;i++)
      number.emplace_back(i);

    printf("Discarded cards: ");
    if(N>1) putchar('1');
    int p=0;
    while(number.size()>2)
      number.erase(number.begin()+p),
      p=(p+1)%number.size(),
      printf(", %d",number[p]);
    number.erase(number.begin()+p),
    printf("\nRemaining card: %d\n",number[0]);
  }
}