#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, string>* data;
    unsigned long long* id = NULL;
    const string used = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (id == NULL) {
            mt19937_64 mt((int)time(NULL));
            id = new unsigned long long((unsigned long long)mt());
            data = new unordered_map<string, string>();
        }
        (*id) = ((*id) + 1) % (1ULL<<63);
        string target;
        unsigned long long ival = *id, cnum = used.size();
        for (int i=0; i<7; ++i) {
            target += (char)used[ival%cnum];
            ival /= cnum;
        }
        reverse(target.begin(), target.end());
        (*data)[target] = longUrl;
        return target;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (id == NULL) return "";
        if ((*data).find(shortUrl) == (*data).end()) return "";
        else return (*data)[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(){
    return 0;
}
