-- Keep a log of any SQL queries you execute as you solve the mystery.

-- The crime scene description reports that the crime took place at 10:15 am at the Humphrey Street bakery and interviews were conducted with three witnesses each mentioning the bakery.
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- Three transcripts of interviews that mention bakery.
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- Collecting bank transaction information based on second interview.
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

-- Collecting flight information based on the third interview.
SELECT name FROM people JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
    SELECT id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
        SELECT id FROM airports WHERE city = "Fiftyville"
    )
    ORDER BY hour, minute
    LIMIT 1
);

-- Collecting telephone information based on the third interview.
SELECT name FROM people JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Finding the destination city of the flight from Fiftyville on the specified date.
SELECT city FROM airports WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29 AND origin_airport_id = (
        SELECT id FROM airports WHERE city = "Fiftyville"
    )
    ORDER BY hour, minute
    LIMIT 1
);

-- Finding the suspect's phone.
SELECT phone_number FROM people WHERE name = "Bruce";

-- Searching the name of the accomplice who received the suspect's call
SELECT name FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533"
);