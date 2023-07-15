import csv
from cs50 import SQL

db = SQL("sqlite:///favorites.db")
proper_shows = []
wrong = []

with open("list.csv") as csvfile:
    proper = csv.reader(csvfile)
    for row in proper:
        proper_shows.append(row[0])

for row in db.execute("SELECT * FROM shows;"):
    wrong.append(row["title"])

for i in range(len(proper_shows)):
    db.execute("UPDATE shows SET title = ? WHERE title LIKE ?", proper_shows[i], proper_shows[i])

print(wrong)

for i in range(len(proper_shows)):
    test = (db.execute("SELECT title FROM shows WHERE title LIKE ?", proper_shows[i]))
    for j in range(len(test)):
        print(test[j]['title'])

test2 = db.execute("SELECT title FROM shows ORDER BY title asc")

for i in range(len(test2)):
    print(test2[i]["title"])

# Sławek