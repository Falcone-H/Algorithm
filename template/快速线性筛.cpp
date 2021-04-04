#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1000005;
int Mark[MAX_SIZE];
int prime[MAX_SIZE];
int Prime()
{
    int index = 0;
    for (int i = 2; i < MAX_SIZE; i++)
    {
        if (Mark[i] == 0)
        {
            prime[index++] = i;
        }
        // 标记目前得到的素数的 i 倍为非素数
        for (int j = 0; j < index && prime[j] * i < MAX_SIZE; j++)
        {
            Mark[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
}