#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;
    string ans;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
        ans += s[i];
        if (s[i] == 'l' || s[i] == 'i' || s[i] == 'n' ||s[i] == 'k' || s[i] == 'e') {
            if (i + 3 < s.length() && s[i + 1] == 'b' && s[i + 2] == 't' && s[i + 3] == s[i]) {
                i += 3;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

//i love linbtnkezbas je dosadnbtna ovakemijaxaszxdbtddbtddbtddbtddbtddbtd
//ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd