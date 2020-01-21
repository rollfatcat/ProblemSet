/* 給定三邊, 問是否能夠成三角形
 * 構成三角形的條件：較短的兩邊長和須大於最長邊
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
    int caseT, len[3];
    scanf("%d\n",&caseT);
    while(caseT--){
        scanf("%d %d %d\n",&len[0],&len[1],&len[2]);
        sort(len,len+3);
        puts((len[0]+len[1]<=len[2])?"Wrong!!":"OK");
    }
}