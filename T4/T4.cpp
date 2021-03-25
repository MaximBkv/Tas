#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    const int size = 256;
    char s1[size];
    ifstream fin("input.txt");
    fin.getline(s1, size);
    fin.close();
    ofstream fout("output.txt");
    cout << "line: <" << s1 << ">" << endl;
    fout << "line: <" << s1 << ">" << endl;

    string s(s1);
    while (s[0] == ' ') s.erase(0, 1);
    while (s.back() == ' ' || s.back() == '\n' || s.back() == '\r')
        s.pop_back();
    while (s.find("  ") != string::npos)
        s.erase(s.find("  "), 1);
    while (s.find(" .") != string::npos)
        s.erase(s.find(" ."), 1);
    cout << "Remove extra space:   " << s << endl;
    fout << "Remove extra space:   " << s << endl;
    int pos;
    pos = s.rfind(' ');
    string LastW = s.substr(pos + 1);
    if (LastW.back() == '.') LastW.pop_back();
    pos = 0;
    while (pos < s.size()) {
        int pos1 = s.find_first_of(" ", pos);
        if (pos1 == (int)string::npos) break;
        if (LastW == s.substr(pos, pos1 - pos)) {
            s.erase(pos, pos1 - pos + 1);
        }
        else {
            pos = pos1 + 1;
        }
    }
    cout << "Remove last word:   " << s << endl;
    fout << "Remove last word:   " << s << endl;
    string s3;
    int sLen = s.size();
    pos = 0;
    while (pos < sLen) {
        int pos1 = s.find_first_of(" .", pos);
        if (pos1 == (int)string::npos) break;
        char ch = s[pos1 - 1];
        if (s3.size() > 0) s3.push_back(' ');
        while (pos < pos1) {
            if (s[pos] != ch) s3.push_back(s[pos]);
            pos++;
        }
        s3.push_back(ch);
        pos = pos1 + 1;
    }
    cout << "Extra task: <" << s3 << ">" << endl;
    fout << "Extra task: <" << s3 << ">" << endl;
    fout.close();
    return 0;
}
