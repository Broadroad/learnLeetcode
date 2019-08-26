#include <iostream>
using namespace std;

void selectSort(int[] a, int n) {
    for (int i = 0; i < n; i++) {
        int maxNum = a[i];
        int index = i;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > maxNum) {
                maxNum = a[j];
                index = j;
            }
        }
        int tmp = a[n - i - 1];
        a[n - i - 1] = maxNum;
        a[index] = tmp;
    }
}

void selectSort1(int[] a, int n) {
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[index]) {
                index = j;
            }
        }
        swap(&a[index], &a[i]);
    }
}

int main() {
    int[] a = {2, 4, 3, 5, 1};
    selectSort(a, 5);
    for (size_t i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }
    
}