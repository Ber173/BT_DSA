#include <bits/stdc++.h>
#define ll long long
#define fasito ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;
const int mod = 1e9 + 7;

int n, a[MAXN], x;
vector <int> res;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> x;
}

void solve()
{
    input();

    for(int i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            res.push_back(i);
        }
    }

    if(res.size()){
        cout << res.size() << '\n';
        for(int i = 0; i <= int(res.size()) - 1; i++)
        {
            cout << res[i] << ' ' << res[i] + 1 << '\n';
        }
    }
    else cout << 0;
}

int main()
{
    fasito
    solve();
}