#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string to;
        for (int i=0; i<n; ++i) {
            if (path[i] == '/') {
                to += "/";
                while (i+1<n && path[i+1]=='/') ++i;
            }
            else to += path[i];
        }
        swap(to, path);
        n = path.size();
        to.clear();
        for (int i=0; i<n; ++i) {
            if (path.substr(i,3)=="/./") {
                while (i+2<n && path.substr(i,3)=="/./") i += 2;
                --i;
            }
            else if (i==n-2 && path.substr(i,2)=="/.") {
                to += "/";
                ++i;
            }
            else to += path[i];
        }
        swap(to, path);
        n = path.size();
        to.clear();
        for (int i=0; i<n; ++i) {
            if (path.substr(i,4)=="/../" || (i==n-3&&path.substr(i,3)=="/..")) {
                if (!to.empty()) {
                    int pos = 0;
                    for (int j=(int)(to.size())-1; j>=0; --j) {
                        if (to[j] == '/') {
                            pos = j;
                            break;
                        }
                    }
                    to.erase(to.begin()+pos, to.end());
                }
                i += 2;
            }
            else to += path[i];
        }
        swap(to, path);
        n = path.size();
        to.clear();
        if (path.empty()) path += "/";
        if ((int)(path.size())>1 && path.back()=='/') path.pop_back();
        return path;
    }
};

int main(){
    Solution cl;
    string path;
    cin >> path;
    cout << cl.simplifyPath(path) << endl;
    return 0;
}
