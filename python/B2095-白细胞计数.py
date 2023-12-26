n=int(input())
sample=[]
for i in range(n):
    sample.append(float(input()))

sample.remove(max(sample))
sample.remove(min(sample))
average=0.0
for i in range(n-2):
    average+=sample[i]/(n-2)

for i in range(n-2):
    sample[i]=abs(sample[i]-average)
print('%.2f' % average+' '+'%.2f' %max(sample))