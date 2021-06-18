from cs50 import get_int

def check_number(number):
    if (number >= 100000000000000 and number <= 999999999999999) and (number // 10000000000000 == 34 or number // 10000000000000 == 37):
        return(1)
    elif (number >= 1000000000000000 and number <= 9999999999999999) and \
    (number // 100000000000000 == 51 or number // 100000000000000 == 52 or \
     number // 100000000000000 == 53 or number // 100000000000000 == 54 or number // 100000000000000 == 55):
        return(2)
    elif (number >= 1000000000000 and number <= 9999999999999 and number // 1000000000000 == 4) or \
    (number >= 1000000000000000 and number <= 9999999999999999 and number // 1000000000000000 == 4):
        return(3)
    return(0)

number = 0
digits = 1
digitscnt = 0
sums = 0
while number < 1000000000:
    number = get_int("Number: ")
tmp = number
while tmp:
    digits *= 10
    digitscnt += 1
    tmp = tmp // 10
digits = digits // 10
while digitscnt:
    tmp = (number // digits) % 10
    if digitscnt % 2 == 1:
        sums += tmp
    else:
        tmp *= 2
        if not tmp // 10:
            sums += tmp
        else:
            sums += tmp // 10 + tmp % 10
    digitscnt -= 1
    digits //= 10
if (sums % 10 == 0):
    if check_number(number) == 1:
        print("AMEX")
    elif check_number(number) == 2:
        print("MASTERCARD")
    elif check_number(number) == 3:
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")