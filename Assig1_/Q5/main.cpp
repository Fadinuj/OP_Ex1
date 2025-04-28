#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Returns random integer between -25 and 25
int randomInRange() {
    return rand() % 51 - 25;
}

// Fills an array with random integers in [-25, 25]
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = randomInRange();
    }
}

// O(n^3)
int maxSubarrayN3(int arr[], int n) {
    int maxSum = INT_MIN;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k)
                sum += arr[k];
            if (sum > maxSum)
                maxSum = sum;
        }
    return maxSum;
}

// O(n^2)
int maxSubarrayN2(int arr[], int n) {
    int maxSum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += arr[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

// O(n)
int maxSubarrayN(int arr[], int n) {
    int maxSum = arr[0];
    int currSum = arr[0];
    for (int i = 1; i < n; ++i) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <seed> <array_size>" << endl;
        return 1;
    }

    int seed = atoi(argv[1]);
    int n = atoi(argv[2]);

    if (n <= 0) {
        cerr << "Array size must be positive." << endl;
        return 1;
    }

    srand(seed);
    int* arr = new int[n];

    generateRandomArray(arr, n);  // use the new function here!

    cout << "Running O(n^3) version..." << endl;
    int res1 = maxSubarrayN3(arr, n);
    cout << "Max Sum (O(n^3)): " << res1 << endl;

    cout << "Running O(n^2) version..." << endl;
    int res2 = maxSubarrayN2(arr, n);
    cout << "Max Sum (O(n^2)): " << res2 << endl;

    cout << "Running O(n) version..." << endl;
    int res3 = maxSubarrayN(arr, n);
    cout << "Max Sum (O(n)): " << res3 << endl;

    delete[] arr;
    return 0;
}
