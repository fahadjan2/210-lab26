// COMSC-210 | Lab 26 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void vectorracer(const string filename, vector<vector<vector<milliseconds>>> &durations);
void listracer(const string filename, vector<vector<vector<milliseconds>>> &durations);
void setracer(const string filename, vector<vector<vector<milliseconds>>> &durations);
void output(vector<vector<vector<milliseconds>>> durations);

int main() {
    string filename = "codes.txt";
    vector<vector<vector<milliseconds>>> durations; //3D array, holds [#run][# indicating either vect, set, list][# indicating read/sort/etc duration]
    //                                                                       0 = vect, 1 = set, 2 = list           0 = read, 1 = sort, 2 = insert, 3 = delete         
    
    //Resizing
    durations.resize(15);
    for (int i = 0; i < 15; i++) {
        durations[i].resize(3);
    }

    vectorracer(filename, durations);
    listracer(filename, durations);
    setracer(filename, durations);

    output(durations);

    return 0;
}

void vectorracer(const string filename, vector<vector<vector<milliseconds>>> &durations) {
    for (int i = 0; i < 15; i++) {
        vector<string> vect;
        //Read
        ifstream file(filename);
        auto start = high_resolution_clock::now();
        string value;
        while (file >> value) {
            vect.push_back(value);
        };
        auto end = high_resolution_clock::now();
        auto readduration = duration_cast<milliseconds>(end - start);

        //Sort
        start = high_resolution_clock::now();
        sort(vect.begin(), vect.end());
        end = high_resolution_clock::now();
        auto sortduration = duration_cast<milliseconds>(end - start);
            
        //Insert
        value = "TESTCODE";
        start = high_resolution_clock::now();
        auto it = vect.begin();
        advance(it, vect.size() / 2);
        vect.insert(it, value);
        end = high_resolution_clock::now();
        auto insertduration = duration_cast<milliseconds>(end - start);

        //Delete
        start = high_resolution_clock::now();
        it = vect.begin();
        vect.erase(it);
        end = high_resolution_clock::now();
        auto deleteduration = duration_cast<milliseconds>(end - start);

        //duration set
        durations[i][0].push_back(readduration);
        durations[i][0].push_back(sortduration);
        durations[i][0].push_back(insertduration);
        durations[i][0].push_back(deleteduration);
    }
    return;
}

void setracer(const string filename, vector<vector<vector<milliseconds>>> &durations) {
    for (int i = 0; i < 15; i++) {
        set<string> set;
        //Read
        ifstream file(filename);
        auto start = high_resolution_clock::now();
        string value;
        while (file >> value) {
            set.insert(value);
        };
        auto end = high_resolution_clock::now();
        auto readduration = duration_cast<milliseconds>(end - start);

        //Insert
        value = "TESTCODE";
        start = high_resolution_clock::now();
        auto it = set.begin();
        advance(it, set.size() / 2);
        set.insert(it, value);
        end = high_resolution_clock::now();
        auto insertduration = duration_cast<milliseconds>(end - start);

        //Delete
        start = high_resolution_clock::now();
        it = set.begin();
        set.erase(it);
        end = high_resolution_clock::now();
        auto deleteduration = duration_cast<milliseconds>(end - start);

        //duration set
        durations[i][1].push_back(readduration);
        durations[i][1].push_back(insertduration);
        durations[i][1].push_back(deleteduration);
    }
    return;
}

void listracer(const string filename, vector<vector<vector<milliseconds>>> &durations) {
    for (int i = 0; i < 15; i++) {
        list<string> list;
        //Read
        ifstream file(filename);
        auto start = high_resolution_clock::now();
        string value;
        while (file >> value) {
            list.push_back(value);
        };
        auto end = high_resolution_clock::now();
        auto readduration = duration_cast<milliseconds>(end - start);

        //Sort
        start = high_resolution_clock::now();
        list.sort();
        end = high_resolution_clock::now();
        auto sortduration = duration_cast<milliseconds>(end - start);

        //Insert
        value = "TESTCODE";
        start = high_resolution_clock::now();
        auto it = list.begin();
        advance(it, list.size() / 2);
        list.insert(it, value);
        end = high_resolution_clock::now();
        auto insertduration = duration_cast<milliseconds>(end - start);

        //Delete
        start = high_resolution_clock::now();
        it = list.begin();
        list.erase(it);
        end = high_resolution_clock::now();
        auto deleteduration = duration_cast<milliseconds>(end - start);

        //duration set
        durations[i][2].push_back(readduration);
        durations[i][2].push_back(sortduration);
        durations[i][2].push_back(insertduration);
        durations[i][2].push_back(deleteduration);
    }
    return;
}

//Outputs the three different durations
void output(vector<vector<vector<milliseconds>>> durations) {
    //Output
    int ssortduration = -1;
    for (int i = 0; i < 15; i++) {
        cout << "Run #" << i + 1 << ":" << endl;
        cout << "Operation    Vector\tList\tSet" << endl;
        cout << "Read\t\t" << durations[i][0][0].count() << "\t" << durations[i][2][0].count() << "\t" << durations[i][1][0].count() << endl;
        cout << "Sort\t\t" << durations[i][0][1].count() << "\t" << durations[i][2][1].count() << "\t" << ssortduration << endl;
        cout << "Insert\t\t" << durations[i][0][2].count() << "\t" << durations[i][2][2].count() << "\t" << durations[i][1][2].count() << endl;
        cout << "Delete\t\t" << durations[i][0][3].count() << "\t" << durations[i][2][3].count() << "\t" << durations[i][1][3].count() << endl;
        cout << endl;
    }
}