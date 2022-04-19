
int *lower_bound(int *begin, int *end, int tar){
    int len = end - begin;
    while (len > 0){
        int half = len / 2;
        int *mid = begin + half;
        if (tar > *mid){
            begin = mid + 1;
            len -= half + 1;
        }
        else    
            len = half;
    }
    return begin;
}

int search(int* nums, int n, int tar){
    int *t = lower_bound(nums, nums + n, tar);
    return (t != nums + n && *t == tar)? t - nums : -1;
}