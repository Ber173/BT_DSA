#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <random>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;
using namespace chrono;

void online()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);   
}

int n;
vector <int> a;

void heapify(vector<int> & a, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void HeapSort(vector <int>& a){
    int n = a.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void print(){
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
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
    else {
        cerr << "Unable to open file " << filename << '\n';
    }
    return data;
}


int main()
{
    vector<string> filenames;

    for(int i = 1; i <= 10; i++){
        filenames.push_back("../Make_Test/test" + to_string(i) + ".inp");
    }

    freopen("HeapSort.txt", "w", stdout);

    for(const string& filename : filenames){
        vector<int> data = readFile(filename);
        auto start = high_resolution_clock::now();
        HeapSort(data);
        auto stop = high_resolution_clock::now();

        cout << duration_cast<milliseconds>(stop - start).count() << '\n';
    }
    return 0;
}