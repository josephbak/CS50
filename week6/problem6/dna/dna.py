import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as datafile:
        reader = csv.DictReader(datafile)
        for row in reader:
            database.append(row)

    list_of_STR = list(database[0].keys())[1:]
    # print(database)
    # print(list_of_STR)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as dnafile:
        dna_sequence = dnafile.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest_STR_dict = {}
    for str in list_of_STR:
        longest_STR_dict[str] = longest_match(dna_sequence, str)
    # print(longest_STR_dict)
    # print(list(longest_STR_dict.keys()))

    # TODO: Check database for matching profiles
    for data in database:
        if matching_STR(data, longest_STR_dict):
            print(data['name'])
            return
    print('No match')
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def matching_STR(data, longest_STR):
    matched = 1
    for str in list(longest_STR.keys()):
        if int(data[str]) == int(longest_STR[str]):
            matched *= 1
        else:
            # print(str)
            matched *= 0
    # print(f"{data['name']}: {matched}")
    if matched == 1:
        # print("hi")
        return True
    else:
        return False


main()
