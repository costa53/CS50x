from cs50 import get_int

while True:
    number = get_int("Number: ")
    if number > 0:
        break

count = len(str(number))
if count < 13 or count > 16:
    print("INVALID")
    exit()

even = cod = s1 = s2 = 0
while number != 0:
    dig = number % 10
    even += 1
    if even % 2 == 0:
        dig = int(dig) * 2
        if dig > 9:
            dig = (int(dig) % 10) + 1
        s1 = int(s1) + dig
    else:
        s2 = int(s2) + dig

    n = int(number)
    if 10 < n < 100:
        if (65 <= n <= 69) and count == 16:
            cod = 1
        elif (51 <= n <= 55) and count == 16:
            cod = 2
        elif (40 <= n <= 49) and (count == 13 or count == 16):
            cod = 3
        elif (n == 34 or n == 37) and count == 15:
            cod = 4
        else:
            print("INVALID")
            exit()
    number /= 10

sum = int(s1 + s2)
if sum % 10 == 0:
    if cod == 1:
        print("ELO")
    elif cod == 2:
        print("MASTERCARD")
    elif cod == 3:
        print("VISA")
    elif cod == 4:
        print("AMEX")
else:
    print("INVALID")
    exit()