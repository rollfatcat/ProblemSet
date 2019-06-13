// 模擬OS的cmd模式底下對『檔案』『目錄』進行新增或刪除的行為

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct NODE{
  short ID;
  bool type;
  string name;
  map<string,short> son;
  NODE(int ID=0,string ss="",bool type=1):ID(ID),name(ss),type(type){}
} node[505];
int Nnode=1, depth;
string opt, os_path;
vector<string> node_inpath;

void DFS_Print(string ss,int ID,int deep){
  if(deep==depth){
    cout<<ss<<node[ID].name;
    if(node[ID].type) cout<<"/";
    if(node[ID].son.size()) cout<<"+";
    cout<<'\n';
    return;
  }
  ss+=node[ID].name;
  if(node[ID].type) ss+='/';
  cout<<ss<<'\n';
  for(map<string,short>::iterator it=node[ID].son.begin(); it!=node[ID].son.end(); it++)
    DFS_Print(ss,it->second,deep+1);
}

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  node[0]=NODE();

  int N;
  cin>>N;
  while(N--){
    cin>>opt>>os_path;
    // 字串解析：轉換成每個節點
    node_inpath.clear();
    int pivot=0;
    for(int i=0;i<os_path.length();i++)
      if(os_path[i]=='/')
        node_inpath.push_back(os_path.substr(pivot,i-pivot)), pivot=i+1;
    if(os_path.size()>1)
      node_inpath.push_back(os_path.substr(pivot,os_path.length()));

    // 判斷路徑是否合法：注意不同的目錄底下可以放同樣名稱的目錄/檔案
    bool legal=(node_inpath[0]=="");
    int idx, now=0, pre=0;
    for(idx=1;legal and idx<node_inpath.size()-1; idx++){
      legal=(node[now].son.find(node_inpath[idx])!=node[now].son.end() and node[now].type);
      if(legal)  now=node[now].son[node_inpath[idx]];
    }
    if(!legal){ cout<<"ERROR\n"; continue; }

    /* 合法路徑有2種：(1)只有根目錄(2)根目錄＋往下Ｎ層
     * now 目前指向父節點
     * 需要根據"操作"來決定是否合法
     * 若是『新增』：路徑上的最後一個節點必須不存在且該節點不能是根目錄且父節點必須屬於『目錄』
     * 若是『刪除』：路徑上的最後一個節點必須  存在且該節點不能是根目錄且該節點沒有任一個子節點
     * 若是『查詢』：分兩個情況討論(1)查詢是根目錄時(2)根目錄＋往下Ｎ層的格式
     *               (2)初始的子字串要取到最後一個'/'(包含)
     */
    if(opt=="touch" or opt=="mkdir"){
      if(node[now].son.find(node_inpath.back())==node[now].son.end() and node[now].type
         and node_inpath.size()>1){
        node[Nnode]=NODE(Nnode,node_inpath.back(),opt=="mkdir");
        node[now].son[ node_inpath.back() ]=Nnode;
        Nnode++;
      }
      else
        cout<<"ERROR\n";
    }else if(opt=="rm" or opt=="rmdir"){
      if(node[now].son.find(node_inpath.back())!=node[now].son.end() and node[now].type
         and node[ node[now].son[node_inpath.back()] ].son.size()==0
         and node[ node[now].son[node_inpath.back()] ].type==(opt=="rmdir"))
        node[now].son.erase(node_inpath.back());
      else
        cout<<"ERROR\n";
    }
    else{ // 查詢
      cin>>depth;
      if(node_inpath.size()==1)
        DFS_Print("",0,0);
      else if(node[now].son.find(node_inpath.back())!=node[now].son.end() and node[now].type
              and node[node[now].son[node_inpath.back()]].type)
        pivot=os_path.find_last_of("/"),
        DFS_Print(os_path.substr(0,pivot+1),node[now].son[node_inpath.back()],0);
      else
        cout<<"ERROR\n";
    }
  }
}
