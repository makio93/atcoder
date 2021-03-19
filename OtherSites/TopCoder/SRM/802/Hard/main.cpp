#include <bits/stdc++.h>
using namespace std;

class DisjointDiceValues {
    long long calc(int a, int b) {
        if (b > a) return 0LL;
        if (a-b < b) return calc(a, a-b);
        long long res = 1;
        for (int i=a; i>a-b; --i) res *= i;
        for (int i=1; i<=b; ++i) res /= i;
        return res;
    }
public:
    double getProbability(int A, int B) {
        double res = 0.0;
        for (int i=1; i<=min(A,6); ++i) {
            double aval = 1.0, bval = 1.0;
            for (int j=0; j<i; ++j) aval *= (double)(i-j);
            if (A-i > 0) aval *= (double)calc(A-1, i-1);
            aval *= (double)calc(6, i);
            bval = ((double)pow(6.0, (double)B) - (double)pow((double)(6-i), (double)B));
            res += aval * bval;
        }
        res /= (double)pow(6.0, (double)(A+B));
        return res;
    }
};

int main(){
    DisjointDiceValues cl;
    int A, B;
    cin >> A >> B;
    cout << cl.getProbability(A, B) << endl;
    return 0;
}
