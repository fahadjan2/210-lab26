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
void output(vector<vector<vector<milliseconds>>> &durations);

int main() {
    string filename = "codes.txt";
    vector<vector<vector<milliseconds>>> durations; //3D array
    
    vectorracer(filename, durations);
    listracer(filename, durations);
    setracer(filename, durations);

    output(durations);

    return 0;
}

void vectorracer(const string filename, vector<vector<vector<milliseconds>>> &durations) {
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

    //vector duration set
    vector<milliseconds> dur;
    dur.push_back(readduration);
    dur.push_back(sortduration);
    dur.push_back(insertduration);
    dur.push_back(deleteduration);

    return dur;
}

void setracer(const string filename, vector<vector<vector<milliseconds>>> &durations) {
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

   //duration set;
    durations.push_back;
    dur.push_back(insertduration);
    dur.push_back(deleteduration);

    return dur;
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

        //Struct duration set
        Durations dur;
        dur.read = readduration;
        dur.sort = sortduration;
        dur.insert = insertduration;
        dur.delet = deleteduration;
    }
    return dur;
}

//Outputs the three different durations
void output(Durations vDur, Durations lDur, Durations sDur) {
    //Output
    int ssortduration = -1;
    cout << "Operation    Vector\tList\tSet" << endl;
    cout << "Read\t\t" << vDur.read.count() << "\t" << lDur.read.count() << "\t" << sDur.read.count() << endl;
    cout << "Sort\t\t" << vDur.sort.count() << "\t" << lDur.sort.count() << "\t" << ssortduration << endl;
    cout << "Insert\t\t" << vDur.insert.count() << "\t" << lDur.insert.count() << "\t" << sDur.insert.count() << endl;
    cout << "Delete\t\t" << vDur.delet.count() << "\t" << lDur.delet.count() << "\t" << sDur.delet.count() << endl;
}