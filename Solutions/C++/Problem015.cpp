
#include <iostream>
#include <stdlib.h>
#include <time.h>

int getRandomElement(int array[], int size) {
    srand(time(NULL));
    return array[rand() % size];
}

int main(int argc, char** argv) {
    int array[] = {1, 2, 3, 4, 5, 6};
    std::cout << getRandomElement(array, 6) << std::endl;
    return 0;
}
