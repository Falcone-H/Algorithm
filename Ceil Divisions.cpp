// https://codeforces.com/contest/1469/problem/D
// 思路：找2、或4、或8这三个数中最大的一个作为中转。
// 第一步：将所有大于2，且不为中转数的其他数，除以最后一个数，即为操作(i n)。这一步会执行 n - 4 次
// 第二步：将最后一个数，不断除以中转数，因为数据范围是2e + 5, 即2的18次方左右。这个数不断除以8，直到1的时候结束。这一步最多会执行6次。
// 第三步：将中转数不断除以2，因为中转数最大为8，所以最多除3次。这一步最多会执行3次。
// 所以，以上一共最多会执行 n + 5 次，符合要求。
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
using namespace std;
int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        double temp = 0;
        if(n > 8)   // 找到中转数
            temp = 8;
        else if(n > 4)
            temp = 4;
        else if(n > 2)
            temp = 2;
        int t1 = 0, t2 = 0, t3 = 0;
        double last = n;
        while(last > 1) {   // 计算最后一个数，可以除以中转数多少次
            last = ceil(last / temp);
            t1++;
        }
        if(temp == 2)   // 计算除了1、2、中转数、最后一个数之外，还有多少个数
            t2 = n - 3;
        else
            t2 = n - 4;
        double mid = temp;  // 计算中转数可以除以2多少次
        while(mid > 1 && temp != 2) {
            mid = ceil(mid / 2);
            t3++;
        }
        cout << t1 + t2 + t3 << endl;
        if(t2 != 0) {
            for(int i = 3; i < n; i++) {
                if(i != temp)
                    cout << i << " " << n << endl;
            }
        }
        while(t1--) {
            cout << n << " " << temp << endl;
        }
        while(t3--) {
            cout << temp << " " << 2 << endl;
        }
    }
    return 0;
}