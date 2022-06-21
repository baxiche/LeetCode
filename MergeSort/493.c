

int rec(int nums[], int tmp[], int left, int right){
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = rec(nums, tmp, left, mid) + rec(nums, tmp, mid + 1, right);
    int l = left;
    int r = mid + 1;
    while (l <= mid){
        while (r <= right && (long long)nums[l] > 2 * (long long)nums[r]) 
            ++r;

        count += r - (mid + 1);
        ++l; 
    }

    l = left;
    r = mid + 1;
    int idx = left;
    while (l <= mid && r <= right){
        tmp[idx++] = (nums[l] <= nums[r])? nums[l++] : nums[r++];
    }
    while (l <= mid) tmp[idx++] = nums[l++];
    while (r <= right) tmp[idx++] = nums[r++];
    for (idx = left; idx <= right; ++idx) nums[idx] = tmp[idx];

    return count;
}

int reversePairs(int* nums, int len){
    int tmp[len];
    return rec(nums, tmp, 0, len - 1);
}