#include <bits/stdc++.h>
#include <fstream>
#include <random>
#include <chrono>
#define ll long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#define task ""

using namespace std;

const int maxn = 1e6 + 6;
const int test = 1000;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    return l + rd() % (r - l + 1);
}

void make_test(int i){
    string name = "test" + to_string(i) + ".inp";
    ofstream inp(name);

    vector<ll> a;
    for(int i = 1; i <= 1e6; i++){
        ll z = Rand(-1e6, 1e6);

        a.push_back(z);
    }

    if(i == 1) sort(a.begin(), a.end());
    if(i == 2) sort(a.begin(), a.end(), greater<int>());

    for(auto x : a) inp << x << ' ';

    inp.close();
}

int main()
{
    srand(time(NULL));
    fastio
    for(int i = 1; i <= 10; i++){
        make_test(i);
    }
    return 0;
}