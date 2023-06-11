# TODO

from cs50 import get_float

while True:
    owed = get_float('Change owed: ')
    if owed >= 0:
        break

coins = 0

quarters = int(owed / 0.25)

owed = round(owed - quarters * 0.25, 2)

dimes = int(owed / 0.1)

owed = round(owed - dimes * 0.1, 2)

nickel = int(owed / 0.05)

owed = round(owed - nickel * 0.05, 2)

pennies = int(owed / 0.01)

owed = round(owed - pennies * 0.01, 2)

coins = quarters + dimes + nickel + pennies

print(coins)

# Sławek
