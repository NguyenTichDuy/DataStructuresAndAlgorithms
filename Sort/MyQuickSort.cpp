#include<iostream>

using namespace std;

int Particition(int arr[], int left, int right);


void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Particition_r(int arr[], int left, int right)
{
    srand(time(NULL));
    int index = rand()%(right - left) + left;

    Swap(&arr[index], &arr[right]);

    return Particition(arr, left, right);
}
int Particition(int arr[], int left, int right)
{
    int pivot = arr[right];
    
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    
    Swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = Particition_r(arr, left, right);

        QuickSort(arr, left, pi - 1);
        QuickSort(arr, pi + 1, right);
    }
}
void PrintArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    
}
int main()
{
    int arr[] = {10, 80, 50, 90, 60, 20, 70};
    int right = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, right-1);
    PrintArray(arr, right);
}