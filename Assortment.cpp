#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>& arr) {
    int s = 0;
    for(int x : arr) s += x;
    return s;
};

int countVowels(string s) {
    int count = 0;
    for(char c : s) {
        if(string("aeiouAEIOU").find(c) != string::npos)
            count++;
    }
    return count;
};

int linearSearch(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) return i;
    }
    return -1;
};

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

