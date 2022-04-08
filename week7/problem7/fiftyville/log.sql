-- Keep a log of any SQL queries you execute as you solve the mystery.
-- To see all of the tables in the database.
.tables
-- To see how crime_scene_reports table is created and the contents.
.schema crime_scene_reports
SELECT * FROM crime_scene_reports LIMIT 5;
-- To check the crime scene reports on the crime day and location.
SELECT * FROM crime_scene_reports WHERE year=2021 AND month=7 AND day=28 AND street="Humphrey Street";

-- To see how interviews table is created and some contents.
.schema interviews
SELECT * FROM interviews LIMIT 5;
-- To read the interviews of witnesses.
SELECT * FROM interviews WHERE year=2021 and month=7 and day=28 AND transcript LIKE '%bakery%';

-- There seem to be more than 3 witnesses and by checking the duration of phone call, we can find that Emma is lying or her testimony is not useful.
.schema phone_calls
SELECT * FROM phone_calls WHERE year=2021 and month=7 and day=28 ORDER BY duration DESC LIMIT 5;

-- Check how atm_transactions table is created and some contents.
.schema atm_transactions
select * FROM atm_transactions LIMIT 5;
-- Check Eugene's testimony about atm withdrawal.
select * from atm_transactions where year=2021 and month=7 and day=28 and atm_location="Leggett Street" and transaction_type="withdraw";

-- Check how bakery_security_logs table is created and some contents.
.schema bakery_security_logs
SELECT * FROM bakery_security_logs LIMIT 5;
-- Since theft took place at 10:15am and a witness Ruth said the theif left within 10 minutes of the theft, check the security log of the bakery around that time.
SELECT * FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute BETWEEN 15 AND 25 ORDER BY minute;

-- Check how people table is created and some contents.
.schema people
SELECT * FROM people LIMIT 5;

-- Check Raymon's testimony about less than 1 minute phone call.
SELECT * FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration < 60;

-- To see how airports table is created and some contents.
.schema airports
SELECT * FROM airports LIMIT 5;
-- To see how flights table is created and some contents.
.schema flights
SELECT * FROM flights LIMIT 5;
-- To check the get-away flight according to the witness, Raymond.
SELECT * FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute;

-- To check how passengers table is created and some contents.
.schema passengers
SELECT * FROM passengers LIMIT 5;

-- Combine all testimonies of Ruth, Eugene, and Raymond => Bruce is the thief.
SELECT * FROM people
WHERE (license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute BETWEEN 15 AND 25 ORDER BY minute))
AND id IN (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where year=2021 and month=7 and day=28 and atm_location="Leggett Street" and transaction_type="withdraw"))
AND phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 and month=7 and day=28 and duration < 60)
AND passport_number IN(SELECT passport_number from passengers WHERE flight_id=(SELECT id FROM flights WHERE origin_airport_id=(SELECT id FROM airports WHERE city="Fiftyville") AND year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1));

-- Find who Bruce called on the theft day less than 1 min.
SELECT * FROM people where phone_number=(SELECT receiver FROM phone_calls WHERE year=2021 AND month=7 AND day=28 AND duration < 60 AND caller=(SELECT phone_number FROM people WHERE name="Bruce"));