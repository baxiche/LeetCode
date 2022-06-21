

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 */

void rec(int in[][2], int countPair[], int tmp[][2], int left, int right){
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    rec(in, countPair, tmp, left, mid);
    rec(in, countPair, tmp, mid + 1, right);

    for (int i = left; i <= right; ++i){
        tmp[i][0] = in[i][0];
        tmp[i][1] = in[i][1];
    }    

    int i = left;
    int j = mid + 1;
    int idx = left;
    while (i <= mid && j <= right){
        if (in[i][0] <= in[j][0]){
            countPair[in[i][1]] += j - (mid + 1);
            tmp[idx][0] = in[i][0];
            tmp[idx][1] = in[i][1];
            ++i;
            ++idx;
        }
        else {
            tmp[idx][0] = in[j][0];
            tmp[idx][1] = in[j][1];
            ++j;
            ++idx;
        }
    }
    while (i <= mid){
        countPair[in[i][1]] += j - (mid + 1);
        tmp[idx][0] = in[i][0];
        tmp[idx][1] = in[i][1];
        ++i;
        ++idx;
    }
    while (j <= right){
        tmp[idx][0] = in[j][0];
        tmp[idx][1] = in[j][1];
        ++j;
        ++idx;
    }

    for (idx = left; idx <= right; ++idx){
        in[idx][0] = tmp[idx][0];
        in[idx][1] = tmp[idx][1];
    }

    return;
}

int* countSmaller(int* nums, int len, int* rs){
    *rs = len;
    int in[len][2];
    for (int i = 0; i < len; ++i){
        in[i][0] = nums[i];
        in[i][1] = i;
    }

    int tmp[len][2];
    int *countPair = (int*)calloc(len, sizeof(int));
    rec(in, countPair, tmp, 0, len - 1);
    return countPair;
}