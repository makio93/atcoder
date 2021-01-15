#include <bits/stdc++.h>
using namespace std;

class FriendFinder {
public:
    int distance(string line) {
        int n = line.size();
        int sid = -1, fid = -1;
        for (int i=0; i<n; ++i) {
            if (line[i] == 'S') sid = i;
            else if (line[i] == 'F') fid = i;
        }
        return abs(sid-fid);
    }
};

int main(){
    return 0;
}
