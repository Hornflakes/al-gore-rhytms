#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>

void printThreeDistinctGreatest();
void moveZeroesToEnd();
void rearrangeEvenGreaterThanOdd();
void rearrangeSortedArrayMaxDescMinAsc();
void segregateEvenOdd();
void rotateLeft();
void waveSort();
void countTriangles();
void findUniqueElementAmongDoubles();
void findSubArraysThatSum();
void reorderByIndexes();
void findMaxSubArraySum();
void maxProfitTwoTrades();
void sort012();
void sort012InOnePass();
void findMajorityElement();
void findPairThatSums();
void findTripletThatSums();
void findBalanceIndex();

template <class T, size_t N>
void print(T (&arr)[N]);

int main() {
    findBalanceIndex();
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
    print(arr);
};

void rearrangeEvenGreaterThanOdd() {
    int arr[] = {1, 2, 2, 1, 5, 4, 7, 6, 10, 11, 19};

    for (int i = 0; i < std::size(arr) - 1; i += 2)
        if (arr[i] < arr[i + 1]) std::swap(arr[i], arr[i + 1]);
    print(arr);
}

// even index --> max elements DESC
// odd index --> min elements ASC
void rearrangeSortedArrayMaxDescMinAsc() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40};
    const int n = std::size(arr);
    int minIndex = 0;
    int maxIndex = n - 1;
    const int greaterThanMax = arr[maxIndex] + 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // kinda like Euclid's division lemma
            arr[i] += (arr[maxIndex] % greaterThanMax) * greaterThanMax;
            maxIndex--;
        } else {
            arr[i] += (arr[minIndex] % greaterThanMax) * greaterThanMax;
            minIndex++;
        }
    }
    for (int i = 0; i < n; i++) arr[i] = arr[i] / greaterThanMax;
    print(arr);
}

void segregateEvenOdd() {
    int a[] = {1, 3, 2, 4, 5, 2, 0, 3, 5, 7, 12};
    int evenNumbersEncountered = 0;

    for (int i = 0; i < std::size(a); i++)
        if (a[i] % 2 == 0) {
            std::swap(a[evenNumbersEncountered], a[i]);
            evenNumbersEncountered++;
        }
    print(a);
}

void rotateLeft() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    const int r = 3;
    const int n = std::size(a);
    int remainder = n % r;

    for (int i = 0; i <= n - 2 * r; i += r)
        for (int j = i; j < i + r; j++) std::swap(a[j], a[j + r]);

    if (remainder) {
        for (int i = n - remainder; i < n; i++) std::swap(a[i], a[i - r]);
        while (r - remainder) {
            for (int i = n - r; i < n - 1; i++) std::swap(a[i], a[i + 1]);
            remainder++;
        }
    }
    print(a);
}

void waveSort() {
    int a[] = {10, 5, 15, 20, 30, 25, 35, 40};
    const int n = std::size(a);

    for (int i = 0; i < n; i += 2) {
        if (i && a[i - 1] > a[i])
            std::swap(a[i], a[i - 1]);
        if (i < n - 1 && a[i] < a[i + 1])
            std::swap(a[i], a[i + 1]);
    }
    print(a);
}

void countTriangles() {
    int a[] = {300, 100, 22, 21, 101, 200, 10};
    int count = 0;

    std::sort(std::begin(a), std::end(a));
    for (int i = std::size(a) - 1; i >= 1; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (a[left] + a[right] > a[i]) {
                count += right - left;
                right--;
            } else
                left++;
        }
    }
    std::cout << count;
}

void findUniqueElementAmongDoubles() {
    int a[] = {2, 1, 2, 3, 3, 4, 4};
    int unique = a[0];

    // ^ is XOR, bit manipulation trick, only works for doubles
    for (int i = 1; i < std::size(a); i++) unique = unique ^ a[i];
    std::cout << unique;
}

void findSubArraysThatSum() {
    const int a[] = {5, 1, 2, 3, 3, 4, 1, 4};
    const int sum = 5;
    int startIndex = 0;
    int subArraySum = 0;

    for (int i = 0; i < std::size(a); i++) {
        subArraySum += a[i];

        if (subArraySum < sum) continue;

        if (subArraySum == sum) {
            std::cout << startIndex << " to " << i << '\n';

            subArraySum = a[i];
            startIndex = i;
            continue;
        }

        while (startIndex < i - 1) {
            startIndex++;
        }
        subArraySum = a[i];
    }
}

