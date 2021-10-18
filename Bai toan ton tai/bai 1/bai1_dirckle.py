import random
random.seed(10)
def gcd(a,b):
    if(b == 0):
        return a
    return gcd(b,a % b)

print("Nhap n : ")

n = int(input())
array = list()
array = random.sample(range(0,2*n),n+1)
print("Sinh mảng ngẫu nhiên n + 1 số nguyên dương khác nhau <= 2n ")
print(array)

# sắp xếp lại mảng 
print("Mảng ngẫu nhiên sau sắp xếp : ")
array.sort()
print(array)
# 
# Tìm hai phần tử liên tiếp nhau trong mảng. 
# Hai phần tử liên tiếp nhau luôn là nguyên tố cùng nhau. 
# (1,2),(3,4),(5,6),..(2n-1,2n) . 2n số chia ra được n tập con có hai phần tử liên tiếp không lặp lại.

print("Ta tìm được một số cặp số nguyên tố cùng nhau : ")
for i in range(len(array)-1):
    if (array[i]+1 == array[i+1]):
        print(array[i],array[i+1])
        