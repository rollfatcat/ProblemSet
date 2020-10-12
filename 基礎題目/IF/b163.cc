/* 給定三個參數(ｐ１,ｐ２,ｐ３)和需要解壓縮的字串，輸出還原後的內容？
 * 解壓縮的條件(規則４)：只有當'-'左右兩邊都是數字 或 小寫字母且 ASCii Code 差值大於等於０才做替換。
 * ｐ１：解壓縮時輸出１＝小寫 ２＝大寫 ３＝'*'
 * ｐ２：重複的次數
 * ｐ３：１＝順向 ２＝逆向
 * 解題關鍵：簡單模擬
 * 解題盲點：題目只寫出了規則，並未說明判斷的順序，必須依據規則之間是否相互干擾自行推理出「判斷流程」
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=100;
char ss[MaxL+2];
inline bool Check_Side(char c1,char c2){
	return ('0'<=c1 and c1<='9' and '0'<=c2 and c2<='9' ) or
		   ('a'<=c1 and c1<='z' and 'a'<=c2 and c2<='z' );
}
inline bool UnCompress(int i){ return ss[i]=='-' and Check_Side(ss[i-1],ss[i+1]) and ss[i-1]<ss[i+1]; }
int main(){
  int p1, p2, p3, L;
  while(scanf("%d %d %d\n",&p1,&p2,&p3)!=EOF){
  	scanf("%s\n",ss);
  	putchar(ss[0]);
  	for(int i=1;ss[i]!='\0';i++){
  		/* 判定是否符合解壓縮的條件，不符直接輸出該字元，否則依據規則解壓縮 */
        if( UnCompress(i) ){
  			/* 若ｐ１是３直接輸出'*'構成的字串 */
              if(p1==3)
  				for(int j=ss[i-1]+1;j<ss[i+1];j++)
  					for(int k=1;k<=p2;k++)
  						putchar('*');
  			else{
                /* 根據ｐ１決定起始字元和停止字元 */
                char st_ch=ss[i-1]+1-(p1==2 and ss[i-1]>'9')*('a'-'A');
                char ed_ch=ss[i+1]-1-(p1==2 and ss[i-1]>'9')*('a'-'A');
                if(p3==1){ 
                    for(char c=st_ch;c<=ed_ch;c++)
                        for(int j=1;j<=p2;j++)
                            putchar(c);
                }else{
                    for(char c=ed_ch;c>=st_ch;c--)
                        for(int j=1;j<=p2;j++)
                            putchar(c);
                }
  			}
  		}else
  			putchar(ss[i]);
  	}
  	
  	putchar('\n');
  }
}