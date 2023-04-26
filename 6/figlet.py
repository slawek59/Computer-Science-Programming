from pyfiglet import Figlet
from sys import argv, exit
import random

figlet = Figlet()
fonts = figlet.getFonts()
if len(argv) == 1:
    f = random.choice(fonts)
    figlet.setFont(font=f)
    s = input('Input: ')
    print(figlet.renderText(s))
elif len(argv) == 3:
    if argv[1] != '-f' and argv[1] != '--font':
        print('Invalid usage')
        exit(1)
    elif argv[2] not in fonts:
        print('Invalid usage')
        exit(1)
    else:
        f = argv[2]
        figlet.setFont(font=f)
        s = input('Input: ')
        print(figlet.renderText(s))
elif len(argv) == 2:
    print('Invalid usage')
    exit(1)

#Sławek