/*
 * @Description: Acwing 787. 归并排序
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 18:21:52
 * @LastEditTime: 2020-04-01 18:22:14
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
int tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] < q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

//test
int main(){
    int n;
    scanf("%d", &n);
    int a[N];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
}