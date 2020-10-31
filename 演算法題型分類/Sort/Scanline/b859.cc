/* 給定Ｔ比測試資料，每筆資料包含Ｎ隻水貍的身高和體重和一開始將水梨交給第Ｓ號水貍，輸出水梨最後可能轉交到的號碼。
 * 任兩隻水貍間可能會發生轉移水梨的情況，只要另一隻水貍的身高更高且體重更重。
 * 解題關鍵：排序＋掃描線
 * 對比題目：d555二維平面上的極大點，差異在於排序規則
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxT=50;
const int MaxN=2e4;
int data[MaxN+1][2];
int ord[MaxN+1];

bool compare(int a,int b){
	return (data[a][0]==data[b][0])? data[a][1]>data[b][1]: data[a][0]<data[b][0];
}
int main(){
	int caseQ, N, S, uN;
  scanf("%d",&caseQ);
  while(caseQ--){
  	scanf("%d %d\n",&N,&S);
    for(int i=1;i<=N;i++)
  		scanf("%d %d\n",&data[i][0],&data[i][1]);
    /* 只需排序"比起Ｓ號水貍的身高更高且體重更重"的水貍號碼 */
    uN=0;
  	for(int i=1;i<=N;i++)
  		if(data[i][0]>data[S][0] and data[i][1]>data[S][1])
  			ord[uN++]=i;
    /* 若不存在"比起Ｓ號水貍的身高更高且體重更重"的水貍：代表水梨只會存在Ｓ手中 */
  	if(uN==0){ printf("1\n%d\n",S); continue; }
  	/* 排序規則：身高由低到高但(身高相同時)體重是重到輕 ... 和 d555-極大點的差異
     * 掃描線由後往前掃瞄時，若存在一個點的Ｙ座標＝目前水平線時也是屬於末點(無法傳遞給其他水貍)
     * 排序規則的設定是基於若存在數個點的Ｘ座標相同但Ｙ座標不同時只要高於水平線的點都要紀錄。
     * 相對於極大點的規則  若存在數個點的Ｘ座標相同但Ｙ座標不同時只紀錄Ｙ座標最高的點(由後往前掃所以Ｙ座標最高的排後面)。
     */
    sort(ord,ord+uN,compare);
  	vector<int> memo_ord;
  	memo_ord.push_back(ord[uN-1]);
  	int max_y=data[ord[uN-1]][1];
  	for(int i=uN-2;i>=0;i--)
  		if( data[ ord[i] ][1]>=max_y )
  			memo_ord.push_back(ord[i]),
  			max_y=data[ ord[i] ][1];
  	/* 題目要求輸出時需要依據輸入的號碼由小到大 */
  	sort(memo_ord.begin(),memo_ord.end());
  	printf("%lu\n",memo_ord.size());
  	for(int i=0;i<memo_ord.size();i++)
  		printf("%d ",memo_ord[i]);
  	putchar('\n');
  } 
}
/*
2
4 2
1 3
1 1
2 2
3 3

4 1
1 1
2 3
3 2
3 3
*/