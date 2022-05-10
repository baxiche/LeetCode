/*
 * @lc app=leetcode id=4 lang=c
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

int t(int *begin1, int *end1, int *begin2, int *end2, int k){
    while (k > 1){
        int len1 = end1 - begin1;
        if (len1 == 0) return *(begin2 + k - 1);
        int len2 = end2 - begin2;
        if (len2 == 0) return *(begin1 + k - 1);

        int half1 = (len1 < k / 2)? len1 : k / 2;
        int *mid1 = begin1 + half1 - 1;
        int half2 = (len2 < k / 2)? len2 : k / 2;
        int *mid2 = begin2 + half2 - 1;

        if (*mid1 > *mid2){
            begin2 += half2 + 1;
            k -= half2;
        } 
        else {
            begin1 += half1;
            k -= half1;
        }
    }
    return (*begin1 < *begin2)? *begin1 : *begin2;
}

double findMedianSortedArrays(int* nums1, int n, int* nums2, int m){
    if (n + m % 2 == 0){
        int x = t(nums1, nums1 + n, nums2, nums2 + m, (n + m) / 2);
        int y = t(nums1, nums1 + n, nums2, nums2 + m, (n + m) / 2 + 1);
        return (double)(0.5) * (double)(x + y);
    }
    else {
        return t(nums1, n, nums2, m, (n + m + 1) / 2);
    }
}
// @lc code=end

