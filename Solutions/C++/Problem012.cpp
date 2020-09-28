
#include <iostream>

int fibonacci(int i) {
    if(i <= 1) {
        return i;
    } else {
        return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char** argv) {
    int numberOfStairs = 2;
    std::cout << "The number of ways to climb "
              << numberOfStairs
              << " stairs is "
              << fibonacci(numberOfStairs)
              << std::endl;
    return 0;
}
