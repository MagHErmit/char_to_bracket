#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::unordered_map;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s = "Success";
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    unordered_map<char, bool> map;
    for(auto& c:s) {
        if(map.find(c) == map.end())
            map[c] = false;
        else
            map[c] = true;
    }
    for(auto& c:s) {
        cout << (map[c] ? ')' : '(');
    }
}
