#include "mainHeader.h"

void measureSelectionSort(int *a, int n, long long &countCompare)
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
void measureInsertionSort(int *a, int n, long long &countCompare)
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

void measureBubbleSort(int *a, int n, long long &countCompare)
{
    return;
}

void measureShakerSort(int *a, int n, long long &countCompare)
{
    long long count_compare = 0;
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (++count_compare && swapped) // swapped == true
    {
        swapped = false;
        for (int i = start; ++count_compare && i < end; ++i)
        {
            if (++count_compare && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (++count_compare && !swapped)
            break;

        swapped = false;
        --end;
        for (int i = end - 1; ++count_compare && i >= start; --i)
        {
            if (++count_compare && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
    countCompare = count_compare;
    return;
}

void measureShellSort(int *a, int n, long long &countCompare)
{
    long long count_compare = 0;

    for (int gap = n / 2; ++count_compare && gap > 0; gap /= 2)
    {
        for (int i = gap; ++count_compare && i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; (++count_compare && j >= gap) && (++count_compare && a[j - gap] > temp); j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
    countCompare = count_compare;
}

void measureHeapSort(int *a, int n, long long &countCompare)
{

    for (int i = n / 2 - 1; ++countCompare, i >= 0; i--)
    {
        countCreateHeap(a, n, i, countCompare);
    }

    for (int i = n - 1; ++countCompare, i > 0; i--)
    {
        swap(a[0], a[i]);
        countCreateHeap(a, i, 0, countCompare);
    }
}
void countCreateHeap(int *a, int n, int pos, long long &countCompare)
{
    int next = pos;
    int left = pos * 2 + 1, right = 2 * pos + 2;

    if (++countCompare && left < n && ++countCompare && a[left] > a[next])
        next = left;
    if (++countCompare && right < n && ++countCompare && a[right] > a[next])
        next = right;

    if (++countCompare && next != pos)
    {
        swap(a[next], a[pos]);
        countCreateHeap(a, n, next, countCompare);
    }
}

void measureMergeSort(int *a, int n, long long &countCompare)
{
    countStartMergeSort(a, 0, n - 1, countCompare);
}
void countMergeArray(int *a, int l, int r, int mid, long long &countCompare)
{
    int t1 = mid - l + 1, t2 = r - mid;
    int *left_array = new int[t1];
    int *right_array = new int[t2];

    for (int i = l; ++countCompare, i <= mid; i++)
        left_array[i - l] = a[i];
    for (int i = mid + 1; ++countCompare, i <= r; i++)
        right_array[i - mid - 1] = a[i];

    int count1 = 0, count2 = 0, tmp = l;

    while (++countCompare && count1 < t1 && ++countCompare && count2 < t2)
    {
        if (++countCompare && left_array[count1] < right_array[count2])
        {
            a[tmp++] = left_array[count1++];
        }
        else
            a[tmp++] = right_array[count2++];
    }
    while (++countCompare && count1 < t1)
        a[tmp++] = left_array[count1++];
    while (++countCompare && count2 < t2)
        a[tmp++] = right_array[count2++];
}
void countStartMergeSort(int *a, int l, int r, long long &countCompare)
{
    if (++countCompare && l >= r)
        return;
    int mid = l + (r - l) / 2;
    ;
    countStartMergeSort(a, l, mid, countCompare);
    countStartMergeSort(a, mid + 1, r, countCompare);
    countMergeArray(a, l, r, mid, countCompare);
}

void measureQuickSort(int *a, int n, long long &countCompare) {}

void measureCountingSort(int *a, int n, long long &countCompare)
{
    countCompare = 0;

    int maxValue = a[0];

    for (int i = 0; ++countCompare, i < n; i++)
        if (++countCompare && maxValue < a[i])
            maxValue = a[i];

    int minValue = a[0];

    for (int i = 0; ++countCompare && i < n; i++)
        if (++countCompare && minValue > a[i])
            minValue = a[i];

    int maxNum = maxValue - minValue + 1;
    int *countArr = new int[maxNum];
    int *sortedArr = new int[n];

    for (int i = 0; ++countCompare, i < maxNum; i++)
        countArr[i] = 0;

    for (int i = 0; ++countCompare, i < n; i++)
        sortedArr[i] = 0;

    for (int i = 0; ++countCompare, i < n; i++)
        countArr[a[i] - minValue]++;
    for (int i = 1; ++countCompare, i < maxNum; i++)
        countArr[i] += countArr[i - 1];

    for (int i = 0; ++countCompare, i < n; i++)
    {
        sortedArr[countArr[a[i] - minValue] - 1] = a[i];
        countArr[a[i] - minValue]--;
    }
    for (int i = 0; ++countCompare, i < n; i++)
        a[i] = sortedArr[i];
}

void measureRadixSort(int *a, int n, long long &countCompare)
{
    countCompare = 0;
    // find max element
    int maxnum = a[0];
    for (int i = 1; ++countCompare, i < n; i++)
    {
        if (++countCompare && maxnum < a[i])
            maxnum = a[i];
    }
    int d = countDigit2(maxnum, countCompare);
    for (int i = 1; ++countCompare, i <= d; i++)
    {
        countCountingSortForBase_k(a, n, i, countCompare);
    }
}
int countDigit2(int x, long long &countCompare)
{
    int t = 0;
    while (++countCompare && x > 0)
    {
        x /= 10;
        t++;
    }
    return t;
}
int digit2(int x, int k, long long &countCompare)
{
    for (int i = 1; ++countCompare, i < k; i++)
        x /= 10;
    return x % 10;
}
void countCountingSortForBase_k(int *a, int n, int k, long long &countCompare)
{
    int f[10];
    int *b = new int[n];
    for (int i = 0; ++countCompare, i < 10; i++)
        f[i] = 0;
    for (int i = 0; ++countCompare, i < n; i++)
        f[digit2(a[i], k, countCompare)]++;
    for (int i = 1; ++countCompare, i < 10; i++)
        f[i] += f[i - 1];
    for (int i = n - 1; ++countCompare, i >= 0; i--)
    {
        int tmp = digit2(a[i], k, countCompare);
        b[f[tmp] - 1] = a[i];
        f[tmp]--;
    }

    for (int i = 0; ++countCompare, i < n; i++)
        a[i] = b[i];
}

void measureFlashSort(int *a, int n, long long &countCompare)
{
    long long count_compare = 0;
    int i = 0, j = n - 1;
    int m = (int)(0.45 * n);
    int min, max, maxIndex;
    min = max = a[0];
    maxIndex = 0;

    for (i = 1; ++count_compare && i < n - 1; i += 2)
    {
        int small;
        int big;
        int bigIndex;

        if (++count_compare && a[i] < a[i + 1])
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

        if (++count_compare && big > max)
        {
            max = big;
            maxIndex = bigIndex;
        }

        if (++count_compare && small < min)
        {
            min = small;
        }
    }

    if (++count_compare && a[n - 1] < min)
    {
        min = a[n - 1];
    }
    else if (++count_compare && a[n - 1] > max)
    {
        max = a[n - 1];
        maxIndex = n - 1;
    }

    if (++count_compare && max == min)
    {
        return;
    }

    double c1 = (m - 1.0) / (max - min);
    int *l = new int[m];
    int k;

    for (k = 0; ++count_compare && k < m; k++)
    {
        l[k] = 0;
    }
    for (j = 0; ++count_compare && j < n; j++)
    {
        k = (int)(c1 * (a[j] - min));
        l[k] += 1;
    }

    for (k = 1; ++count_compare && k < m; k++)
    {
        l[k] += l[k - 1];
    }

    int hold = a[maxIndex];
    a[maxIndex] = a[0];
    a[0] = hold;

    int move = 0, t, flash;
    j = 0;
    k = m - 1;

    while (++count_compare && move < n - 1)
    {
        while (++count_compare && j > l[k] - 1)
        {
            j++;
            k = (int)(c1 * (a[j] - min));
        }
        flash = a[j];

        while (++count_compare && !(j == l[k]))
        {
            k = (int)(c1 * (flash - min));
            hold = a[t = l[k] -= 1];
            a[t] = flash;
            flash = hold;
            move++;
        }
    }

    for (j = 1; ++count_compare && j < n; j++)
    {
        hold = a[j];
        i = j - 1;
        while (++count_compare && i >= 0 && a[i] > hold)
        {
            a[i + 1] = a[i--];
        }
        a[i + 1] = hold;
    }
    delete[] l;
    countCompare = count_compare;
}