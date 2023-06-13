# TODO

from cs50 import get_string

number = get_string("Number: ")

index = len(number) - 2
index2 = len(number) - 1
list = []
list2 = []
sum = 0
valid = False

while (index >= 0):
    list.append(int(number[index]))
    index -= 2
    if (index < 0):
        break

while (index2 >= 0):
    list2.append(int(number[index2]))
    index2 -= 2
    if (index2 < 0):
        break

for num in list:
    num *= 2
    if (num >= 0 and num < 10):
        sum += num
    else:
        num2 = num % 10
        num3 = 1
        sum += num2 + num3

for i in list2:
    sum += i

if (sum % 10 == 0):
    valid = True

if (number[0:2] in {"34", "37"} and len(number) == 15 and valid):
    print("AMEX")
elif (number[0] == "4" and (len(number) == 13 or len(number) == 16)) and valid:
    print("VISA")
elif (number[0:2] in {"51", "52", "53", "54", "55"} and len(number) == 16 and valid):
    print("MASTERCARD")
else:
    print("INVALID")

# Sławek