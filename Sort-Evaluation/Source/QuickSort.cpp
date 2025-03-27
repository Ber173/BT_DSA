#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <random>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;
using namespace chrono;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long R(long long l, long long r) {
    return l + rd() % (r - l + 1);
}

int medianOfThree(vector<int> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);
    swap(arr[mid], arr[high]);
    return arr[high];
}

int patrition(vector<int>& a, int low, int high){
    //int pivot = medianOfThree(a, low, high);

    int random_index = low + rd() % (high - low + 1);
    swap(a[random_index], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(a[j] <= pivot){
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort(vector<int>& a, int low, int high){
    if(low < high){
        int pi = patrition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
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
    vector <string> filenames;

    for(int i = 1; i <= 10; i++)
    {
        filenames.push_back("../Make_Test/test" + to_string(i) + ".inp");
    }

       freopen("QuickSort.txt", "w", stdout);

    for(const string& filename : filenames){
        vector <int> data = readFile(filename);
        int n = int(data.size()) - 1;
        auto start = high_resolution_clock::now();
        QuickSort(data, 0, n);
        auto stop = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(stop - start).count() << '\n';
    }

    return 0;
}