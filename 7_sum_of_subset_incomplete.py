def subset_sum(arr, target_sum,curr_subset,curr_sum,curr_index):
    if curr_sum == target_sum:
        for num in curr_subset:
          print(num)
          return
    if curr_index >= len(arr):
       return
    
    curr_subset.append(arr[curr_index])
    subset_sum(arr,target_sum,curr_subset,curr_sum+arr[curr_index],curr_index+1)
    curr_subset.pop()
    subset_sum(arr,target_sum,curr_subset,curr_sum,curr_index)

subset_sum([2,2,3],5,[],0,0)