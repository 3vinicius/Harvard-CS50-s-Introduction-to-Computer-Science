import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 0
    fileDataBase = sys.argv[1]
    fileSequencesDna =sys.argv[2]

    dataBase = []


    # TODO: Read database file into a variable
    with open(fileDataBase) as file:
        dates = csv.DictReader(file)
        for line in dates:
            dataBase.append(line)


    # TODO: Read DNA sequence file into a variable
    with open(fileSequencesDna) as file:
        sequenceDna = csv.reader(file)
        for line in sequenceDna:
            sequence = line


    # TODO: Find longest match of each STR in DNA sequence
    valuesLongest = {}
    keys = list(dataBase[0].keys())
    keys.remove("name")
    for key in keys:
        total = longest_match(sequence[0], key)
        valuesLongest[key] = total

    # TODO: Check database for matching profiles

    for dna in dataBase:
        checkTrue = 0
        for key in keys:
            if int(dna[key]) == valuesLongest[key]:
                checkTrue += 1
        if (checkTrue == len(keys)):
            print(dna['name'])
            return 1
    print("No match")

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


main()
