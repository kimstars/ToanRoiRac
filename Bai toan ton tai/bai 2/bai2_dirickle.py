import random

line = []

for i in range(7):
    line.append(random.randrange(10, 100))
print("7 đoạn thẳng ngẫu nhiên có độ dài trong khoảng (10,100):")
print(line)
#sắp xếp lại các cạnh theo thứ tự tăng dần
line.sort()


def checkTamgiac(a,b,c):
    if(a+b > c): return True
    return False

#

print("\nĐoạn thẳng tạo được thành tam giác là : ")
for i in range(0,5):
    if(checkTamgiac(line[i],line[i+1],line[i+2])):
        print(line[i],line[i+1],line[i+2])
        break