void reorderByIndexes() {
    int a[] = {50, 40, 70, 60, 90};
    int indexes[] = {3, 0, 4, 1, 2};

    for (int i = 0; i < std::size(a); i++) {
        // swap until both arrays are proper
        while (indexes[i] != i) {
            std::swap(a[i], a[indexes[i]]);
            std::swap(indexes[i], indexes[indexes[i]]);
        }
    }
    print(a);
}

// called Kadane's algo
void findMaxSubArraySum() {
    const int a[] = {-1, 1, -2, 1};
    int max = INT_MIN, currMax = 0;

    for (int x : a) {
        currMax += x;
        if (currMax < 0) currMax = 0;
        if (currMax > max) max = currMax;
    }

    // if all numbers are negative
    if (!max) max = *std::max_element(std::begin(a), std::end(a));

    std::cout << max;
}

void maxProfitTwoTrades() {
    const int prices[] = {90, 80, 70, 60, 100};
    int firstBuyPnL = INT_MIN, firstSellPnL = 0, lastBuyPnL = INT_MIN, lastSellPnL = 0;

    for (int x : prices) {
        firstBuyPnL = std::max(firstBuyPnL, -x);
        firstSellPnL = std::max(firstSellPnL, firstBuyPnL + x);

        lastBuyPnL = std::max(lastBuyPnL, firstSellPnL - x);
        lastSellPnL = std::max(lastSellPnL, lastBuyPnL + x);
    }

    std::cout << lastSellPnL;
}

// called Dutch flag algo
void sort012() {
    int a[] = {0, 1, 2, 0, 1, 2};
    int zeros = 0, ones = 0, twos = 0;

    for (int x : a) {
        switch (x) {
            case 0:
                zeros++;
                break;
            case 1:
                ones++;
                break;
            default:
                twos++;
        }
    }

    int i = 0;
    while (zeros--) {
        a[i++] = 0;
    }
    while (ones--) {
        a[i++] = 1;
    }
    while (twos--) {
        a[i++] = 2;
    }

    print(a);
}

// 0 -> low :: 0s
// low -> mid :: 1s
// mid -> high :: unknown
// high -> n :: 2s
void sort012InOnePass() {
    int a[] = {0, 1, 2, 0, 1, 2};
    const int n = std::size(a);
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (a[mid]) {
            case 0:
                std::swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            default:
                std::swap(a[mid], a[high--]);
        }
    }
    print(a);
}

// element that appears more than size(a) / 2 times
void findMajorityElement() {
    const int a[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    std::unordered_map<int, int> hashTable;

    for (int x : a) {
        hashTable[x]++;
        if (hashTable[x] > std::size(a) / 2) {
            std::cout << x;
            return;
        }
    }
}

void findPairThatSums() {
    const int a[] = {1, 3, 4, 8, 9};
    const int sum = 11;
    int pairSum;

    // two pointers technique
    for (int i = 0, j = std::size(a) - 1; i < j;) {
        pairSum = a[i] + a[j];
        if (pairSum == sum) {
            std::cout << a[i] << ", " << a[j];
            return;
        } else if (pairSum < sum)
            i++;
        else
            j--;
    }
}

void findTripletThatSums() {
    const int a[] = {1, 4, 6, 8, 10, 45}, n = std::size(a), sum = 22;
    int left, right;

    for (int i = 0; i < n - 2; i++) {
        // two pointers technique
        left = i + 1;
        right = n - 1;
        while (left < right) {
            if (a[i] + a[left] + a[right] == sum) {
                std::cout << a[i] << ", " << a[left] << ", " << a[right];
                return;
            } else if (a[i] + a[left] + a[right] < sum)
                left++;
            else
                right--;
        }
    }
}

void findBalanceIndex() {
    const int a[] = {-7, 1, 5, 2, -4, 3, 0};
    int rightSum = std::accumulate(std::begin(a), std::end(a), 0);
    int leftSum = 0;
    for (int i = 0; i < std::size(a); i++) {
        rightSum -= a[i];
        if (leftSum == rightSum) {
            std::cout << i;
            return;
        }
        leftSum += a[i];
    }
}

template <class T, size_t N>
void print(T (&arr)[N]) {
    for (T x : arr) std::cout << x << ' ';
    std::cout << '\n';
}
