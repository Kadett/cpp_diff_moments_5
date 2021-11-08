#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <fstream>

using namespace std;


template<typename Iter>
void print_unique(Iter first, Iter last) {
    set<string> s;
    for_each(first, last, [&s](const auto &i) {
        s.insert(i);
    });
    for (const auto &i: s) cout << i << ' ';
}


int main() {
    list<string> sList{"Monday", "Monday",
                       "Tuesday", "Tuesday",
                       "Wednesday", "Wednesday",
                       "Thursday", "Thursday",
                       "Friday", "Friday",
                       "Saturday", "Saturday",
                       "Sunday", "Sunday"};
    vector<string> sVec(14);
    deque<string> sDeq(14);
    copy(sList.begin(), sList.end(), sVec.begin());
    copy(sList.begin(), sList.end(), sDeq.begin());

    cout << "Task 1:" << "\n\n";

    print_unique(sList.begin(), sList.end());
    cout << endl;
    print_unique(sVec.begin(), sVec.end());
    cout << endl;
    print_unique(sDeq.begin(), sDeq.end());
    cout << endl;
    cout << endl;
    cout << "Task 2:" << "\n\n";


    multimap<int, string> m;
    ifstream in("../text.txt");
    string str{};
    while (getline(in, str, '.')) {
        while (str[0] == ' ') str.erase(str.begin()); // Удаляю пробелы после точки
        m.insert({str.size(), str});
    }

    for(const auto& [key, val] : m){
        std:: cout << "size = [" << key << "]: " << val << endl;
    }

    return 0;
}
