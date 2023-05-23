#include <iostream>
#include <cmath>
#include <vector>
#include<string>
#include <algorithm>
#include<cmath>

using namespace std;

bool isSelfDual(std::string s) {
    string delimiter = ",";
    string sub = "";
    int r_pos = s.rfind(",");
    for (int i = r_pos + 1; i < s.size(); i++) {
        sub += s[i];
    }
    int step = pow(2, ceil(log(stoi(sub)) / log(2)));
    string M(step, '0');
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        M[stoi(token)] = '1';
        s.erase(0, pos + delimiter.length());
    }
    M[stoi(s)] = '1';
    string M2 = M;
    reverse(M2.begin(), M2.end());
    for (int i = 0; i < M2.size(); i++) {
        if (M2[i] == '0')
            M2[i] = '1';
        else
            M2[i] = '0';
    }
    if (M2 == M)
        return true;
    else
        return false;
}

