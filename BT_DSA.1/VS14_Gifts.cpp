#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;

int n, a[MAXN], k, res;

void input()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

int bs(int l, int r, int x)
{
    int res = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(a[mid] <= x){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

void solve()
{
    input();
    
    sort(a + 1, a + n + 1);
    a[n + 1] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= k) continue;
        int p = bs(1, n + 1, k - a[i]);
        if(p == -1) continue;
        if(a[p] == a[i]) p--;
        res = max(res, a[i] + a[p]);
    }
    cout << res;
}

int main()
{
    fastio
    solve();
    return 0;
}