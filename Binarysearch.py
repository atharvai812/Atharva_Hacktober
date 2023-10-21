a=int(input("Enter the size of string."))
L=[]

for i in range(a):
    x=input()
    L.append(x)

print(L)

def Binary_Search(ele,low,high):
     
    ele=input("Enter the element to search")
    low=0
    high=len(L)
    mid=(low+high)//2

    while(low<=high):
        if(ele == L[mid]):
            print("Element found at ",mid)
        elif(ele>L[mid]):
            low=mid+1
        elif(ele<L[mid]):
            high=mid-1
        else:
            return mid
    Binary_Search(ele,low,high)