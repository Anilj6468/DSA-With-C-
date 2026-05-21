#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;
using namespace chrono;

void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    cout << "[ ";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i + 1 < arr.size()) cout << ", ";
    }
    cout << " ]\n";
}

void printDivider(char ch = '-', int width = 55) {
    cout << string(width, ch) << "\n";
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

vector<int> getArrayFromUser() {
    vector<int> arr;
    cout << "\n  Enter numbers separated by spaces (then press Enter):\n  > ";
    clearInput();
    string line;
    getline(cin, line);

    size_t pos = 0;
    while (pos < line.size()) {
        while (pos < line.size() && isspace(line[pos])) ++pos;
        if (pos == line.size()) break;
        size_t start = pos;
        bool negative = (line[pos] == '-');
        if (negative) ++pos;
        if (pos < line.size() && isdigit(line[pos])) {
            while (pos < line.size() && isdigit(line[pos])) ++pos;
            try {
                arr.push_back(stoi(line.substr(start, pos - start)));
            } catch (...) {}
        } else {
            ++pos; 
        }
    }
    return arr;
}

void bubbleSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(arr.begin() + left,  arr.begin() + left + n1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i)
        if (arr[i] == target) return i;
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = static_cast<int>(arr.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)  low  = mid + 1;
        else                    high = mid - 1;
    }
    return -1;
}

void runBubbleSort() {
    printDivider('=');
    cout << "  BUBBLE SORT\n";
    printDivider();
    cout << "  Time Complexity : O(n²) avg/worst, O(n) best\n";
    cout << "  Space Complexity: O(1) — in-place\n";
    printDivider();

    vector<int> arr = getArrayFromUser();
    if (arr.empty()) { cout << "  No valid numbers entered.\n"; return; }

    printArray(arr, "\n  Before");

    auto t1 = high_resolution_clock::now();
    bubbleSort(arr);
    auto t2 = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(t2 - t1).count() / 1000.0;

    printArray(arr, "  After ");
    cout << fixed << setprecision(3)
         << "\n  Elapsed: " << us << " µs\n";
}

void runMergeSort() {
    printDivider('=');
    cout << "  MERGE SORT\n";
    printDivider();
    cout << "  Time Complexity : O(n log n) — all cases\n";
    cout << "  Space Complexity: O(n) — extra arrays\n";
    printDivider();

    vector<int> arr = getArrayFromUser();
    if (arr.empty()) { cout << "  No valid numbers entered.\n"; return; }

    printArray(arr, "\n  Before");

    auto t1 = high_resolution_clock::now();
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    auto t2 = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(t2 - t1).count() / 1000.0;

    printArray(arr, "  After ");
    cout << fixed << setprecision(3)
         << "\n  Elapsed: " << us << " µs\n";
}

void runLinearSearch() {
    printDivider('=');
    cout << "  LINEAR SEARCH\n";
    printDivider();
    cout << "  Time Complexity : O(n)\n";
    cout << "  Works on       : unsorted OR sorted arrays\n";
    printDivider();

    vector<int> arr = getArrayFromUser();
    if (arr.empty()) { cout << "  No valid numbers entered.\n"; return; }

    printArray(arr, "\n  Array");
    cout << "  Enter the value to search for: ";
    int target; cin >> target;

    auto t1 = high_resolution_clock::now();
    int idx = linearSearch(arr, target);
    auto t2 = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(t2 - t1).count() / 1000.0;

    cout << "\n";
    if (idx != -1)
        cout << "  ✔  Found " << target << " at index " << idx << "\n";
    else
        cout << "  ✘  " << target << " not found in the array.\n";

    cout << fixed << setprecision(3)
         << "  Elapsed: " << us << " µs\n";
}

void runBinarySearch() {
    printDivider('=');
    cout << "  BINARY SEARCH\n";
    printDivider();
    cout << "  Time Complexity : O(log n)\n";
    cout << "  Requirement     : array MUST be sorted\n";
    printDivider();

    vector<int> arr = getArrayFromUser();
    if (arr.empty()) { cout << "  No valid numbers entered.\n"; return; }

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    printArray(sorted, "\n  Sorted array used");

    cout << "  Enter the value to search for: ";
    int target; cin >> target;

    auto t1 = high_resolution_clock::now();
    int idx = binarySearch(sorted, target);
    auto t2 = high_resolution_clock::now();
    double us = duration_cast<nanoseconds>(t2 - t1).count() / 1000.0;

    cout << "\n";
    if (idx != -1)
        cout << "  ✔  Found " << target << " at index " << idx
             << " (in sorted array)\n";
    else
        cout << "  ✘  " << target << " not found in the array.\n";

    cout << fixed << setprecision(3)
         << "  Elapsed: " << us << " µs\n";
}

void showComparison() {
    printDivider('=');
    cout << "  ALGORITHM COMPARISON TABLE\n";
    printDivider('=');
    cout << left
         << setw(18) << "  Algorithm"
         << setw(16) << "  Best"
         << setw(16) << "  Average"
         << setw(16) << "  Worst"
         << setw(12) << "  Space"
         << "\n";
    printDivider();

    // Sorting
    cout << setw(18) << "  Bubble Sort"
         << setw(16) << "  O(n)"
         << setw(16) << "  O(n²)"
         << setw(16) << "  O(n²)"
         << setw(12) << "  O(1)"
         << "\n";
    cout << setw(18) << "  Merge Sort"
         << setw(16) << "  O(n log n)"
         << setw(16) << "  O(n log n)"
         << setw(16) << "  O(n log n)"
         << setw(12) << "  O(n)"
         << "\n";
    printDivider();

    // Searching
    cout << setw(18) << "  Linear Search"
         << setw(16) << "  O(1)"
         << setw(16) << "  O(n)"
         << setw(16) << "  O(n)"
         << setw(12) << "  O(1)"
         << "\n";
    cout << setw(18) << "  Binary Search"
         << setw(16) << "  O(1)"
         << setw(16) << "  O(log n)"
         << setw(16) << "  O(log n)"
         << setw(12) << "  O(1)"
         << "\n";
    printDivider('=');
    cout << "  * Binary Search requires a sorted array.\n";
    cout << "  * Merge Sort is stable; Bubble Sort is stable.\n";
}

void showMenu() {
    printDivider('=');
    cout << "   SORTING & SEARCHING ALGORITHMS\n";
    printDivider('=');
    cout << "   SORTING\n";
    cout << "    1. Bubble Sort\n";
    cout << "    2. Merge Sort\n";
    printDivider();
    cout << "   SEARCHING\n";
    cout << "    3. Linear Search\n";
    cout << "    4. Binary Search\n";
    printDivider();
    cout << "    5. Complexity Comparison Table\n";
    cout << "    0. Exit\n";
    printDivider('=');
    cout << "  Choose an option: ";
}

int main() {
    int choice = -1;
    while (true) {
        cout << "\n";
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: runBubbleSort();    break;
            case 2: runMergeSort();     break;
            case 3: runLinearSearch();  break;
            case 4: runBinarySearch();  break;
            case 5: showComparison();   break;
            case 0:
                cout << "\n  Goodbye!\n\n";
                return 0;
            default:
                cout << "\n  Invalid option. Please choose 0–5.\n";
                clearInput();
        }
        cout << "\n  Press Enter to return to the menu...";
        clearInput();
        clearInput();
    }
}