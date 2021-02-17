/* 牌堆一開始的順序是固定的，依照Ｎ個指令操作後輸出牌堆最上面的５張牌內容？ 
 * 解題關鍵：vector.insert() / vector.erase() 的使用
 *    模擬切牌的行為需要隨機存取指定位置 ... 使用 double link list 的成本不一定會比較省時。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
char name[52][5]={ 
    "SA","S2","S3","S4","S5","S6","S7","S8","S9","S10","SJ","SQ","SK",
    "HA","H2","H3","H4","H5","H6","H7","H8","H9","H10","HJ","HQ","HK",
    "DA","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK",
    "FA","F2","F3","F4","F5","F6","F7","F8","F9","F10","FJ","FQ","FK" };

int main(){
	int N, cmd, a, b, L;
	vector<int> p;
	while(scanf("%d\n",&N)!=EOF and N>0){
		// init
		vector<int> card(52);
		for(int i=0;i<52;i++)
			card[i]=i;
		// 根據操作指令模擬
		while(N-->0){
			scanf("%d %d",&cmd,&a);
			switch(cmd){
				case 1: // 將由上往下數到的第ａ張牌到第ｂ張牌放到牌堆的最上面
					scanf("%d",&b);
					p=vector<int>(card.begin()+a-1,card.begin()+b);
					card.erase(card.begin()+a-1,card.begin()+b);
					card.insert(card.begin(),p.begin(),p.end());
					break;
				case 2: // 將由上往下數到的第ａ張牌到第ｂ張牌放到牌堆的最下面
					scanf("%d",&b);
					p=vector<int>(card.begin()+a-1,card.begin()+b);
					card.erase(card.begin()+a-1,card.begin()+b);
					card.insert(card.end(),p.begin(),p.end());
					break;
				case 3: // 將牌堆由上往下數到第ａ張牌放到牌堆的最底層
					p=vector<int>(card.end()-a,card.end());
					card.erase(card.end()-a,card.end());
					card.insert(card.begin(),p.begin(),p.end());
					break;
				case 4: // 將牌堆由下往上數到第ａ張牌放到牌堆的最上面
					p=vector<int>(card.begin(),card.begin()+a);
					card.erase(card.begin(),card.begin()+a);
					card.insert(card.end(),p.begin(),p.end());
					break;
			}
		}
		printf("%s %s %s %s %s\n",name[card[0]],name[card[1]],name[card[2]],name[card[3]],name[card[4]]);
	}
}