nums1=list(map(int,input().split(' ')))
nums2=list(map(int,input().split(' ')))
total=nums1+nums2
total.sort()
print(total)
if len(total)%2==0:
    print((total[len(total)//2]+total[len(total)//2-1])/2)
else:
    print(total[(len(total)-1)//2])
