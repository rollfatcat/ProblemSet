/* 題目給訂一個數字(字串)需要找到距離目前數字差值最小的『合法』數字，輸出差值
 * 類似競賽題，需要自行觀察規律(規律不好找)
 */
#include<bits/stdc++.h>
using namespace std;

/* 輸出第一個出現『偶數』的位數，若無則輸出-1
 * 初始判斷輸入的數字是否即符合條件(若是則直接輸出0)
 */ 
inline int Test(char Nss[]){
    for(int i=0;Nss[i]!=0;i++)
        if( (Nss[i]&1)==0 )
            return i;
    return -1;
}

/* 將輸入的字串轉換成對應的數字(long型態)
 */
inline long ToNumber(char Nss[],long ret=0){
    for(int i=0;Nss[i]!=0;i++)
        ret=(ret<<3)+(ret<<1)+Nss[i]-'0';
    return ret;
}
/* 找到比現在這個數字還『大』的『合法』數字
 * (從最高位)找到最早出現『偶數』的位數後將將這個位數+1(最大的偶數是8，8+1=9) 而後面的位數都變成'1'
 */
inline long UppToNumber(char Nss[],int idx,long ret=0){
    for(int i=0;i<idx;i++)
        ret=(ret<<3)+(ret<<1)+Nss[i]-'0';
    ret=(ret<<3)+(ret<<1)+Nss[idx]+1-'0';
    for(int i=idx+1;Nss[i]!=0;i++)
        ret=(ret<<3)+(ret<<1)+1;
    return ret;
}
/* 找到比現在這個數字還『小』的『合法』數字
 * 難點：(從最高位)找到最早出現『偶數』的位數，這個位數是'0'時無法-1，須從這個位置向前面的位數『借位』(以維護前面的位數仍是奇數的特性)
 * 作法：目前位數-1，若出現小於'0'的情況則向前一位『借位』(前一位的數值-2)，直到(1)前一位的數值大於'0'或者(2)沒有前一位時
 * 這個位數之後的部分都變成'9'
 */
inline long LowToNumber(char Nss[],int idx,long ret=0){
    Nss[idx]--;
    int i=idx;
    while(i>0 and Nss[i]<'0')
        Nss[i]='9',Nss[--i]-=2;
    for(i=Nss[0]<'0';i<=idx;i++)
        ret=(ret<<3)+(ret<<1)+Nss[i]-'0';
    for(i=idx+1;Nss[i]!=0;i++)
        ret=(ret<<3)+(ret<<1)+9;
    return ret;
}
int main(){
    char Nss[22];
    while(scanf("%s",Nss)!=EOF){
        int odd_pos=Test(Nss);
        if(odd_pos==-1){ puts("0"); continue; }
        long now_Num=ToNumber(Nss);
        long upp_Num=UppToNumber(Nss,odd_pos)-now_Num;
        long low_Num=now_Num-LowToNumber(Nss,odd_pos);
        printf("%ld\n",(upp_Num>low_Num)?low_Num:upp_Num);
    }
}