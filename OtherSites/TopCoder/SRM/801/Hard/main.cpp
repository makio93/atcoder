#include <bits/stdc++.h>
using namespace std;

class SecondDiameters {
public:
     long long getSecondDiameters(vector<int> X, vector<int> Y) {
         int n = X.size();
         map<long long, map<int, set<int>>> dcnt;
         for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
             long long dist = (long long)(X[j]-X[i])*(X[j]-X[i]) + (long long)(Y[j]-Y[i])*(Y[j]-Y[i]);
             dcnt[dist][i].insert(j);
             dcnt[dist][j].insert(i);
         }
         long long ans = 0;
         for (int i=0; i<n; ++i) {
             vector<long long> mval;
             for (auto itr=dcnt.rbegin(); itr!=dcnt.rend(); ++itr) {
                 if ((int)(mval.size()) >= 2) break;
                 bool add = false;
                 for (auto itr2=itr->second.begin(); itr2!=itr->second.end(); ++itr2) {
                     if ((int)(mval.size())>=2 || add) break;
                     if (itr2->first == i) continue;
                     for (auto pi : itr2->second) {
                         if ((int)(mval.size())>=2 || add) break;
                         if (pi != i) {
                             if (!add && (mval.empty() || (!mval.empty()&&mval.back()!=itr->first))) {
                                 mval.push_back(itr->first);
                                 add = true;
                                 if ((int)(mval.size()) == 2) ans += mval.back();
                                 break;
                             }
                         }
                     }
                     if ((int)(mval.size())>=2 || add) break;
                 }
                 if ((int)(mval.size()) >= 2) break;
             }
         }
         return ans;
     }
};

int main(){
    return 0;
}
