#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;
const int base = 173;
const ll INF = 1e18;

ll n, k, a[MAXN];
deque < pair <int, int> > q;

void input()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1;
    for(int i = 2; i <= n + 1; i++)
    {
        if(a[i] != a[i - 1]) q.push_back({a[i - 1], i - j}), j = i;
    }
}

void solve()
{
    input();
    while(k--)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        cout << x << ' ';
        if(y - 1) q.push_back({x, y - 1});
    }
}

int main()
{
    fastio
    solve();
}