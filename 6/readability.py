# TODO

import cs50

text = cs50.get_string('Text: ')

letters = 0

words = 0

sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i].isspace():
        words += 1
    elif ord(text[i]) == 46 or ord(text[i]) == 33 or ord(text[i]) == 63:
        sentences += 1

words += 1


L = letters / words * 100
S = sentences / words * 100

level = round(0.0588 * L - 0.296 * S - 15.8)

if level < 1:
    print('Before Grade 1')
elif level > 16:
    print('Grade 16+')
else:
    print(f'Grade: {level}')

