#ifndef __SORT_H__
#define __SORT_H_

void exch(int* a , int i , int j)
{
    if(i==j) return; //如果i和j相等就什么都不做
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
/***********************Selection Sort *************************/
//largeW.txt 100W ints takes 1261.15s on i3-4150 ,win7 64 bits
//for array length is N ,it needs N^2/2 times compare and N times exchange 
void SelectionSort(int *a, int asize){
    for(int i =0; i< asize ; i++)
    {
        int min = i;
        for(int j = i + 1 ; j < asize ; j++){
            if(a[j] < a[min])
                min = j;
        }
        exch(a, min , i );
    }
}


/***********************Insertion Sort *************************/
//largeW.txt 100W ints takes 1197.99s on i3-4150 ,win7 64 bits
//average needs N^2/4 times compare and N^2/4 times exchange 
//badest needs N^2/2 times compare and N^2/2 times exchange
void InsertionSort(int *a , int size){
    for(int i = 1; i <size ; i++){
        for(int j = i;(j > 0) && (a[j] < a[j-1]); j--){
            
               exch(a, j , j-1); 
        }
    }
}

/***********************Shell Sort *************************/
//largeW.txt 100W ints takes  about 0.5s on i3-4150 ,win7 64 bits
//思想是任意间隔h的数组都是有序的，这被称为h有序数组
//算法的性能取决于所使用的递增序列，这里所使用的递增序列为1/2*(3^k -1) 1,4,13,40,...
//算法最坏的性能为 k*N^(3/2) 次比较
void ShellSort(int* a , int size){
    int h =1;
    while(h < size/3)
        h= 3*h + 1; //第二组数的第一个数
    while(h >= 1){
        for(int i=h; i<size ; i++){
            //用插入排序的思想对a[i-h] ,a[i-2h],a[i-3h],...进行排序
            for(int j=i; j>=h && a[j] < a[j-h];j -= h )
                exch(a, j , j-h);
        }
        //实时计算递增序列。还可以将递增序列事先计算好，保存在一个数组中。
        h = h / 3; //最后一次循环h必等于1, 因为h = 3*h +1;
    }
}

/***********************Merge Sort *************************/
//将两个有序数组，a[low..mid] a[mid+1..high] ,归并成一个有序数组。
//数组a的左半部分和右半部分都是有序的。
//先将将数组a复制到辅助数组aux中，然后将aux中的数按照适当的大小依次放入a中，
//如果右边的当前的元素小于左边，则从右边取元素放入a中
//如果左边的当前的元素小于右边，则从左边取元素放入a中
//如果左边的元素都取完了，就从右边取；右边取完就从左边取
void Merge(int* a ,int* aux, int low, int mid, int high){
    //i是左边的索引，j是右边的索引
    int i =low, j = mid + 1;
    //将所有元素复制到辅助数组aux中。
    for(int k = low; k<= high; k++){
        aux[k] = a[k];
    }
    //下面进行归并操作
    for(int k = low; k <= high ; k++){
        if( i > mid) //左半边元素用尽，则使用右半边的元素
            a[k] = aux[j++];
        else if ( j > high) //右半边的元素用尽，则使用左半边的元素
            a[k] = aux[i++];
        else if ( aux[j] < aux[i]) //右半边的当前元素小于左半边的当前元素，则取右半边的元素
            a[k] = aux[j++];
        else            //右半边的当前元素大于左半边的当前元素，则取左半边的元素
            a[k] = aux[i++];
    }
}

void RecursionMergeSort(int*a ,int* aux ,int lo , int hi){
    if(hi <= lo) //退出条件
        return;
    int mid = lo + ( hi - lo) /2;
    RecursionMergeSort(a,aux, lo , mid ); //将左半边排序
    RecursionMergeSort(a,aux, mid+1 , hi); //将右半边排序
    Merge(a,aux, lo , mid , hi); //将结果归并
}
//自顶向下归并
//对于长度为N的任意数组，该算法需要(1/2)*N*lgN 到 N*lgN次比较 
//对于长度为N的任意数组，该算法需要最多访问数组 6*N*lgN次
//largeW.txt 100W ints takes  about 0.2s on i3-4150 ,win7 64 bits
void MergeSort(int* a , int N){
    int* aux = new int[N]; //分配辅助数组空间
    RecursionMergeSort(a, aux , 0 , N-1);   //递归调用归并排序
    delete [] aux;
}
//自底向上归并
//性能与自顶向下的排序差不多
void MergeBUSort(int*a , int N){
    int* aux = new int[N];
    for( int sz = 1; sz < N ; sz = sz + sz){
        for(int lo = 0; lo < N - sz; lo += sz + sz )
            Merge(a , aux , lo , lo + sz -1 , (lo + 2*sz -1) < (N-1) ? (lo + 2*sz -1) :(N-1) );
    }
}

/***********************Quick Sort *************************/
//largeW.txt 100W ints takes  about 0.165s on i3-4150 ,win7 64 bits
//快速排序平均需要约2NlnN次比较，1/6NlnN次交换
//最坏的情况是N^2/2次比较。但是这几乎不会发生，只要数据是随机的
int Partition(int *a , int lo , int hi){
    int i = lo , j = hi + 1;  //左右扫描指针
    int temp = a[lo]; //切分元素 
    while(true){
        while( a[++i] < temp ) //从左侧开始搜索找到第一个大于切分元素的数就退出while,则当前i所指就是这个元素
            if( i == hi) break;
        while( a[--j] > temp)  //从右侧开始搜索找到第一个小于切分元素的数就退出while,则当前j所指就是这个元素
            if( j == lo) break;
        if( i >= j) break; //两个指针相遇，即数组扫描完毕。此时j所指向的元素一定是小于等于切分元素的。
        exch( a , i ,j);   
    }
    exch( a , lo , j);  //将切分元素放到正确的位置
    return j;  // 此时有a[lo...j-1] <= a[j] <= a[j+1...hi]; 返回
}

void RecursionQuickSort(int*a ,int lo , int hi ){
    if(hi <= lo) //退出条件
        return;
    int j = Partition(a, lo , hi);  //切分完之后a[j]已经是在它正确的位置了
    RecursionQuickSort(a , lo , j-1); //将a[lo...j-1]排序
    RecursionQuickSort(a , j+1 , hi); //将a[j+1...hi]排序
}

void QuickSort(int *a , int N){
    RecursionQuickSort(a , 0 , N -1);
}

//3向切分快速排序，对于有大量重复元素的数组，效果很好
//如果重复元素不多，则运行效率不如普通快速排序
void RecurQuick3Way(int*a , int lo , int hi){
    if(lo >= hi) return;
    int lt = lo , i = lo + 1 , gt = hi;
    int v = a[lo];
    while(i <= gt){
        if(a[i] < v){
            //exch(a, i , lt );
            //++i; ++lt;
            exch(a , i++ , lt++);
        }
        else if( a[i] > v){
            //exch(a, i , gt);
            //--gt;
            exch(a , i , gt--);
        }
        else {
            ++i;
        }
    }
    RecurQuick3Way(a , lo , lt-1);
    RecurQuick3Way(a , gt+1 , hi); 
}

void QuickSort3Way(int *a , int N){
    RecurQuick3Way(a , 0 , N-1);
}

bool isSorted(int *a , int asize){
    for(int i=1; i< asize ; i ++){
        if(a[i] < a[i-1])
            return false;
    }
    return true;
}


#endif