#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <random>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;
using namespace chrono;

const int maxn = 1e6 + 6;

void online(){
    fastio
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
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

vector <int> readFile(const string& filename){
    ifstream file(filename);
    vector <int> data;
    int val;

    if(file.is_open()){
        while(file >> val){
            data.push_back(val);
        }
        file.close();
    }
    else{
        cerr << "Unable to open file " << filename << '\n';
    }
    return data;
}

int main()
{
    freopen("MergeSort.txt", "w", stdout);
    vector <string> filenames;

    for(int i = 1; i <= 10; i++)
    {
        filenames.push_back("../Make_Test/test" + to_string(i) + ".inp");
    }

    for(const string& filename : filenames){
        vector <int> data = readFile(filename);
        int n = data.size() - 1;
        auto start = high_resolution_clock::now();
        MergeSort(data, 0, n);
        auto stop = high_resolution_clock::now();

       cout << duration_cast<milliseconds>(stop - start).count() << '\n';
    }

    return 0;
}