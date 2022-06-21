#include <stdio.h>

void merge(int nums[], int left, int mid, int right){
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int L[len1], R[len2];
    for (int i = 0; i < len1; ++i) L[i] = nums[left + i];
    for (int i = 0; i < len2; ++i) R[i] = nums[mid + 1 + i];

    int idx = left;
    int lidx = 0;
    int ridx = 0;
    for (; lidx < len1 && ridx < len2; ++idx){
        nums[idx] = (L[lidx] <= R[ridx])? L[lidx++] : R[ridx++];
    }
    for (; lidx < len1; ++idx) nums[idx] = L[lidx++];
    for (; ridx < len2; ++idx) nums[idx] = R[ridx++];    
}

void mergeSort(int nums[], int left, int right){
    if (right <= left) return;

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

int* sortArray(int* nums, int len, int* rlen){
    *rlen = len;
    mergeSort(nums, 0, len - 1);
    return nums;
}

int main(){
    int a[5] = {1,5,3,4,2};
    mergeSort(a, 0, 4);
}