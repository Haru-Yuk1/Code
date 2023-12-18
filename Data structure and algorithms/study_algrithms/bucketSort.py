def BucketSort(arr):
    size=(max(arr)-min(arr))/len(arr)+1
    cnt=(max(arr)-min(arr))/size+1
    buckets=[[] for _ in range(cnt)]
    for num in arr:
        buckets[cnt-1].append(num)
    