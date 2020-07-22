
#include <iostream>
#include <vector>
#include <set>


bool resolveProblem001(std::vector<int>& array, int k) {
    std::set<int> tempSolutions;
    
    for(int i = 0; i < array.size(); i++) {
        int element = array.at(i);

        if(tempSolutions.find(element) != tempSolutions.end()) {
            return true;
        }
        
        tempSolutions.insert(k - element);
    }
    return false;
}

void test() {
    std::vector<int> test1 = {1, 2, 3, 4, 5, 6, 7};
    assert(resolveProblem001(test1, 13));
    assert(resolveProblem001(test1, 12));
    assert(!resolveProblem001(test1, 14));
    assert(!resolveProblem001(test1, 1));
}

int main(int argc, const char** argv) {
    test();
    
    return 0;
}
