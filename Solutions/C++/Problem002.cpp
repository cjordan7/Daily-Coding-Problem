
#include <iostream>
#include <vector>

std::vector<int> resolve2Problem002(std::vector<int>& array) {
    std::vector<int> solution;
    int product = 1;

    // Each element of "solutionLeft" correspond to the product
    // of all elements to the left of it:
    // example {1, 2, 3, 4, 5} -> {1, 1, 2, 3*2, 2*3*4}
    std::vector<int> solutionLeft;
    for(int i = 0; i < array.size(); ++i) {
        solutionLeft.push_back(product);
        product *= array.at(i);
    }
    
    product = 1;

    // Each element of "solutionRight" correspond to the product
    // of all elements to the right of it:
    // example {1, 2, 3, 4, 5} -> {2*3*4*5, 3*4*5, 4*5, 5, 1}
    std::vector<int> solutionRight;
    solutionRight.push_back(product);
    for(int i = array.size() - 1; i >= 0; --i) {
        product *= array.at(i);
        solutionRight.push_back(product);
    }

    for(int i = 0; i < array.size(); ++i) {
        int left = solutionLeft.at(i);
        int right = solutionRight.at(array.size()-1-i);
        solution.push_back(left*right);
    }

    return solution;
}

// The simple solution is to multiply each element of the array
// so that we can find the product of the array
// and then we divide the product by the corresponding element in the array
std::vector<int> resolveEasyProblem002(std::vector<int>& array) {
    std::vector<int> solution;
    int product = 1;

    for(int i = 0; i < array.size(); ++i) {
        product *= array.at(i);
    }

    for(int i = 0; i < array.size(); ++i) {
        solution.push_back(product/array.at(i));
    }

    return solution;
}

void test() {
    std::vector<int> test1 = {1, 2, 3, 4, 5};
    std::vector<int> test2 = {3, 2, 1};
    
    std::vector<int> solution1 = resolveEasyProblem002(test1);
    std::vector<int> solution2 = resolveEasyProblem002(test2);
    assert(solution1.at(0) == 120);
    assert(solution1.at(1) == 60);
    assert(solution1.at(2) == 40);
    assert(solution1.at(3) == 30);
    assert(solution1.at(4) == 24);
    
    assert(solution2.at(0) == 2);
    assert(solution2.at(1) == 3);
    assert(solution2.at(2) == 6);
    
    solution1 = resolve2Problem002(test1);
    solution2 = resolve2Problem002(test2);
    assert(solution1.at(0) == 120);
    assert(solution1.at(1) == 60);
    assert(solution1.at(2) == 40);
    assert(solution1.at(3) == 30);
    assert(solution1.at(4) == 24);
    
    assert(solution2.at(0) == 2);
    assert(solution2.at(1) == 3);
    assert(solution2.at(2) == 6);
}

int main(int argc, const char** argv) {
    test();
    
    return 0;
}
