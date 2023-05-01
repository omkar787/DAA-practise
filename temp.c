void merge(int *arr, int n, int start, int mid, int end)
{
    // Creating 2 arrays to store the sub arrays
    int first_len = mid - start + 1;
    int second_len = end - mid;
    int *first = (int *)malloc(sizeof(int) * first_len);
    int *second = (int *)malloc(sizeof(int) * second_len);

    for (int i = 0; i < first_len; i++)
    {
        first[i] = arr[start + i];
    }

    for (int i = 0; i < second_len; i++)
    {
        second[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = start;
    while (i < first_len && j < second_len)
    {
        if (first[i] <= second[j])
        {
            arr[k] = first[i];
            i++;
        }
        else
        {
            arr[k] = second[j];
            j++;
        }
        k++;
    }

    while (i < first_len)
    {
        arr[k] = first[i];
        i++;
        k++;
    }
    while (j < second_len)
    {
        arr[k] = second[j];
        j++;
        k++;
    }

    free(first);
    free(second);
}

void merge_sort(int *arr, int n, int start, int end)
{
    if (start < end)
    {
        int mid = (int)(start + end) / 2;
        merge_sort(arr, n, start, mid);
        merge_sort(arr, n, mid + 1, end);
        merge(arr, n, start, mid, end);
    }
}

int main(void)
{
    int *arr = (int *)malloc(sizeof(int) * 5);
    arr[0] = 5;
    arr[1] = 4;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 1;
    merge_sort(arr, 5, 0, 5 - 1);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
