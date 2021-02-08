#include <bits/stdc++.h>
using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */

class Iterator {
	struct Data;
	Data* data;
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
    vector<int> *pval;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) { pval = new vector<int>(); }
	int peek() {
        if (pval->empty()) pval->push_back(Iterator::next());
        return pval->back();
	}
	int next() {
        int res = 0;
        if (!pval->empty()) {
            res = pval->back();
            pval->pop_back();
        }
        else res = Iterator::next();
	    return res;
	}
	bool hasNext() const {
        if (!pval->empty()) return true;
        else return Iterator::hasNext();
	}
};

int main(){
    return 0;
}
