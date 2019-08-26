#include <iostream>
using namespace std;

void swap(int *xp, int *yp) { 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int index = 0;
        for (int j = 0; j <= n - i - 1; j++) {
            if (a[j] > a[index]) {
                index = j;
            }
        }
        swap(&a[n - i - 1], &a[index]);
    }
}

void selectSort1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[index]) {
                index = j;
            }
        }
        swap(&a[index], &a[i]);
    }
}

int main() {
    int a[5] = {2, 4, 3, 5, 1};
    selectSort(a, 5);
    for (size_t i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }
    
}