# TODO

#VERSION 1:
#___________________________________

# height = input("Height: ")

# while not height.isnumeric() or not (int(height) > 0 and int(height) < 9):
#     height = input("Height: ")

# height = int(height)

# j = height

# for i in range(height):
#     print(' ' * (j - 1), end='')
#     j -= 1
#     print('#' * (i + 1), end='')
#     print('  ', end='')
#     print('#' * (i + 1))

#VERSION 2:
#___________________________________

while True:
    height = input("Height: ")
    if height.isnumeric() and (int(height) > 0 and int(height) < 9):
        break

height = int(height)

j = height

for i in range(height):
    print(' ' * (j - 1), end='')
    j -= 1
    print('#' * (i + 1), end='')
    print('  ', end='')
    print('#' * (i + 1))
# Sławek