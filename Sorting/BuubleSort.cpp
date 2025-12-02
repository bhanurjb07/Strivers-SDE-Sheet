#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    ============================================================================
                                BUBBLE SORT
    ============================================================================
    Problem:
        Given an array of integers nums, sort the array in NON-DECREASING order
        using the Bubble Sort algorithm and return the sorted array.

    Non-decreasing:
        Each element should be >= all previous elements.

    We implement TWO variations:
        1️⃣ Basic Bubble Sort (Standard)
        2️⃣ Optimized Bubble Sort (Stops early when array becomes sorted)

    Bubble Sort works by repeatedly swapping adjacent elements 
    that are in the wrong order.
*/
/*
    ============================================================================
    1️⃣ APPROACH 1 — BASIC BUBBLE SORT
    ============================================================================
    IDEA:
        Compare arr[j] and arr[j+1], swap if arr[j] > arr[j+1].
        Keep doing this for n-1 passes.

    TIME COMPLEXITY:
        Worst case: O(n²)
        Average:    O(n²)
        Best:       O(n²)

    SPACE COMPLEXITY:
        O(1) — in-place

    NOTES:
        Very simple but not optimal for large data.
*/
void bubbleSort_basic(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }

        }
    }
}



/*
    ============================================================================
    2️⃣ APPROACH 2 — OPTIMIZED BUBBLE SORT
    ============================================================================
    IDEA:
        If in a full pass we make ZERO swaps → array is already sorted.
        Break early → saves huge time for nearly-sorted arrays.

    TIME COMPLEXITY:
        Worst:  O(n²)
        Best:   O(n)  (when already sorted)

    SPACE COMPLEXITY:
        O(1)

    WHY BETTER?
        Prevents unnecessary passes.
*/
void bubbleSort_optimized(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }

        }
        // No swaps → Array already sorted
        if (!swapped) break;
    }
}
/*
    ============================================================================
     PRINT ARRAY
    ============================================================================
*/
void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {

    vector<int> nums = {1, 2, 5, 4, 8, 9, 0, 7};

    vector<int> a = nums;
    vector<int> b = nums;

    cout << "Original Array: ";
    printArray(nums);

    // Basic Bubble Sort
    bubbleSort_basic(a);
    cout << "After Basic Bubble Sort: ";
    printArray(a);

    // Optimized Bubble Sort
    bubbleSort_optimized(b);
    cout << "After Optimized Bubble Sort: ";
    printArray(b);

    return 0;
}
