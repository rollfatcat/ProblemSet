// 1e3個點在一維座標分群(最多10群)，目標最小化群內的曼哈頓距離總和
/* 想法：一個聯絡站只會連向鄰近的地點，而不會有捨近求遠的情形，所以分群方式是
 * 連續的區間，目標是各個區域之間相鄰越遠越好？(20%)
 * 紀錄點和點之間的距離做排序，由大到小依序抓出分群的點
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005

int node[MAXN];
pair<int,int> line[MAXN];
int main(){
  int caseT;
  int node_Num, cluster_Num;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d%d",&node_Num,&cluster_Num);
    cluster_Num=min(cluster_Num,node_Num);
    for(int i=0;i<node_Num;i++)
      scanf("%d",&node[i]);
    sort(node,node+node_Num);
    for(int i=1;i<node_Num;i++)
      line[i-1]=make_pair(node[i]-node[i-1],i);
    sort(line,line+node_Num-1);
    vector<short> cut_point;
    int pivot=node_Num-2;
    for(int i=1;i<cluster_Num;i++)
      cut_point.push_back( line[pivot--].second );
    sort(cut_point.begin(),cut_point.end());

    long sum_dis=0;
    int pre_pos=0;
    for(int i=0;i<cut_point.size();i++){
      int mid_point=(pre_pos+cut_point[i]-1)>>1;
      for(int j=pre_pos;j<cut_point[i];j++)
        sum_dis+=abs(node[j]-node[mid_point]);
      pre_pos=cut_point[i];
    }
    int mid_point=(pre_pos+node_Num-1)>>1;
    for(int j=pre_pos;j<node_Num;j++)
      sum_dis+=abs(node[j]-node[mid_point]);
    printf("%ld\n",sum_dis);
  }
}
/*
1
5 3
-1 0 2 7 9
*/