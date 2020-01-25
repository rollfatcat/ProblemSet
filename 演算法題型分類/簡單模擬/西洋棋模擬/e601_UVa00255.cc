/* 題目給定 King 和 Queen 在棋盤上的位置後，詢問當 Queen 移動到指定位置後的狀態
 * 題目麻煩的點在於需要觀察測資並設定對應情況的邏輯判斷的順序
 * 將不同情況一一排除後，『有些條件』就不需要判斷。
 */
#include<bits/stdc++.h>
using namespace std;
 
struct NODE{
	int x, y;
	NODE(int x=-1,int y=-1):x(x),y(y){}
} King, nowQ, nxtQ;
 
inline int JudgeStatus(int king,int nowq,int nxtq){
	/* Illegal state：King 和 nowQueen 重疊 */
    if(king==nowq) return 0;
	/* Illegal move：
     * (1) King 和 nxtQueen 重疊 
     * (2) Queen 位置未改變( nowQueen=nxtQueen )
     * (3) nowQueen 無法『沿著直線』移動到 nxtQueen
     * (4) nowQueen 移動到 nxtQueen 的路徑上存在 King 
     */
    if(nowq==nxtq or king==nxtq) return 1;
	King=NODE(king>>3,king&7);
	nowQ=NODE(nowq>>3,nowq&7);
	nxtQ=NODE(nxtq>>3,nxtq&7);
	if(nowQ.x!=nxtQ.x and nowQ.y!=nxtQ.y) return 1;
	if(((King.x==nowQ.x and  King.x==nxtQ.x) or (King.y==nowQ.y and King.y==nxtQ.y)) and nowq>king and king>nxtq) return 1;
	if(((King.x==nowQ.x and  King.x==nxtQ.x) or (King.y==nowQ.y and King.y==nxtQ.y)) and nxtq>king and king>nowq) return 1;
	/* Move not allowed：nxtQueen 移動到 King 的『旁邊』，此時不需要考慮：( 17 49 9 ) */
    if(King.x==nxtQ.x and abs(King.y-nxtQ.y)==1) return 2;
	if(King.y==nxtQ.y and abs(King.x-nxtQ.x)==1) return 2;
    /* Stop：nxtQueen 封鎖所有 King 可以移動的位置，這種情況只存在(0,9)(7,14)(56,49)(63,54)這４種組合 */
	if(king== 0 and nxtq== 9) return 4;
	if(king== 7 and nxtq==14) return 4;
	if(king==56 and nxtq==49) return 4;
	if(king==63 and nxtq==54) return 4;
	/* Continue：nxtQueen 不會阻礙 King 的位移空間，屏除上述的情況即是 */
    return 3;
}
int main(){
	int king, nowq, nxtq;
	char out[5][20]={"Illegal state","Illegal move","Move not allowed","Continue","Stop"};
	while(scanf("%d %d %d",&king,&nowq,&nxtq)==3)
		puts(out[JudgeStatus(king,nowq,nxtq)]);
 
}