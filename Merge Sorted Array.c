/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

int a[11] = {1,2,3,4,5};
int b[6] = {3,4,5,6,7,8};

要得到a[11] = {1,2,3,3,4,4,5,5,6,7,8}
第一感觉这个题目比较简单，就是归并排序中的其中一步：

需要一个tmp数组，初始化两个int 作为指示器，分别指向a数组的第一个元素和b数组的第一个元素。

然后比较a数组和b数组的当前元素，谁比较小谁就放入tmp数组。完了后移向下一个元素。这样操作直到a指示器大于a数组长度或者b指示器大于b数组长度。

然后看a数组和b数组，谁还剩下元素就把谁全部复制到tmp数组中。

tmp数组就是最终的有序数组。
*/
void merge(int* nums1, int m, int* nums2, int n) {
    int temp[m+n];
    int i=0;
    int j=0;
    int t=0;
    while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            temp[t]=nums1[i];
            i++;
            t++;
        }
        else{
            temp[t]=nums2[j];
            t++;
            j++;
        }
    }
    while(i<m){
        temp[t]=nums1[i];
        t++;
        i++;
    }
    while(j<n){
        temp[t]=nums2[j];
        t++;
        j++;
    }
    for(int k=0;k<m+n;k++){
        nums1[k]=temp[k];
    }
}

/*方法二：
这里我们不需要在另外创建一个数组，这道题目中，a数组空间比较大，可以直接用a

换个思路，

初始化两个int 作为指示器，分别指向a数组的最后一个元素和b数组的最后一个元素。

然后比较大小，较大的放入a数组的末端。这样不断往前走。直到a数组用完或者b数组用完。

如果a数组先用完，那么就把b数组剩下的所有元素复制到a的前半部分，如果b数组先用完，那么a数组已经是一个有序的数组。
*/
void merge(int A[], int m, int B[], int n) {
    
    int larstAIndex = m - 1;
    int larstBIndex = n - 1;
    int currentIndex = m + n - 1;

    while(larstAIndex >= 0 && larstBIndex >= 0){
        if(A[larstAIndex] >= B[larstBIndex]){
            A[currentIndex--] = A[larstAIndex--];
        }else{
            A[currentIndex--] = B[larstBIndex--];
        }
    }
    while(larstBIndex >= 0){
        A[currentIndex--] = B[larstBIndex--];
    }

}