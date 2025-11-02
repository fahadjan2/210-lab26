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

struct Durations {
    milliseconds read, sort, insert, delet;
};

Durations vectorracer(const string filename, vector<string> &vect);
Durations listracer(const string filename, list<string> &list);
Durations setracer(const string filename, set<string> &set);
void output(Durations v, Durations l, Durations s);

int main() {
    string filename = "codes.txt";
    vector<string> vect;
    list<string> list;
    set<string> set;
    
    Durations vDur = vectorracer(filename, vect);
    Durations lDur = listracer(filename, list);
    Durations sDur = setracer(filename, set);

    output(vDur, lDur, sDur);

    return 0;
}

Durations vectorracer(const string filename, vector<string> &vect) {
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

    //Struct duration set
    Durations dur;
    dur.read = readduration;
    dur.sort = sortduration;
    dur.insert = insertduration;
    dur.delet = deleteduration;
    return dur;
}

Durations setracer(const string filename, set<string> &set) {
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

    //Struct duration set
    Durations dur;
    dur.read = readduration;
    dur.insert = insertduration;
    dur.delet = deleteduration;
    return dur;
}

Durations listracer(const string filename, list<string> &list) {
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