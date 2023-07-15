import csv
from cs50 import SQL

db = SQL("sqlite:///roster.db")

student_list = []

with open("students.csv") as csvfile:
    students = csv.DictReader(csvfile)
    for row in students:
        student_list.append(row)

for i in range(len(student_list)):
    db.execute("INSERT INTO students (student_name) VALUES (?)", student_list[i]["student_name"])

for i in range(len(student_list)):
    db.execute("INSERT INTO houses (house_name, head) VALUES (?, ?)", student_list[i]["house"], student_list[i]["head"])

for i in range(len(student_list)):
    student_id = db.execute("SELECT id FROM students")
    house_id = db.execute("SELECT house_id FROM houses")

    db.execute("INSERT INTO assignments (student_id,house_id) VALUES (?,?)", student_id[i]["id"], house_id[i]["house_id"])

# Sławek