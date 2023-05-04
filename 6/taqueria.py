def main():

    menu = {
        "Baja Taco": 4.00,
        "Burrito": 7.50,
        "Bowl": 8.50,
        "Nachos": 11.00,
        "Quesadilla": 8.50,
        "Super Burrito": 8.50,
        "Super Quesadilla": 9.50,
        "Taco": 3.00,
        "Tortilla Salad": 8.00
    }

    try:
        item = input('Item: ')

        price = 0

        while True:
            if item.title() in menu:
                price += menu[item.title()]
                print(f'Total: ${"%.2f" % price}')

            item = input('Item: ')
    except EOFError:
        print('\n')


main()


# while item != 'exit':
#             if item.title() in menu:
#                 price += menu[item.title()]
#                 print(f'Total: ${"%.2f" % price}')
#             if item == 'exit':
#                 break
#             item = input('Item: ')

# Sławek