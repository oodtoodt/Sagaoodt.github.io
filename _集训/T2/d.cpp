#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 220000;
int unit;
int num[1111111],a[maxn];
long long tmp, ans[maxn];
struct Query
{
	int i, l, r;
	bool operator<(const Query &q)const
	{
		if (l / unit == q.l / unit) return r < q.r;
		return l / unit < q.l / unit;
	}
}query[maxn];
void insert(long long x)
{
	tmp -= num[x]*num[x] * num[x];
	++num[x];
	tmp += num[x]*num[x] * num[x];
}
void remove(long long x)
{
	tmp -= num[x]*num[x] * num[x];
	--num[x];
	tmp += num[x]*num[x] * num[x];
}
int main(){
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	unit = (int)sqrt((double)n);
	for (int i = 0; i < t; ++i)
	{
		query[i].i = i;
		scanf("%d%d", &query[i].l, &query[i].r);
	}
	sort(query, query + t);
	int l = 1, r = 1; 
	num[a[1]] = 1; tmp = a[1];
	for (int i = 0; i<t; ++i)
	{
		while (l < query[i].l) remove(a[l++]);
		while (l > query[i].l) insert(a[--l]);
		while (r>query[i].r) remove(a[r--]);
		while (r < query[i].r) insert(a[++r]);
		ans[query[i].i] = tmp;
	}
	for (int i = 0; i < t; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}