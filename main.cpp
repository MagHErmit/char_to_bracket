#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



using std::unordered_map;
using std::cout;
using std::endl;
using std::string;

string char_to_bracket(string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    unordered_map<char, bool> map;
    string res;
    for(auto& c:s)
        map.find(c) == map.end() ? map[c] = false : map[c] = true;
    for(auto& c:s)
        res.push_back(map[c] ? ')' : '(');
    return res;
}

TEST_CASE( "swap char to bracket_basic" ) {
    REQUIRE(char_to_bracket("din") == "(((");
    REQUIRE(char_to_bracket("recede") == "()()()");
    REQUIRE(char_to_bracket("Success") == ")())())");
    REQUIRE(char_to_bracket("(( @") == "))((");
}
TEST_CASE( "swap char to bracket_advanced" ) {
    REQUIRE(char_to_bracket("") == "");
    REQUIRE(char_to_bracket("abacaba") == ")))()))");
    REQUIRE(char_to_bracket("SsAbbhg") == "))())((");
}