import os
from datetime import datetime
from pytz import timezone


from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "GET":
        log = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[
            0
        ]["username"]
        check_for_shares = db.execute(
            "SELECT * FROM shares WHERE user_id = ? ", session["user_id"]
        )

        cash_left = db.execute(
            "SELECT cash FROM users WHERE id = ?", session["user_id"]
        )[0]["cash"]
        grand_total = cash_left

        if len(check_for_shares) != 0:
            check = True

            symbols = db.execute(
                "SELECT share_symbol FROM shares WHERE user_id = ?", session["user_id"]
            )
            print(f"AHGLCUHNGKSHCNGSDLHGCLND {symbols}")

            symbols_list = []
            current_price_list = []
            number_of_shares_list = []
            total_list = []
            total_in_shares = 0

            for i in range(len(symbols)):
                symbols_list.append(symbols[i]["share_symbol"])

                current_price_list.append(lookup(symbols_list[i])["price"])

                number_of_shares_list.append(
                    db.execute(
                        "SELECT number_of_shares FROM shares WHERE share_symbol = ? AND user_id =?",
                        symbols_list[i],
                        session["user_id"],
                    )[0]["number_of_shares"]
                )
                print(number_of_shares_list)

                total_list.append(
                    float(current_price_list[i]) * float(number_of_shares_list[i])
                )
                total_in_shares = total_in_shares + total_list[i]

            cash_left = db.execute(
                "SELECT cash FROM users WHERE id = ?", session["user_id"]
            )[0]["cash"]

            grand_total = cash_left + total_in_shares

            return render_template(
                "index.html",
                symbols_list=symbols_list,
                current_price_list=current_price_list,
                number_of_shares_list=number_of_shares_list,
                total_list=total_list,
                cash_left=cash_left,
                grand_total=grand_total,
                check=check,
                log=log,
            )

        else:
            return render_template(
                "index.html", cash_left=cash_left, grand_total=grand_total, log=log
            )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        log = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[
            0
        ]["username"]
        return render_template("buy.html", log=log)

    elif request.method == "POST":
        share_name = request.form.get("symbol")
        symbol = lookup(share_name)

        if symbol != None:
            if len(request.form.get("shares")) == 0:
                return apology("Specify number of shares.")

            if not request.form.get("shares").isdigit():
                return apology("Insert positive integers only.")

            number_of_shares = int(request.form.get("shares"))
            price_each = symbol["price"]
            price_to_pay = price_each * number_of_shares
            balance = db.execute(
                "SELECT cash FROM users WHERE id = ?", session["user_id"]
            )[0]["cash"]
            money_left = balance - price_to_pay

            if len(share_name) == 0:
                return apology("Missing symbol.")

            elif number_of_shares <= 0:
                return apology("Why should you try to buy 0 shares like srsly...")

            elif money_left < 0:
                return apology("You are too poor.")

            else:
                date_time = datetime.now(timezone("Europe/Warsaw"))
                db.execute(
                    "UPDATE users SET cash = ? WHERE id = ?",
                    money_left,
                    session["user_id"],
                )

                db.execute(
                    "INSERT INTO transactions (user_id, symbol, price_each, number_of_shares, price_to_pay) VALUES (?, ?, ?, ?, ?)",
                    session["user_id"],
                    symbol["symbol"],
                    price_each,
                    number_of_shares,
                    price_to_pay,
                )

                check_for_shares = db.execute(
                    "SELECT share_symbol FROM shares WHERE share_symbol = ? AND user_id = ?",
                    symbol["symbol"],
                    session["user_id"],
                )

                if len(check_for_shares) == 0:
                    db.execute(
                        "INSERT INTO shares (share_symbol, number_of_shares, user_id) VALUES (?, ?, ?)",
                        symbol["symbol"],
                        number_of_shares,
                        session["user_id"],
                    )
                else:
                    db.execute(
                        "UPDATE shares SET number_of_shares = number_of_shares + ? WHERE user_id = ? AND share_symbol = ?",
                        number_of_shares,
                        session["user_id"],
                        symbol["symbol"],
                    )

                transaction_id = int(
                    db.execute(
                        "SELECT transaction_id FROM transactions ORDER BY transaction_id DESC LIMIT 1"
                    )[0]["transaction_id"]
                )
                db.execute(
                    "INSERT INTO date (transaction_id, date_time) VALUES (?, ?)",
                    transaction_id,
                    date_time,
                )

        elif len(share_name) == 0:
            return apology("Specify the symbol.")

        else:
            return apology("Symbol does not exist.")

    return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    if request.method == "GET":
        log = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[
            0
        ]["username"]
        history_rows = db.execute(
            "SELECT symbol, number_of_shares, price_each, date_time FROM transactions JOIN date ON date.transaction_id = transactions.transaction_id  WHERE user_id = ?",
            session["user_id"],
        )
        print(history_rows)

        if len(history_rows) != 0:
            return render_template("history.html", history_rows=history_rows, log=log)

        if len(history_rows) == 0:
            return render_template("history.html", history_rows=history_rows, log=log)

    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        if len(request.form.get("symbol")) == 0:
            return apology("Missing symbol")

        symbol = lookup(request.form.get("symbol"))

        if symbol != None:
            return render_template("quoted.html", symbol=symbol)

        elif symbol == None:
            return apology("Symbol does not exist.")

        else:
            return render_template("quote.html")

    else:
        log = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[
            0
        ]["username"]
        return render_template("quote.html", log=log)


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    session.clear()

    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 400)

        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords do not match!")

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        if len(rows) != 0:
            return apology("Username already exists!", 400)

        if len(rows) == 0:
            db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)",
                request.form.get("username"),
                generate_password_hash(request.form.get("password")),
            )

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")

        if symbol == None:
            return apology("Missing symbol.")

        shares = int(request.form.get("shares"))
        shares_owned = db.execute(
            "SELECT number_of_shares FROM shares WHERE share_symbol = ? AND user_id = ?",
            symbol,
            session["user_id"],
        )[0]["number_of_shares"]
        price = float(lookup(symbol)["price"])

        if shares_owned >= shares:
            cash_earned = shares * price
            db.execute(
                "UPDATE users SET cash = cash + ? WHERE id = ?",
                cash_earned,
                session["user_id"],
            )

            db.execute(
                "UPDATE shares SET number_of_shares = number_of_shares - ? WHERE share_symbol =? AND user_id = ?",
                shares,
                symbol,
                session["user_id"],
            )

            if shares_owned - shares == 0:
                db.execute("DELETE FROM shares WHERE number_of_shares = 0")

            db.execute(
                "INSERT INTO transactions (user_id, symbol, price_each, number_of_shares, price_to_pay) VALUES (?, ?, ?, ?, ?)",
                session["user_id"],
                symbol,
                price,
                -shares,
                price,
            )
            transaction_id = db.execute(
                "SELECT transaction_id FROM transactions ORDER BY transaction_id DESC LIMIT 1"
            )[0]["transaction_id"]

            date_time = datetime.now(timezone("Europe/Warsaw"))
            db.execute(
                "INSERT INTO date (transaction_id, date_time) VALUES (?, ?)",
                transaction_id,
                date_time,
            )

            return redirect("/")

        else:
            return apology("Not enough shares.")

    if request.method == "GET":
        log = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])[
            0
        ]["username"]
        symbol_list = db.execute(
            "SELECT share_symbol FROM shares WHERE user_id = ?", session["user_id"]
        )
        print(symbol_list)
        return render_template("sell.html", symbol_list=symbol_list, log=log)
