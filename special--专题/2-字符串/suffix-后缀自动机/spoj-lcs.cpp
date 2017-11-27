/*
  ID: oodt
  PROG:
  LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>

using namespace std;

const int maxx=250050;
int n,m,k;
char a[maxx],b[maxx];
int ans = 0,cnt = 0,pos = 0;
int l = 0,r = 0;

const int CHAR = 26;
const int MAXN = 250010;
struct SAM_Node
{
    SAM_Node *fa,*next[CHAR]; int len;
    int id,pos;
    SAM_Nod e(){}
    SAM_Node(int _len) {
        fa = 0;
        len = _len;
        memset( next, 0,sizeof( next) );
    }
};
SAM_Node SAM_node[MAXN*2], *SAM_root, *SAM_last;
int SAM_size;
SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size] = SAM_Node(len);
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p) {
    SAM_node[SAM_size] = *p;
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init() {
    SAM_size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
    SAM_node[0].pos = 0;
}
void SAM_add(int x,int len) {
    SAM_Node *p = SAM_last, *np = newSAM_Node(p->len+1);
    np->pos = len;
    SAM_last = np;
    for(;p && !p->next[x];p = p->fa)
    p->next[x] = np;
    if(!p) {
        np->fa = SAM_root;
        return;
    }
    SAM_Node *q = p->next[x]; if(q->len == p->len + 1) {
        np->fa = q;
        return;
    }
    SAM_Node *nq = newSAM_Node(q); nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for(;p && p->next[x] == q;p = p->fa)
    p->next[x] = nq;
}
void SAM_build(char *s) {
    SAM_init();
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    SAM_add(s[i] - 'a',i+1);
}
//加入串后进行拓扑排序。
int topocnt[maxx];
SAM_Node *topsam[maxx*2];

int main()
{
#ifdef LOCAL
    freopen("/Users/ecooodt/Desktop/c++ and acm/special--专题/2-字符串/suffix-后缀自动机/spoj-lcs.txt","r",stdin);
#endif
    scanf("%s",a);
    scanf("%s",b);
    int n = strlen(a);
    SAM_build(a);
    memset( topocnt,0 ,sizeof(topocnt ));
    for(int i = 0;i < SAM_size;i++)
    topocnt [SAM_node[i].len]++ ;
    for(int i = 1;i <= n;i++)
    topocnt[i] += topocnt[i-1];
    for(int i = 0;i < SAM_size;i++)
    topsam[--topocnt[SAM_node[i].len]] = &SAM_node[i];

    return 0;
}
