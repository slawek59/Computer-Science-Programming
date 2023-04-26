from sys import exit

while (True):
    greeting = input('Enter "start" to start or "exit" to exit the app: ')
    if greeting == 'start' or greeting == 'exit':
        break

if greeting == 'exit':
    exit(0)
elif greeting == 'start':
    while greeting != 'exit':

        greeting = input('Greeting: ')

        if greeting.lower().strip()[0:5] == 'hello':
            print('$0')

        elif greeting[0].lower().strip() == 'h':
            print('$20')

        else:
            print('$100')
    if greeting == 'exit':
        exit(0)

#Sławek