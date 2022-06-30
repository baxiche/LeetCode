

char * longestPalindrome(char * s){
    int len = strlen(s);
    for (int sl = 0, fa = 1; fa < len; ++fa){
        if (s[sl] == s[fa]) sl = fa;
        else{
            s[sl] = s[fa];
            ++sl;
        }
    }
}



int removeDuplicates(int* nums, int len){
    if (!len) return 0;
    if (len == 1) return 1;

    for (int sl = 0, fa = 0; fa < len; ++fa){
        if (nums[])
    }
}

int main(){
    char ss[10] = "aabb";
    
    for (int i = 0; i < 4; ++i)

}