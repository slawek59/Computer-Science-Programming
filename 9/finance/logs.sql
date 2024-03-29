CREATE TABLE users (
id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
username TEXT NOT NULL,
hash TEXT NOT NULL,
cash NUMERIC NOT NULL DEFAULT 10000.00
);

CREATE TABLE transactions (
transaction_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
user_id INTEGER NOT NULL,
symbol TEXT NOT NULL,
price_each NUMERIC NOT NULL,
number_of_shares INTEGER NOT NULL,
price_to_pay NUMERIC NOT NULL
);

CREATE TABLE date (
date_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
transaction_id INTEGER NOT NULL,
date_time TIMESTAMP NOT NULL,
FOREIGN KEY(transaction_id) REFERENCES transactions(transaction_id)
);

CREATE TABLE shares (
share_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
share_symbol TEXT NOT NULL,
number_of_shares INTEGER NOT NULL,
user_id INTEGER NOT NULL,
FOREIGN KEY (user_id) REFERENCES users(id));