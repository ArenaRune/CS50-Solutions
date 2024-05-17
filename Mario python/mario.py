from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 0 < n < 9:
        break

e = " "
h = "#"

for i in range(1,n+1):
    print(e*(n-i)+h*i+e*2,end="")
    print(h*i)