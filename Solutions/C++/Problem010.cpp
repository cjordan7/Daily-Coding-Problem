
#include <iostream>
#include <unistd.h>

template<class T>
void problem010(std::function<T> f, int n) {
    usleep(n);
    f();
}

int main(int argc, char** argv) {
    
    return 0;
}
