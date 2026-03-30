#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, -2, 10, -8, 0, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Negative elements: ";

    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;
};


#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1, 5, 3},
        {9, 2, 8},
        {4, 7, 6}
    };

    int max = arr[0][0]; 

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }

    cout << "Largest element = " << max;

    return 0;
};


#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // In-place transpose
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Print result
    cout << "Transpose Matrix:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
};