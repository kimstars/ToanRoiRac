import random

line = []

for i in range(7):
    line.append(random.randrange(10, 100))
print("7 đoạn thẳng ngẫu nhiên có độ dài trong khoảng (10,100):")
print(line)
line.sort()


def checkTamgiac(a,b,c):
    if(a+b > c): return True
    return False

print("\nCác bộ đoạn thẳng tạo được thành tam giác : ")
for i in range(5):
    for j in range(i+1,5):
        for t in range(j+1, 5):
            if(checkTamgiac(line[i], line[j], line[t])):
                print(line[i], line[j], line[t])