#include <bits/stdc++.h>
#define ll long long 
#define X first 
#define Y second 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int maxn = 5e5 + 6;
const int mod = 1e9 + 7;
const int base = 173;

vector <string> arr, Query;
vector <pair <int, int> > a[30];
string s;
pair <int, int> tmp;
int n, m, k;
bool check;
string s;

void online(){
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
}

void input(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> s;
        arr.push_back(s);
    }

    for(int i = 1; i <= k; i++){
        cin >> s;
        Query.push_back(s);
    }
}

bool check_hang(int i, int j, string pattern){
    int len = pattern.size();
    for(int k = 0; k < len; k++){
        if(arr[i][j + k] != pattern[k]) return 0;
    }
    return 1;
}

bool check_cot(int i, int j, string pattern){
    int len = pattern.size();
    for(int k = 0; k < len; k++){
        if(arr[i + k][j] != pattern[k]) return 0;
    }
    return 1;
}


void solve(){
    input();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            a[int(arr[i][j] - 'a')].push_back({i, j});
        }
    }

    for(int i = 0; i <= int(Query.size()) - 1; i++){
        int len = Query[i].size();
        check = 0;
        for(int j = 0; j <= int(a[Query[i][0]].size()) - 1; j++){
            tmp = a[int(Query[i][0] - 'a')][j];
            if(tmp.X + len - 1 < m) check = check_hang(tmp.X, tmp.Y, Query[i]);
            if(tmp.Y + len - 1 < n) check = check_cot(tmp.X, tmp.Y, Query[i]);
            if(check) break;
        }
        cout << check;
    }
}

int main(){
    online();
    fastio
    solve();
    return 0;
}