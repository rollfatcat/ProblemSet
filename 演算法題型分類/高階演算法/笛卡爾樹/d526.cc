// 利用『笛卡爾樹』的概念達成二分樹的建立方式
/* 笛卡爾樹屬於一種二元樹，每個節點為<key,value>，
 * 只看 key 時笛卡爾樹是一棵二元搜尋樹，而看 value 時是一個最大堆 (或者是最小堆)
 * (1) 如何建立笛卡爾樹？
 * 假使已經對於 key 值由小到大排序(升排序)，那麼將點依序插入笛卡爾樹就能保證的是－由於要符合二元搜尋樹，
 * 新加入的點一定是這棵樹某個節點的右節點。知道這一點後，再往前考慮前一次插入的點
 * (它原本也符合再某節點的右節點)，往這個節點往上爬，直到符合最大堆(性質 node.v > new_insert.v)，
 * 這時將這個節點的右子樹移到新加入節點的左子樹 (此時符合二元搜尋樹的性質，也保有原本堆的性質)。
 * (2) 笛卡爾樹的問題(極端情況) => ZJ-b346
 * 往上爬的次數不超過節點個數，因為每個節點只會從右子樹換到左子樹。
 * 均攤下O(n)(每個節點只會從右子樹推到左子樹一次，因此最多 n 次)
 * (3) 如何轉換問題？
 * 我們接著將"按照順序插入的 BST"轉換成建造笛卡爾樹，
 * key 值依舊為輸入的元素大小，而 value 則訂為輸入順序，根據 key 值為一個二元搜尋樹，
 * 根據 value 建造一個最小堆，那麼仔細思考可以得到與原本相同的二元搜尋樹。
 * (4) 成本分析：建造笛卡爾樹只需要花 O(N) 時間，但建造前必須根據 key 排序O(N㏒N)，所以複雜度為 O( N㏒N )
 */

#include<bits/stdc++.h>
using namespace std;

struct NODE{
  int key, value;
  int lson, rson, parent;
  NODE(int k=0,int v=0,int l=0,int r=0,int p=0):key(k),value(v),lson(l),rson(r),parent(p){}
}node[1001];
void InsertCartesianTree(int index) {
  int now=index-1;
  while( node[now].value>node[index].value )
    now=node[now].parent;

  node[ node[now].rson ].parent=index;
  node[index].lson=node[now].rson;
  node[now].rson=index;
  node[index].parent=now;
}
void PreOrder(int now) {
  if(now==0)    return;
  printf("%d ", node[now].key);
  PreOrder(node[now].lson);
  PreOrder(node[now].rson);
}
int main() {
  int N;
  pair<int, int> org[1001];
  while(scanf("%d", &N)!=EOF){
    for(int x,i=1; i<=N; i++)
        scanf("%d",&x),
        org[i]=make_pair(x,i); // 輸入的數值當作key，輸入的順序當作value
    sort(org+1,org+1+N);

    node[0]=NODE(0,-1);
    for(int i=1; i<=N; i++)
      node[i]=NODE(org[i].first,org[i].second);

    for(int i=1; i<=N; i++)
      InsertCartesianTree(i);
    //for(int i=0;i<=N;i++)
    //  printf("%d %d %d %d %d\n",node[i].key,node[i].value,node[node[i].parent].key,node[node[i].lson].key,node[node[i].rson].key);

    PreOrder(node[0].rson);
    puts("");
  }
}