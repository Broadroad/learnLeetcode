class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &A) {
        int n = A.size();
        if (n <= 1) {
            return;
        }
        
        vector<int> temp(n, 0);
        mergeSort(A, 0, n-1, temp);
    }
    
private:
    void mergeSort(vector<int>& A, int start, int end, vector<int>& temp) {
        if (start >= end) {
            return;
        }
        
        mergeSort(A, start, (end+start)/2, temp);
        mergeSort(A, (end+start)/2+1, end, temp);
        merge(A, start, end, temp);
    }
    
    void merge(vector<int>& A, int start, int end, vector<int>& temp) {
        int middle = (start + end) / 2;
        int leftStart = start;
        int rightStart = middle + 1;
        int index = leftStart;
        
        while (leftStart <= middle && rightStart <= end) {
            if (A[leftStart] < A[rightStart]) {
                temp[index++] = A[leftStart++];
            } else {
                temp[index++] = A[rightStart++];
            }
        }
        
        while (leftStart <= middle) {
            temp[index++] = A[leftStart++];
        }
        
        while (rightStart <= end) {
            temp[index++] = A[rightStart++];
        }
        
        for (int i = start; i <= end; i++) {
            A[i] = temp[i];
        }
    }
};