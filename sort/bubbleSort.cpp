void bubbleSort(int[] a, int n) {
    if (n <= 1) return;

    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }
}