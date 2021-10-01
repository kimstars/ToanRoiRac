import random

def init():
    print("Nhập n : ")
    n  = int(input())
    a = random.sample(range(0,100),n)
    return (a,n)
    
def createDict(a):
    dic = {}
    for i in range(n):
        sum = a[i]
        s = 0
        for j in range(i+1,n):
            sum += a[j]
            if(sum % n == 0):
                s = sum
        dic[a[i]] = s
    return dic
    
def Trace(a,idm):
    index = a.index(idm)
    sum = dic[idm]
    for i in range(index,n):
        if(not sum):
            break
        print(a[i], end=" ")
        sum -= a[i]
    print()
    

if __name__ == "__main__":
    (a,n) = init()
    dic = createDict(a)
    print(a)
    print(dic)
    idmax = max(dic, key=dic.get) # find key have max value
    check = len([i for i in dic.values() if i])
    # print(f"check = {check}")
    if(check == 0):
        print(f"Không tìm được dãy liên tiếp có tổng chia hết cho {n}")
    else:
        print(f"Dãy con liên tiếp dài nhất có tổng chia hết cho {n} là :")
        Trace(a,idmax)
    if(check >1):
        print(f"\nDãy khác có tổng chia hết cho {n}:")
        for i in a:
            if(dic[i] and i != idmax):
                Trace(a,i)




