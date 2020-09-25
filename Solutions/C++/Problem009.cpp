
#include <iostream>
#include <vector>
#include <algorithm>

int maxNonConsecutive(std::vector<int>& array) {
    int next = 0;
    int newNext = 0;
    int previous = array.at(0);

    for(size_t i = 1; i < array.size(); ++i) {
        newNext = std::max(previous, next);
        previous = next + array.at(i);
        next = newNext;
    }

    return std::max(previous, next);
}

int main(int argc, char** argv) {
    std::vector<int> test1 = {5, 1, 1, 5};
    assert(maxNonConsecutive(test1) == 10);

    std::vector<int> test2 = {2, 4, 6, 8};
    assert(maxNonConsecutive(test2) == 10);

    return 0;
}
