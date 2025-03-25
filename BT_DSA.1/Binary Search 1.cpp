#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;

int n, a[MAXN], x;

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
}

int res, cnt = 0;

void solve()
{
    input();
    int l = 1, r = n;
    while(l <= r)
    { 
        cnt++;
        int mid = (l + r) >> 1;
        if(a[mid] < x){
            res = mid;
            l = mid + 1;
        }
        else if(a[mid] == x)
        {
            res = mid;
            break;
        }
        else r = mid - 1;  
    }

    if(a[res] == x) {
        cout << res - 1 << '\n';
        cout << cnt;
    }
    else cout << -1;
}

int main()
{
    fastio
    solve();
}