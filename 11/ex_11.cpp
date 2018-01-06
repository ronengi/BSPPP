#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


bool is_whitespace(char ch, const string& w) {
    if (isspace(ch)) return true;
    for(char ws : w)
        if (ch == ws) return true;
    return false;
}

vector<string> split(const string& s, const string& w) {
    istringstream iss{s};
    ostringstream word;
    vector<string> v;
    for(char ch; iss.get(ch); ) {
        if (is_whitespace(ch, w)) {
            if(word.str().length() > 0)
                v.push_back(word.str());
            word.str("");
        }
        else
            word.put(ch);
    }
    if(word.str().length() > 0)
        v.push_back(word.str());
    return v;
}


int main() {
    vector<string> v;
    v = split("hello a.,'[]a", ",[");
    for(string s : v)
        cout << s << "\n";
}
