/* 給定一段文章，將文章中重複出現的"單字代換成號碼"後輸出，題目保證文章內只會出現'0'唯一的數字字元做為結尾符號。
 * 單字代換成號碼的規則：(1) 第一次出現的單字放到字典的最前面，並直接輸出該字串
 *                   (2) 重複的單字輸出號碼後從現在位置移除後放到字典最前面
 * 解題關鍵：單向鏈結
 */
#include<bits/stdc++.h> 
using namespace std;

int size=0;
const string empty_s="";
struct NODE{
	string ss;
	NODE *nxt;
	NODE(string s):ss(s),nxt(nullptr){}
} *head=new NODE("");

inline void Compress(string ss,int idx=0){
	/* (若存在重複字串)為了移除單向鏈結上的某個節點，需要紀錄的是"前一個位置"而判斷現在位置是否為 Null 
     * 線性搜尋鏈結查詢是否存在重複的單字
     * 若存在則輸出號碼後，紀錄該鏈結位置的記憶體位址並從現在位置移除    
     */
    NODE *now;
    for(NODE *pre=head; pre->nxt!=nullptr; pre=pre->nxt){
		idx++;
        if(pre->nxt->ss==ss){
			now=pre->nxt;
			pre->nxt=pre->nxt->nxt;
			printf("%d",idx);
			break;
		}
    }
	/* idx==size 代表不存在重複單字，直接輸出字串後產生新節點並讓 size+1 */
	if(idx==size){
		for(int i=0;ss[i]!='\0';i++)
			putchar(ss[i]);
		now=new NODE(ss);
        size++;
	}
    /* 放到最前面＝插入 head 和 head->nxt 之間 */
	now->nxt=head->nxt;
	head->nxt=now;
}
int main(){
	
	char ch;
	string now_s="";
    /* 題目保證文章內只會出現'0'唯一的數字字元做為結尾符號
     * 當讀取到的是字母時，加到目前字串中。
     *      若不是字母時，代表目前字串已經結束讀取需要根據該字串是否重複做壓縮，並且直接輸出不是字母的字元
     */
	while((ch=getchar())!='0'){
		if('A'<=ch and ch<='Z' or 'a'<=ch and ch<='z'){
			now_s+=ch;
		}else{
            if(now_s!=empty_s){
				Compress(now_s);
				now_s=empty_s;
			}
			putchar(ch);
		}
	}
}