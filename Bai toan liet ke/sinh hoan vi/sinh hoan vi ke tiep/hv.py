

def swap(a, b):
    return (b, a)


def nextPermutation(a):
    n = len(a)
    j = n - 2
    # 43253
    while(a[j] > a[j+1] and j >= 0):
        j -= 1
    if(j > 0):
        print(a)
    else:
        k = n - 1
        while(a[j] > a[k]):
            k -= 1
        (a[j], a[k]) = swap(a[j], a[k])

        r = j + 1
        s = n - 1
        while(r < s):
            (a[r], a[s]) = swap(a[r], a[s])
            r += 1
            s -= 1
        print(a)
    # return 0


a = 1341243

a = list(str(a))
a = [int(i) for i in a]
print(a)

(a[0],a[4]) = swap(a[0],a[4])

print(a)
# for i in range(10):
# nextPermutation(a)

# b = 10

