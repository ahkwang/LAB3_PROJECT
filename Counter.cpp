#include "mainHeader.h"

void  measureSelectionSort(int* a, int n, long long & countCompare)
{
	countCompare = 0;

	for (size_t i = 0; (++countCompare), i < n - 1; i++)
	{
		int minIdx = i;

		for (size_t j = i + 1; (++countCompare), j < n; j++)
		{
			if (++countCompare && a[minIdx] > a[j])
			{
				minIdx = j;
			}
		}

		swap(a[i], a[minIdx]);
	}
}
void  measureInsertionSort(int* a, int n, long long & countCompare)
{
	countCompare = 0;

	for (int i = 1; (++countCompare), i < n; i++)
	{
		int key = a[i];
		int idx = i - 1;

		while (++countCompare && a[idx] > key && ++countCompare && idx >= 0)
		{
			a[idx + 1] = a[idx--];
		}

		a[idx + 1] = key;
	}
}

void  measureBubbleSort(int* a, int n, long long& countCompare)
{
	return;
}

void  measureShakerSort(int* a, int n, long long& countCompare)
{
	return;
}

void  measureShellSort(int* a, int n, long long& countCompare){}


void measureHeapSort(int *a,int n, long long &countCompare)
{

    for(int i=n/2-1;++countCompare,i>=0;i--)
    {
        countCreateHeap(a,n,i,countCompare);
    }

    for(int i=n-1; ++countCompare, i>0;i--)
    {
        swap(a[0],a[i]);
        countCreateHeap(a,i,0,countCompare);
    }
}
void countCreateHeap(int *a,int n, int pos, long long &countCompare)
{
    int next=pos;
    int left= pos*2+1,right=2*pos+2;


    if(++countCompare && left<n && ++countCompare&&a[left]>a[next] )next=left;
    if(++countCompare && right<n && ++countCompare && a[right]>a[next])next=right;

    if(++countCompare && next!=pos)
    {
        swap(a[next],a[pos]);
        countCreateHeap(a,n,next,countCompare);
    }
}


void measureMergeSort(int *a,int n , long long &countCompare)
{
    countStartMergeSort(a,0,n-1,countCompare);
}
void countMergeArray(int *a,int l,int r,int mid, long long &countCompare)
{
    int t1=mid-l+1,t2=r-mid;
	int *left_array =new int[t1];
	int *right_array=new int [t2];

    for(int i=l; ++countCompare , i<=mid;i++)left_array[i-l]=a[i];
    for(int i=mid+1;++countCompare, i<=r;i++)right_array[i-mid-1]=a[i];

    int count1=0,count2=0,tmp=l;

    while(++countCompare && count1<t1 && ++countCompare && count2<t2)
    {
        if(++countCompare && left_array[count1]<right_array[count2])
        {
            a[tmp++]=left_array[count1++];
        }
        else a[tmp++]=right_array[count2++];
    }
    while(++countCompare && count1<t1)a[tmp++]=left_array[count1++];
    while(++countCompare && count2<t2)a[tmp++]=right_array[count2++];
	delete [] left_array;
	delete [] right_array;
}
void countStartMergeSort(int *a, int l, int r, long long &countCompare)
{
    if(++countCompare && l>=r)return;
    int mid=l+(r-l)/2;;
    countStartMergeSort(a,l,mid,countCompare);
    countStartMergeSort(a,mid+1,r,countCompare);
    countMergeArray(a,l,r,mid,countCompare);
}


void  measureQuickSort(int* a, int n, long long& countCompare){}

void  measureCountingSort(int* a, int n, long long& countCompare){}

void measureRadixSort(int *a, int n, long long &countCompare)
{
    countCompare=0;
    //find max element
    int maxnum=a[0];
    for(int i=1;++countCompare,i<n;i++)
    {
        if(++countCompare && maxnum<a[i])maxnum=a[i];
    }
    int d=countDigit2(maxnum,countCompare);
    for(int i=1;++countCompare,i<=d;i++)
    {
        countCountingSortForBase_k(a,n,i,countCompare);
    }
}
int countDigit2(int x, long long &countCompare)
{
    int t=0;
    while(++countCompare && x>0)
    {
        x/=10;
        t++;
    }
    return t;
}
int digit2(int x,int k, long long &countCompare)
{
    for(int i=1;++countCompare,i<k;i++) x/=10;
    return x%10;
}
void countCountingSortForBase_k(int *a,int n,int k,long long &countCompare)
{
    int f[10];
	int *b=new int [n];
    for(int i=0;++countCompare,i<10;i++) f[i]=0;
    for(int i=0;++countCompare,i<n;i++) f[digit2(a[i],k,countCompare)]++;
    for(int i=1;++countCompare,i<10;i++)f[i]+=f[i-1];
    for(int i=n-1;++countCompare,i>=0;i--)
    {
        int tmp=digit2(a[i],k,countCompare);
        b[f[tmp]-1]=a[i];
        f[tmp]--;
    }

    for(int i=0;++countCompare,i<n;i++)a[i]=b[i];
	delete [] b;
}



void measureFlashSort(int* a, int n, long long& countCompare){}