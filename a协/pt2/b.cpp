 #include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int mp[502][502];
int N,M;
bool combine[502];
const int MAX = 0x3f3f3f3f;
int minC= MAX;

void search(int &s,int &t){
    bool vis[502];
    int w[502];
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    int tmpj=1000;
    for(int i=0;i<N;i++){
        int max=-MAX;
        for(int j=0;j<N;j++){
            if(!vis[j]&&!combine[j]&&max<w[j]){
                max=w[j];
                tmpj=j;
            }
        }
        if(t==tmpj){minC=w[t];return;}
        vis[tmpj]=1;
        s=t,t=tmpj;
        for(int j=0;j<N;j++){
            if(!vis[j]&&!combine[j])
                w[j]+=mp[t][j];
        }
    }
    minC=w[t];
}

int mincut(){
    int ans=MAX;
    int s,t;
    memset(combine,0,sizeof(combine));
    for(int i=0;i<N-1;i++){
        s=t=-1;
        search(s,t);
        combine[t]=true;
        ans=ans>minC?minC:ans;
        for(int j=0;j<N;j++){
            mp[s][j]+=mp[t][j];
            mp[j][s]+=mp[j][t];
        }
//        printf("%d\n",ans);
    }
    return ans;

}

int main(){
    freopen("/Users/ecooodt/Desktop/c++ and acm/a协/pt2/b.txt","r",stdin);
    int s;
    while(cin>>N>>M>>s){
        memset(mp,0,sizeof(mp));
        int u,v,w;
        while(M--){
            scanf("%d %d %d",&u,&v,&w);
            mp[u-1][v-1]+=w;
            mp[v-1][u-1]+=w;
        }
        cout<<mincut()<<endl;
    }
    return 0;
}