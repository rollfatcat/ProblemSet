/* 給定Ｎ個科目(該科目對應的分數和學分)，根據平均分數輸出字串和平均？
 * 解題關鍵：加速讀取( getchar_unlocked() )
 */
#include<stdlib.h>
#include<stdio.h>
using namespace std;

const int MaxN=5e6;
/* 成績不存在負數，所以讀取第一個字元時不用判斷是不是'-' */
inline bool scanInt(int &x){ 
    char c;for(x=0;'0'<=(c=getchar_unlocked()) and c<='9'; x=(x<<3)+(x<<1)+c-'0'); 
    return c!=EOF; 
}

int main(){
	int sum_score=0, sumC=0;
    int G, C;
    while( scanInt(G) & scanInt(C) )
        sumC+=C, sum_score+= G*C;  
    int avg=sum_score/sumC;
    puts( (avg>=60)?"Oh wow! You pass it!":"YEEEEEE!!!" );
    if(avg>=60) printf("%d\n",avg);
}