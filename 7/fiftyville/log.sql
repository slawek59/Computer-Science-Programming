
-- Searching for proper interviews

SELECT * FROM crime_scene_reports WHERE id = 295;

SELECT * FROM interviews WHERE day = 28 AND month = 7;

SELECT * FROM interviews WHERE id BETWEEN 161 AND 163;


-- Checking for destination and flight id

SELECT city,flights.id FROM airports

    JOIN flights ON flights.destination_airport_id = airports.id
    WHERE destination_airport_id =
        (SELECT destination_airport_id FROM flights WHERE origin_airport_id =
            (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 ORDER BY hour) AND flights.id =
                (SELECT id FROM flights WHERE origin_airport_id =
                    (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 ORDER BY hour)LIMIT 1;


-- Searching for the Thief

SELECT name FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")) AND id IN
            (SELECT id FROM people WHERE phone_number IN
                (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND id IN (SELECT id FROM people WHERE license_plate IN
                    (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 14 AND 25 AND activity = "exit") AND passport_number IN
                        (SELECT passport_number FROM passengers WHERE flight_id IN
                            (SELECT flights.id FROM airports JOIN flights ON flights.destination_airport_id = airports.id WHERE destination_airport_id =
                                (SELECT destination_airport_id FROM flights WHERE  origin_airport_id =
                                    (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 ORDER BY hour) AND flights.id =
                                        (SELECT id FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND day = 29 ORDER BY hour)LIMIT 1))));

-- Searching for the Accomplice

SELECT name FROM people WHERE phone_number IN
    (SELECT receiver FROM phone_calls WHERE caller =
        (SELECT phone_number FROM people WHERE name = "Bruce") AND month = 7 AND day = 28 AND duration < 60);


-- Sławek