import math
arr = [i for i in range(10000000,0,-1)]

def merge(arr,start,mid,end):
    first = arr[start:mid+1]
    second = arr[mid+1:end+1]

    
    i = j = 0
    k = start
    while i < len(first) and j < len(second):
        if first[i] <= second[j]:
            arr[k] = first[i]
            i += 1
        else:
            arr[k] = second[j]
            j += 1
        k += 1

    while i < len(first):
        arr[k] = first[i]
        i += 1
        k += 1

    while j < len(second):
        arr[k] = second[j]
        j += 1
        k += 1
            

def merge_sort(arr,start,end):
    if start < end:
        mid = math.floor((start+end)/2)
        merge_sort(arr,start,mid)
        merge_sort(arr,mid+1,end)
        merge(arr,start,mid,end)



merge_sort(arr,0,len(arr)-1)
print(arr)