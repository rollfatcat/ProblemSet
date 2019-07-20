/* 題目等價於『括號配對』的合法狀態問題 
 * 過程中的左括號數量小於右括號的數量 且最後右括號數量必須和左括號數量一樣多
 * 利用一個變數記錄可以消耗的左括號『餘數』，過程中該變數值不能小於 0 且最後必須等於 0
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int caseT;
    scanf("%d\n",&caseT);
    while(caseT--){
        bool safe=true;
        int cnt=0;
        for(char ch;(ch=getchar_unlocked())=='Y' or ch=='N';safe&=(cnt>=0))
            (ch=='Y')?cnt++:cnt--;
        puts((safe and cnt==0)?"YES":"NO");
    }
}