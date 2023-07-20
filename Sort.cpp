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

void bubbleSort(int* a, int n) {}

void shakerSort(int* a, int n){}

void shellSort(int* a, int n){}


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
    int* left_array= new int[t1];
    int* right_array=new int[t2];
    

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


void quickSort(int* a, int n){}

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
    int *b=new int[n];
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

void flashSort(int* a, int n){}

