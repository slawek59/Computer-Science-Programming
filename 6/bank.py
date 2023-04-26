greeting = input('Greeting: ')

if greeting.lower().strip()[0:5] == 'hello':
    print('$0')

elif greeting[0].lower().strip() == 'h':
    print('$20')

else:
    print('$100')


#Sławek