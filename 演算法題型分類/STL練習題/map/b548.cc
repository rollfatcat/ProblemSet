#include<bits/stdc++.h>
using namespace std;

const int N=25; 
struct NODE{
    int x, y;
    NODE(int x=0,int y=0):x(x),y(y){}
};
map<int,NODE> board;
int col[5], row[5], crs[2], use[26];

int main(){
    
    for(int pos;scanf("%d",&pos)!=EOF;){
        board[pos]=NODE();
        for(int i=1;i<5;i++)
            scanf("%d",&pos), board[pos]=NODE(0,i);
        for(int i=1;i<5;i++)
            for(int j=0;j<5;j++)
                scanf("%d",&pos), board[pos]=NODE(i,j);
        fill(col,col+5,0);
        fill(row,row+5,0);
        fill(use,use+26,0);
        crs[0]=crs[1]=0;
        while(scanf("%d",&pos) and pos!=-1){
            use[pos]=1;
            row[board[pos].x]++;
            col[board[pos].y]++;
            if(board[pos].x==board[pos].y)   crs[0]++;
            if(board[pos].x+board[pos].y==4) crs[1]++;
        }
        NODE rec=NODE(0,-1);
				for(int i=1;i<=25;i++)
					if(use[i]==0){
						NODE tmp=NODE(i,0);
						if(row[board[i].x]==4) tmp.y++;
            if(col[board[i].y]==4) tmp.y++;
            if(board[i].x==board[i].y and crs[0]==4)tmp.y++;
            if(board[i].x+board[i].y==4 and crs[1]==4) tmp.y++;
          	if(tmp.y>rec.y) rec=tmp;
					}
				printf("%d\n",rec.x);
    }
}