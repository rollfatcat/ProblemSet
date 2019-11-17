#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int main(){
    int hour_to_day, min_to_hour, sec_to_min; // value ≤ 1e9
    scanf("%d %d %d",&hour_to_day,&min_to_hour,&sec_to_min);
    
    int N, x;
    int hour, min, sec;
    char ch;
    scanf("%d",&N);
    while(N--){
        scanf("%d%c%d%c%d",&hour,&ch,&min,&ch,&sec);
        scanf("%d",&x), hour+=x;
        scanf("%d",&x), min+=x;
        scanf("%d",&x), sec+=x;
        //
        min+=sec/sec_to_min, sec=sec%sec_to_min;
        hour+=min/min_to_hour, min=min%min_to_hour;
        hour=hour%hour_to_day;
        printf("%d:%d:%d\n",hour,min,sec);
    }
}
/*
 2 20 30
 3
 1:19:2 0 1 7
 0:5:5 1 13 25
 1:19:29 1 19 29

 1000 1000 1000
 1
 999:99:9 9 99 999
 */