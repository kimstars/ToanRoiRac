
number_list = [590,504, 540, 342 , 100, 345,760,4500,6060]

def clear(num):
    while(num % 10 == 0):
        num //= 10
    return int(str(num)[::-1])

def reverse_number_in_list(number_list):
    return  [clear(i) for i in number_list]
    
res = reverse_number_in_list(number_list)

print(res)