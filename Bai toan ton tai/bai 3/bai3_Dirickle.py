import random

def init():
    print("Nhập n : ")
    n  = int(input())
    a = random.sample(range(0,100),n)
    return (a,n)

def CalculateSum(a):
    listSum = []
    sum = 0
    for i in range(len(a)):
        sum += a[i]
        listSum.append(sum)
    return listSum

def numtoDict(a):
    return dict(zip([i for i in range(len(a))], a))

def checkCase1(a,n):
    lsum = CalculateSum(a)
    for i in lsum:
        if(i%n != 0):
            return False
    return True

def checkCase2(a,n):
    lsum = CalculateSum(a)
    modSum = {}
    for i in lsum:
        modSum[i] = (i % n)
    dicMod = {}
    for i in modSum.values():
        if(i not in dicMod):
            dicMod[i] = 0
        dicMod[i] += 1
    print(f"dict số dư khi chia cho {n} (tong : sodu)")
    print(modSum)        
    
    # xem số lần xuất hiện của các số dư
    # for i in dicMod.keys():
    #     print(f"{i} : {dicMod[i]}")
    
    print("Tìm các tổng có cùng số dư .............")
    dupmod = []
    for i in dicMod.keys():
        if(dicMod[i] > 1): 
            dupmod.append(i)
    # print(dupmod)
    diclistSum = numtoDict(lsum)        
    for i in range(len(dupmod)):        
        ai = [k for k,v in modSum.items() if v == dupmod[i]] # find all keys with the same value in dict
        print("___________________")
        print(ai)
        print("Dãy tương ứng : ")
        printlist(ai,a,diclistSum)
        print("___________________")
    
def show(ia,ib,a):
    for i in range(ia,ib):
        print(a[i], end=" ")
    print()

def getIndexinDict(dic,x):
    return [k for k,v in dic.items() if v == x][0]

def printlist(ai,a,diclistSum):
    for i in range(len(ai)):
        for j in range(i+1,len(ai)):
            (x,y) = (ai[i],ai[j])
            (x,y) = (getIndexinDict(diclistSum,x), getIndexinDict(diclistSum,y))
            show(x+1,y+1,a)
            
            

if __name__ == "__main__":
    (a,n) = init()
    # (a,n) = ([10,5,25,30,35,41],5)
    print(f"Sinh {n} số nguyên dương : (id : a[i])")
    dicNuma = numtoDict(a)
    print(dicNuma)
    print("Tổng từ a[0] -> a[i] (id : sum)")
    lsum = CalculateSum(a)
    diclistSum = numtoDict(lsum)
    print(diclistSum)
    if(checkCase1(a,n)):
        #Nếu tồn tài một tổng[i] nào đó (i=1,2,3,...,n) chia hết cho n thì bài toán đã được chứng minh
        print(f"Tổng các phân tử trong dãy chia hết cho {n}")
    else:
        #Nếu không tồn tại một tổng nào đó chia hết cho n
        #Ta đem các tổng[i] chia cho n được số dư từ 1->n chỉ có n-1 số
        #Tương đương với xếp n thỏ vào n-1 chuồng
        #Tồn tại ít nhất 2 số s[i],s[j] có cùng số dư khi chia cho n 
        # => s[i] - s[j] là số chia hết cho n 
        # hay tồn tại tổng liên tiếp chia hết cho n có tổng = s[i] - s[j]
        checkCase2(a,n)
        
        