#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;
const int base = 173;
const ll INF = 1e18;

ll n, k, a[MAXN];

struct info{
    int x, y;
};

vector <info> res;

bool cmp(info A, info B)
{
    if(A.x == B.x) return A.y > B.y;
    return A.x < B.x;
}

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        res.push_back({x, y});
    }
}

void solve()
{
    input();
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i <= int(res.size()) - 1; i++){
        cout << res[i].x << ' ' << res[i].y << '\n';
    }
}

int main()
{
    fastio;
    solve();
}