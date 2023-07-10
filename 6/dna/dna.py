import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print('Invalid usage')

    # TODO: Read database file into a variable
    dtb_read = []
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        for name in reader:
            dtb_read.append(name)

    # TODO: Read DNA sequence file into a variable
    sequence = open(sys.argv[2], 'r')
    seq_read = sequence.read()

    # TODO: Find longest match of each STR in DNA sequence
    str = []
    str_list = []
    str = list(dtb_read[0].keys())

    for i in range(1, len(str)):
        str_list.append(longest_match(seq_read, str[i]))

    # TODO: Check database for matching profiles

    for name in range(len(dtb_read)):
        values = []
        values = list(dtb_read[name].values())
        values.pop(0)
        counter = 0

        for value in range(len(values)):
            values[value] = int(values[value])

        # if str_list in values:
        for str in range(len(str_list)):
            if str_list[str] == values[str]:
                counter += 1

        if counter == len(str_list):
            print(dtb_read[name]["name"])
            break
    else:
        print("No match")


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

# Sławek