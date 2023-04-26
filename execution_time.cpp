#include <chrono>
#include <iostream>
#include <string>

const int ARR_10_EL[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int SINGLE_RUNS = 100000;
const int ALL_RUNS = 10000;

std::chrono::_V2::system_clock::time_point start, end;
std::chrono::microseconds duration;
unsigned long long size;

int pointerSizeExecutionTime();
int arraySizeExecutionTime();
int stdSizeExecutionTime();
template <class T>
unsigned long long pointerSize(T(&p));
template <class T, size_t N>
unsigned long long arraySize(T (&arr)[N]);

int main() {
    double averagePointerSize = 0, averageArraySize = 0, averageStdSize = 0;

    for (int i = 0; i < ALL_RUNS; i++) {
        averagePointerSize += pointerSizeExecutionTime();
        averageArraySize += arraySizeExecutionTime();
        averageStdSize += stdSizeExecutionTime();
    }
    averagePointerSize /= SINGLE_RUNS;
    averageArraySize /= SINGLE_RUNS;
    averageStdSize /= SINGLE_RUNS;

    std::cout << "average pointerSize execution time: " << averagePointerSize << '\n';
    std::cout << "average arraySize execution time: " << averageArraySize << '\n';
    std::cout << "average stdSize execution time: " << averageStdSize << '\n';
}

int pointerSizeExecutionTime() {
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SINGLE_RUNS; i++) {
        size = pointerSize(ARR_10_EL);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

int arraySizeExecutionTime() {
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SINGLE_RUNS; i++) {
        size = arraySize(ARR_10_EL);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

int stdSizeExecutionTime() {
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SINGLE_RUNS; i++) {
        size = std::size(ARR_10_EL);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    return duration.count();
}

template <class T>
unsigned long long pointerSize(T(&p)) {
    return sizeof(p) / sizeof(*p);
}

template <class T, size_t N>
unsigned long long arraySize(T (&arr)[N]) {
    return N;
}
