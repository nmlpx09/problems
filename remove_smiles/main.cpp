/*

remove smiles
:-(
:-)

*/

#include <string>
#include <iostream>

void f(std::string& s) {
    int j = 0;
    int i = 0;
    for (; i < s.size() - 3;) {
        s[j] = s[i];
        if (s[i] == ':' && s[i + 1] == '-' && (s[i + 2] == '(' || s[i + 2] == ')')) {
            i = i + 3;
        } else {
            j++;
            i++;
        }
    }
    if (s[i] != ':' || s[i + 1] != '-' || !(s[i + 2] == '(' || s[i + 2] == ')')) {
        for (; i < s.size();) {
            s[j] = s[i];
            i++;
            j++;
        }
    }
    s.resize(j);
}

int main() {
    std::string s = ":-)b";
    f(s);
    std::cout << s;
    return 0;
}