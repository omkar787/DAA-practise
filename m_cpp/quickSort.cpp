#include <iostream>
using namespace std;

int partition(int low, int high, int arr[])
{
    int pivot = low;
    int i, j;
    i = low;
    j = high;
    int temp;
    while (i < j)
    {
        while (i <= high && arr[pivot] > arr[i])
        {
            i++;
        }
        while (j >= low && arr[pivot] < arr[j])
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int low, int high, int arr[])
{
    if (low < high)
    {
        int pivot = partition(low, high, arr);
        quickSort(low, pivot - 1, arr);
        quickSort(pivot + 1, high, arr);
    }
}

int main()
{
    int arr[] = {84, 2, 50, 1, 41, 3, 10, 0};

    quickSort(0, 7, arr);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}