#include <stdio.h>
#include <stdlib.h>


/*
 *参考：
 * 1. https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167047&idx=1&sn=21eb442c1a8fe2da9f2a551feffccfb9
 * 2. Leatcode 167: 两数之和 II - 输入有序数组
 */
int* two_sum(int* numbers, int numbersSize, int target, int* returnSize){
    int* pret = malloc(sizeof(int)*2);
    pret[0] = -1;
    pret[0] = -1;
    *returnSize = 2;
    int i = 0;
    int j = numbersSize - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            pret[0] = i+1;
            pret[1] = j+1;
            return pret;
        }
    }
    return pret;
}

int main() {
    int numbers[] = {1,3,11,17, 50};
    int  pretsize = 0;
    int* pret = two_sum(numbers, sizeof(numbers)/sizeof(int), 20, &pretsize);
    printf("[%d, %d]\n", pret[0], pret[1]);
    return 0;
}
