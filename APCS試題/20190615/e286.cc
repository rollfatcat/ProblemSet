#include<bits/stdc++.h>
using namespace std;

int main(){
    char msg[3][5]={"Lose","Tie","Win"};

    int now_score;
    int sum_scoreA=0;
    for(int i=0;i<4;i++)
        scanf("%d",&now_score),
        sum_scoreA+=now_score;
    int sum_scoreB=0;
    for(int i=0;i<4;i++)
        scanf("%d",&now_score),
        sum_scoreB+=now_score;
    printf("%d:%d\n",sum_scoreA,sum_scoreB);
    int A_win=sum_scoreA>sum_scoreB;
    
    sum_scoreA=sum_scoreB=0;
    for(int i=0;i<4;i++)
        scanf("%d",&now_score),
        sum_scoreA+=now_score;
    for(int i=0;i<4;i++)
        scanf("%d",&now_score),
        sum_scoreB+=now_score;
    printf("%d:%d\n",sum_scoreA,sum_scoreB);
    puts( msg[A_win+(sum_scoreA>sum_scoreB)] );
}