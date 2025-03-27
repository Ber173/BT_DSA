#include <bits/stdc++.h>
#include <chrono>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;
using namespace chrono;

const int maxn = 1e6 + 6;

void online(){
    fastio
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
}

int n;
vector <int> a;

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
}

void Merge(vector<int> & a, int l, int mid, int r){

    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector <int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int i = 0; i < n2; i++) R[i] = a[mid + i + 1];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) a[k] = L[i++];
        else a[k] = R[j++];
        k++;
    }

    while(i < n1) a[k] = L[i++], k++;
    while(j < n2) a[k] = R[j++], k++;       
}

void MergeSort(vector<int>& a, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) >> 1;

        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);

        Merge(a, l, mid, r);
    }
}

void solve(){
    input();
    MergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}

int main()
{
    online();
    auto start = high_resolution_clock::now();

    solve();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds> (stop - start);
    cout << '\n';
    cout << "thoi gian chay: " << duration.count() << " microsecond" << '\n';

    return 0;
}