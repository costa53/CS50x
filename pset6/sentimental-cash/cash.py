from cs50 import get_float

while True:
    v = get_float("Change owed: ") * 100
    if v > 0:
        break

coins = 0
while True:
    if v >= 25:
        v -= 25
        coins += 1
    elif v >= 10:
        v -= 10
        coins += 1
    elif v >= 5:
        v -= 5
        coins += 1
    elif v >= 1:
        v -= 1
        coins += 1
    else:
        break

print(coins)