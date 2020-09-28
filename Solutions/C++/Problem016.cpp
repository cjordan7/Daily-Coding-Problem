
#include <iostream>
#include <vector>
#include <algorithm>

class Log {
private:
    std::vector<int> logArray;
    size_t size;
    size_t currentSize;
    size_t startPointer;

    int pointer;
public:
    Log(size_t size);

    void record(int i);
    int getLast(int i);

    void printLog();
};

Log::Log(size_t size) :size(size), startPointer(0), currentSize(0), pointer(0), logArray(size, 0) {
}

void Log::record(int i) {
    logArray.at(pointer) = i;

    currentSize = std::min(currentSize + 1, size);

    if(currentSize == size) {
        startPointer = (pointer + 1) % size;
    }

    ++pointer;
    pointer %= size;
}

int Log::getLast(int i) {
    size_t tempPtr = (pointer - i + size) % size;
    return logArray.at(tempPtr);
}

void Log::printLog() {
    for(int i = 0; i < currentSize; ++i) {
        std::cout << logArray.at((i + startPointer) % size) << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char** argv) {
    Log log(5);
    log.record(1);
    log.record(2);
    log.record(3);
    log.record(4);
    log.printLog();

    log.record(5);
    log.printLog();

    log.record(6);
    log.record(7);
    log.printLog();

    log.record(8);
    log.record(9);
    log.record(10);
    log.record(11);
    log.printLog();

    return 0;
}
