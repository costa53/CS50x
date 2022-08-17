from cs50 import get_int

while True:
    h = get_int("Height: ")
    if 1 <= h <= 8:
        break

for r in range(h):
    for c in range(h):
        if r + c < h - 1:
            print(" ", end="")
        else:
            print("#", end="")

    print("  " + "#" * (r + 1))