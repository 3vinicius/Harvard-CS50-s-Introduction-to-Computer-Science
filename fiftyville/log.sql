-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE day = 28 AND year = 2021 AND month = 7;
-- id = 295

SELECT * FROM interviews WHERE day = 28 AND year = 2021 AND month = 7;

SELECT * FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";


SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")

-- Return people bank transition
SELECT * FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));



-- number passageres
SELECT * FROM people WHERE passport_number
IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")))));





-- intersection how phone number

SELECT * FROM phone_calls WHERE day = 28 AND caller
IN (SELECT phone_number FROM people WHERE passport_number
IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"))))));



SELECT * FROM people WHERE passport_number
IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")))))



SELECT * FROM people WHERE license_plate IN (
SELECT license_plate FROM bakery_security_logs WHERE activity = 'exit' AND day = 28 AND license_plate IN (
SELECT license_plate FROM people WHERE passport_number
IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")))))
));



SELECT id FROM flights WHERE day = 29 AND year = 2021 AND id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"))));



SELECT * FROM people WHERE passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights
WHERE day = 29 AND year = 2021 AND month = 7 AND passport_number
IN (SELECT passport_number FROM people WHERE id
IN (SELECT person_id FROM bank_accounts WHERE account_number
IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND
year = 2021 AND month = 7 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")))));