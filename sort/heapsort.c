#include <stdio.h>

static void swap( int *a, int *b ) {
     int t = *a;
     *a = *b;
     *b = t;
}

/* 将n_nums个元素的数组中以nums[p]为根的子堆调整为最大堆 */
static void perc_down( int nums[], int p, int n_nums ) {
    int parent, child;
    /* 取出根结点存放的值 */
    int x  = nums[p];

    for (parent = p; parent*2+1 < n_nums; parent = child) {
        child = parent * 2 + 1;
        if ((child!=n_nums-1) && (nums[child] < nums[child+1]) )
            child++;  /* child指向左右子结点的较大者 */

        /* 找到了合适位置退出 */
        if (x >= nums[child]) break;
        /* 下滤x */
        else nums[parent] = nums[child];
    }
    nums[parent] = x;
}

/* 堆排序入口 */
void heap_sort(int nums[], int n_nums) {
    int i;

    /* 建立最大堆 */
    for (i = n_nums/2-1; i >= 0; i--)
        perc_down(nums, i, n_nums);

    for (i=n_nums-1; i>0; i--) {
        /* 将最大值nums[0]与nums[i]交换 */
        swap(&nums[0], &nums[i]);
        /* 重新以新的nums[0], size=n_nums-1调整最大堆 */
        perc_down(nums, 0, i);
    }
}


int main() {
    int nums[] = {4,3,1,2,100,23,56,44};
    int n_nums = sizeof(nums)/sizeof(int);

    heap_sort(nums, n_nums);
    printf("[");
    for (int i=0; i<n_nums; i++)
        printf("%d, ", nums[i]);
    printf("]\n");
}
