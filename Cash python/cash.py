from cs50 import get_float
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

change *= 100

q = change//25
change %= 25
d = change//10
change %= 10
n = change//5
change %= 5

coins = q+d+n+change
coins = int(coins)
print(coins)
