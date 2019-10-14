#include<iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
    
int partition(int arr[], int left, int right)
{
    //int maxLength = sizeof(arr) / sizeof(int);
    int pivot =  arr[right]; //arr[rand()%(maxLength)];
    
    int i = left - 1;

    for (int j  = left; j <= right - 1; j++)
    {
        if (left < pivot)
        {
            i++;
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i+ 1], arr[right]);
    return (i+1);
}
void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);

        partition(arr, left, pi-1);
        partition(arr, pi + 1, right);
    }
}
void PrintArray(int arr[], int maxLength)
{
    for (int i = 0; i < maxLength; i++)
    {
        cout << arr[i] << ' ';
    }
    
}
int main()
{
    int arr[] = {1, 4,5 , 6, 6, 7, 9, 20};
    cout << sizeof(arr) / 4<< endl;
    QuickSort(arr, 0, sizeof(arr) / 4 - 1);
    PrintArray(arr, sizeof(arr) / 4);
}