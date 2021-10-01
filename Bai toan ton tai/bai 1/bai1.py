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

print("Sau khi sắp xếp mảng : ")
array.sort()
print(array)
print("Các cặp số nguyên tố cùng nhau : ")
for i in range(len(array)):
    for j in range(i,len(array)):
        if(gcd(array[i],array[j]) == 1 ):
            print(array[i], array[j])
            
