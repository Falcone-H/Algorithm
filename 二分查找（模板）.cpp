#include<bits/stdc++.h>
using namespace std;
int a[10] = {1, 2, 3, 3, 3, 3, 3, 4, 5, 6};
int len = 10;
int binary_search(int target) {     // 普通的二分查找
    int left = 0, right = len - 1;  // 闭区间
    while(left <= right) {
        int mid = (right - left) / 2 + left;
        if(a[mid] == target) {
            return mid;
        } else if(a[mid] < target) {
            left = mid + 1;
        } else if(a[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}

int left_bound(int target) {        // 寻找第一个等于target的数出现的位置
    int left = 0, right = len - 1;  // 闭区间
    while(left <= right) {
        int mid = (right - left) / 2 + left;
        if(a[mid] == target)
            right = mid - 1;
        else if(a[mid] < target)
            left = mid + 1;
        else if(a[mid] < target)
            right = mid - 1;
    }
    if(left >= len || a[left] != target)    // 整个数组都比target小，或者整个数组都比target大
        return -1;
    else
        return left;
}

int right_bound(int target) {       // 寻找最后一个等于target的数出现的位置
    int left = 0, right = len - 1;  // 闭区间
    while(left <= right) {
        int mid = (right - left) / 2 + left;
        if(a[mid] == target)
            left = mid + 1;
        else if(a[mid] < target)
            left = mid + 1;
        else if(a[mid] > target)
            right = mid - 1;
    }
    if(right < 0 || a[right] != target)    // 整个数组都比target小，或者整个数组都比target大
        return -1;
    else
        return right;
}
int main() {
    cout << binary_search(3) << endl;
    cout << left_bound(3) << endl;
    cout << right_bound(3) << endl;
    return 0;
}