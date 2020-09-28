
#include <iostream>
#include <random>

#define RADIUS 3.0

double getRandomNumber() {
    return ((double) rand() / (RAND_MAX))*RADIUS;
}

double pi(long long int iteration) {
    int counter = 0;

    for(int i = 0; i < iteration; ++i) {
        double x = getRandomNumber();
        double y = getRandomNumber();

        if(x*x + y*y <= RADIUS*RADIUS) {
            ++counter;
        }
    }

    return 4.0*counter/iteration;
}

int main(int argc, char** argv) {
    long long int iteration = 1000000000;
    std::cout << "Estimated value of Pi "
              << pi(iteration)
              << " for "
              << iteration
              << " iterations"<< std::endl;
    return 0;
}
