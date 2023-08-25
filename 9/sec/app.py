from cs50 import SQL
from flask import Flask, render_template, request
from helpers import random_string
import random

app = Flask(__name__)

db = SQL("sqlite:///history.db")

app.config["TEMPLATES_AUTO_RELOAD"] = True

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        page = request.form.get("page")

        db.execute("INSERT INTO history (page) VALUES (?)", page)
        rows = db.execute("SELECT * FROM history;")
        print(rows)


        try:
            page = int(page)
        except ValueError:
            return render_template("index.html", random_string="Type in a number.", history=rows, name="Sławek")

        if page < 0:
            return render_template("index.html", random_string="Type in a positive number.", history=rows, name="Sławek")

        # db.execute("INSERT INTO history (page) VALUES (?);", page)
        random.seed(page)

    string = random_string(100)
    rows = db.execute("SELECT * FROM history;")
    return render_template("index.html", random_string=string, history=rows, name="Sławek")
