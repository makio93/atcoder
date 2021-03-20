#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
    int tlive;
    map<string, int> id;
    map<int, string> unexpired;
public:
    AuthenticationManager(int timeToLive) {
        tlive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        id[tokenId] = currentTime + tlive;
        unexpired[id[tokenId]] = tokenId;
    }
    
    void renew(string tokenId, int currentTime) {
        if (id.find(tokenId) != id.end()) {
            if (id[tokenId] > currentTime) {
                unexpired.erase(id[tokenId]);
                id[tokenId] = currentTime + tlive;
                unexpired[id[tokenId]] = tokenId;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto itr = unexpired.begin();
        while (itr != unexpired.end()) {
            if (itr->first > currentTime) break;
            id.erase(itr->second);
            itr = unexpired.erase(itr);
        }
        return (int)(unexpired.size());
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

int main(){
    return 0;
}
