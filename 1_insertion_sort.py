arr = [15,13,3,512,5,14]

def insertion_sort(vector:list):
    for i in range(1, len(vector)):
      j = i
      key = arr[i]
      while j > 0 and vector[j-1] > key:
        vector[j] = vector[j-1]
        j-=1

      vector[j] = key

    
    print(vector)

insertion_sort(arr)


                
        