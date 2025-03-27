#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <random>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;
using namespace chrono;

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

    freopen("Sort.txt", "w", stdout);
    for(const string& filename : filenames){
        vector<int> data = readFile(filename);
        auto start = high_resolution_clock::now();
        sort(data.begin(), data.end());
        auto stop = high_resolution_clock::now();
        cout << duration_cast<milliseconds>(stop - start).count() << '\n';
    }
    return 0;
}