#include<bits/stdc++.h>
using namespace std;

const int MaxN=1001;
const int MaxL=1002001+1;

pair<short,short> A[MaxL];
pair<short,short> B[MaxL];
struct STATUS{
    bool IsWin;
    int col[MaxN];
    int row[MaxN];
    int crs[2], line;
    STATUS(bool Is=0,int L=0):IsWin(Is),line(L){
        fill(col,col+MaxN,0);
        fill(row,row+MaxN,0);
        crs[0]=crs[1]=0;
    }
} ;
int main(){
    int N, P, L, x;
    scanf("%d %d %d\n",&N,&P,&L);
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&x), B[x]=make_pair(i,j);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&x), A[x]=make_pair(i,j);
    
    int now, turn=L, posx, posy;
    STATUS AS=STATUS();
    STATUS BS=STATUS();
    for(; turn>0; turn--){
        scanf("%d",&now);
        // 確認Ａ的賓果表上是否有該數字後塗黑並更新連線數量
        posx=A[now].first, 
        posy=A[now].second;
        if(posx!=-1){
            AS.row[ posx ]++;
            if(AS.row[ posx ]==N)
                AS.line++;
            AS.col[ posy ]++;
            if(AS.col[ posy ]==N)
                AS.line++;
            if(posx==posy){
                AS.crs[0]++;
                if(AS.crs[0]==N)
                    AS.line++;
            }
            if(posx+posy==N-1){
                AS.crs[1]++;
                if(AS.crs[1]==N)
                    AS.line++;
            }
        }
        //  確認Ｂ的賓果表上是否有該數字後塗黑並更新連線數量
        posx=B[now].first, 
        posy=B[now].second;
        if(posx!=-1){
            BS.row[ posx ]++;
            if(BS.row[ posx ]==N)
                BS.line++;
            BS.col[ posy ]++;
            if(BS.col[ posy ]==N)
                BS.line++;
            if(posx==posy){
                BS.crs[0]++;
                if(BS.crs[0]==N)
                    BS.line++;
            }
            if(posx+posy==N-1){
                BS.crs[1]++;
                if(BS.crs[1]==N)
                    BS.line++;
            }
        }
        //
        AS.IsWin|=(AS.line>=P);
        BS.IsWin|=(BS.line>=P);
        if(AS.IsWin or BS.IsWin){
            printf("%d %d %d\n",now,BS.line,AS.line);
            if(AS.IsWin and BS.IsWin)
                puts("Draw");
            else if(AS.IsWin)
                puts("The winner is Alan");
            else
                puts("The winner is Baluteshih");
            break;
        }
    }
    for(; turn>0; turn--)
        scanf("%d",&now);
}
/*
    5 3 40
    21 7 1 6 5
    24 15 9 16 11
    14 22 2 17 10
    4 20 3 12 19
    13 8 25 18 23
    12 17 2 23 1
    3 14 7 10 21
    4 16 22 13 25
    11 9 15 24 8
    5 20 18 6 19
    1 20 10 21 14 23 15 19 11 18 24 6 25 16 17 22 9 7 12 5 4 3 13 2 8 29 39 32 26 35 30 37 38 31 34 27 33 36 28 40
    3 3 20
    10 19 3
    18 2 8
    14 15 4
    20 18 6
    13 2 14
    19 5 12
    5 11 20 19 3 8 16 15 4 18 17 9 14 2 6 1 7 13 12 10
 */