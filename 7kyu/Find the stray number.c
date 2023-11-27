#include <stddef.h>

int stray(size_t n, int arr[n]) {
    int result = 0;
    for (size_t i = 0; i < n; ++i) {
        result ^= arr[i];
    }
    return result;
}
/*
当我们使用异或（^）操作符时，它会对两个二进制数进行逐位比较。
如果相应的位不同，则结果为1；如果相应的位相同，则结果为0。
在这个问题中，我们假设数组中除了一个元素外，所有其他元素都是相同的。
通过使用异或操作符，我们可以找到那个单独不同的数字。
让我们看一下具体的步骤：

我们初始化一个变量 result 为0。
然后，我们将 result 与数组中的每个元素进行异或操作：result ^= arr[i]。
异或操作具有以下特性：
如果两个数相同，则它们之间的异或结果为0。
如果两个数不同，则它们之间的异或结果为1。
由于数组中除了一个元素外都是相同的数字，所以在进行完所有异或操作后，重复出现的数字会被抵消成0。
剩下来只有单独不同的数字与初始值0进行异或操作。由于任何数与0进行异或操作得到其本身，所以最终结果就是那个单独不同的数字。
因此，在这段代码中使用 ^ 操作符对整个数组进行逐位比较和抵消，并返回最终剩下来的单独不同数字作为结果。

希望这样解释能够帮助你理解代码背后运用了什么原理！

*/
#include <stdio.h>

int stray(size_t n, int arr[n]);

int main() {
    int arr[] = {2, 2, 3, 2, 2}; // Example input array
    size_t length = sizeof(arr) / sizeof(arr[0]);

    int singleDifferentNumber = stray(length, arr);

    printf("The single different number is: %d\n", singleDifferentNumber);

    return 0;
}
