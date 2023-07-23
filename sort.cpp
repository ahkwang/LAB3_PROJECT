#include"mainHeader.h"

void selectionSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int minIdx = i;

		for (size_t j = i + 1; j < n; j++)
		{
			if (a[minIdx] > a[j])
			{
				minIdx = j;
			}
		}

		swap(a[i], a[minIdx]);
	}
}
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int idx = i - 1;

		while (++ a[idx] > key && idx >= 0)
		{
			a[idx + 1] = a[idx--];
		}

		a[idx + 1] = key;
	}
}

void bubbleSort(int* a, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void heapSort(int *a,int n)
{
     for(int i=n/2-1;i>=0;i--)
    {
        createHeap(a,n,i);
    }
    //for(int i=n-1;i>=0;i--) not good
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        createHeap(a,i,0);
    }
}
void createHeap(int *a,int n, int pos)
{
     //create max heap
    int next=pos;
    int left= pos*2+1,right=left+1;
    if(left<n&&a[left]>a[next])next=left;
    if(right<n&&a[right]>a[next])next=right;

    if(next!=pos)
    {
        swap(a[next],a[pos]);
        createHeap(a,n,next);
    }
}

void mergeSort(int *a,int n)
{
    startMergeSort(a,0,n-1);
}
void mergeArray(int *a,int l,int r,int mid)
{
    int t1=mid-l+1,t2=r-mid;

    int* left_array = new int[t1];
    int* right_array = new int[t2];

    for(int i=l;i<=mid;i++)left_array[i-l]=a[i];
    for(int i=mid+1;i<=r;i++)right_array[i-mid-1]=a[i];

    int count1=0,count2=0,tmp=l;

    //while(count1<=t1&&count2<=t2)
    while(count1<t1&&count2<t2)
    {
        if(left_array[count1]<right_array[count2])
        {
            a[tmp++]=left_array[count1++];
        }
        else a[tmp++]=right_array[count2++];
    }
    while(count1<t1)a[tmp++]=left_array[count1++];
    while(count2<t2)a[tmp++]=right_array[count2++];

    delete [] left_array;
    delete [] right_array;

}
void startMergeSort(int *a, int l, int r)
{
    if(l>=r)return;

    int mid=l+(r-l)/2;;
    startMergeSort(a,l,mid);
    startMergeSort(a,mid+1,r);

    mergeArray(a,l,r,mid);
}


void quickSort(int* a, int n)
{
    quickSort_function(a, 0, n - 1);
}
void quickSort_function(int* a, int left, int right)
{
    if (left < right)
    {
        int pivot = a[left];
        int i = left;
        int j = right + 1;
        do {
            do {
                i++;
            } while (i <= right && a[i] < pivot);// tránh trường hợp xét các phần tử ngoài mảng
            do {
                j--;
            } while (a[j] > pivot);
            swap(a[i], a[j]);
        } while (i < j);
        swap(a[i], a[j]);
        swap(a[left], a[j]);
        // giải quyết mảng nhỏ trước, tránh gây tràn bộ nhớ đệm 
        if (j - left <= right - j) {
            quickSort_function(a, left, j - 1);
        }
        else {
            quickSort_function(a, j + 1, right);
        }
    }
}

void countingSort(int* a, int n)
{
	int maxValue = a[0];

	for (int i = 0; i < n; i++)
		if (maxValue < a[i])
			maxValue = a[i];

	int minValue = a[0];

	for (int i = 0; i < n; i++)
		if (minValue > a[i])
			minValue = a[i];

	int maxNum = maxValue - minValue + 1;
	int* countArr = new int[maxNum];
	int* sortedArr = new int[n];

	for (int i = 0; i < maxNum; i++)
		countArr[i] = 0;

	for (int i = 0; i < n; i++)
		sortedArr[i] = 0;

	for (int i = 0; i < n; i++)
		countArr[a[i] - minValue]++;
	for (int i = 1; i < maxNum; i++)
		countArr[i] += countArr[i - 1];

	for (int i = 0; i < n; i++)
	{
		sortedArr[countArr[a[i] - minValue] - 1] = a[i];
		countArr[a[i] - minValue]--;
	}
	for (int i = 0; i < n; i++)
		a[i] = sortedArr[i];

    delete[] countArr;
    delete[] sortedArr;
}

void radixSort(int *a, int n)
{
    //find max element
    int maxnum=a[0];
    for(int i=1;i<n;i++)maxnum=max(maxnum,a[i]);
    int d=countDigit(maxnum);
    for(int i=1;i<=d;i++)
    {
        countingSortForBase_k(a,n,i);
    }
}
int countDigit(int x)
{
    int t=0;
    while(x>0)
    {
        x/=10;
        t++;
    }
    return t;
}
int digit(int x,int k)
{
    for(int i=1;i<k;i++) x/=10;
    return x%10;
}
void countingSortForBase_k(int *a,int n,int k)
{
    int f[10];
    int* b = new int[n];

    for(int i=0;i<10;i++) f[i]=0;
    for(int i=0;i<n;i++) f[digit(a[i],k)]++;
    for(int i=1;i<10;i++)f[i]+=f[i-1];
    for(int i=n-1;i>=0;i--)
    {
        int tmp=digit(a[i],k);
        b[f[tmp]-1]=a[i];
        f[tmp]--;
    }

    for(int i=0;i<n;i++)a[i]=b[i];
    delete []b;

}

void shakerSort(int* a, int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;

        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void shellSort(int* a, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}
void flashSort(int* a, int n)
{
    int i = 0, j = n - 1;
    int m = (int)(0.45 * n);
    int min, max, maxIndex;
    min = max = a[0];
    maxIndex = 0;

    for (i = 1; i < n - 1; i += 2)
    {
        int small;
        int big;
        int bigIndex;

        if (a[i] < a[i + 1])
        {
            small = a[i];
            big = a[i + 1];
            bigIndex = i + 1;
        }
        else
        {
            big = a[i];
            bigIndex = i;
            small = a[i + 1];
        }

        if (big > max)
        {
            max = big;
            maxIndex = bigIndex;
        }

        if (small < min)
        {
            min = small;
        }
    }

    if (a[n - 1] < min)
    {
        min = a[n - 1];
    }
    else if (a[n - 1] > max)
    {
        max = a[n - 1];
        maxIndex = n - 1;
    }

    if (max == min)
    {
        return;
    }

    double c1 = (m - 1.0) / (max - min);
    int* l = new int[m];
    int k;

    for (k = 0; k < m; k++)
    {
        l[k] = 0;
    }
    for (j = 0; j < n; j++)
    {
        k = (int)(c1 * (a[j] - min));
        l[k] += 1;
    }

    for (k = 1; k < m; k++)
    {
        l[k] += l[k - 1];
    }

    int hold = a[maxIndex];
    a[maxIndex] = a[0];
    a[0] = hold;

    // permutation
    int move = 0, t, flash;
    j = 0;
    k = m - 1;

    while (move < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = (int)(c1 * (a[j] - min));
        }
        flash = a[j];

        while (!(j == l[k]))
        {
            k = (int)(c1 * (flash - min));
            hold = a[t = l[k] -= 1];
            a[t] = flash;
            flash = hold;
            move++;
        }
    }

    // insertion
    for (j = 1; j < n; j++)
    {
        hold = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > hold)
        {
            a[i + 1] = a[i--];
        }
        a[i + 1] = hold;
    }
    delete[] l;
}


