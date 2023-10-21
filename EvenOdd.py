L=[2,4,2,6,34,7,4,326,4,2,5,4]
L1=[]
sum=0

for i in L:
    if(i%2==0):
        L1.append(i)
    else:
        sum+=i

print(L1)
print("The sum of odd number is :",sum)
