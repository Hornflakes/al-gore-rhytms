#include <chrono>
#include <iostream>
#include <string>

void printThreeDistinctGreatest();
void moveZeroesToEnd();

int main() {
    moveZeroesToEnd();
}

void printThreeDistinctGreatest() {
    int arr[] = {1, 2, 41, 4, 5, 23, 7, 10, 9, 10};
    int first = INT_MIN, second = first, third = second;

    for (int i = 0; i < std::size(arr); i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second)
            third = arr[i];
    }

    std::cout << "first: " << first << " > "
              << "second: " << second << " > "
              << "third: " << third << '\n';
}

void moveZeroesToEnd() {
    int arr[] = {5, 0, 6, 9, 0, 0, 2, 4, 0, 5, 0};
    int j = 0;

    for (int i = 0; i < std::size(arr); i++) {
        if (arr[i] != 0) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }

    std::cout << "array with zeroes moved to end: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << '\n';
};
