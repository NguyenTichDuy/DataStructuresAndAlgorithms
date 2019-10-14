#include<iostream>


using namespace std;

int countSwap = 0;


long Particition(long arr[], long left, long right);
void Swap(long *a, long *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void QuickSort(long arr[], long left, long right)
{
    if (left < right)
    {
        long pi = Particition(arr, left, right);

        QuickSort(arr, left, pi-1);
        QuickSort(arr, pi+ 1, right);
    }
}

long Particition(long arr[], long left, long right)
{
    long pivot = arr[right];
    long i = left -1;
    for (long j = left; j <= right - 1; j++)
    {
        if (abs(arr[j]) < abs(pivot))
        {   
            i++;
            Swap(&arr[i], &arr[j]);
            countSwap++;
        }
    }
    Swap(&arr[i+1], &arr[right]);
    countSwap++;
    return (i + 1);
}
long count_swap(long arr[], long right)
{
    for (int j = 0; j <= right; j+=2)
    {
        if (arr[j] > arr[j + 1])
        {
            Swap(&arr[j + 1], &arr[j]);
            countSwap++;
        }
            
    }

    return countSwap;
}

int main()
{
    long arr[]={4, 6, -4, -6};
    long right = sizeof(arr) / sizeof(long) - 1;
    QuickSort(arr, 0, right);

   
    cout << count_swap(arr, right);
     cout << "\n";
        for (int i = 0; i < right+1; i++)
    {
        cout << arr[i] << " ";
    }
}