#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;

map <int, bool> mp;
int n;

void input()
{
    cin >> n;
}

void solve()
{
    input();

    int j = 0, x;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        mp[x] = 1;
        while(mp[j]) j++;
        cout << j << ' ';
    }
}

int main()
{
    fastio
    solve();
    return 0;
}