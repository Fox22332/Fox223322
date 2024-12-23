import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database.csv> <sequence.txt>")
        return

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    database = []
    with open(database_file, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            for key in row.keys():
                if key != 'name':
                    row[key] = int(row[key])
            database.append(row)

    with open(sequence_file, 'r') as file:
        dna_sequence = file.read().strip()

    str_list = list(database[0].keys())[1:]

    str_counts = {}
    for str_seq in str_list:
        str_counts[str_seq] = longest_match(dna_sequence, str_seq)

    for person in database:
        match = all(person[str_seq] == str_counts[str_seq] for str_seq in str_list)
        if match:
            print(person['name'])
            return

    output = "Нет совпадений"
    print(output.strip() + "\n", end="")

    return


def longest_match(sequence, subsequence):
    """Возвращает длину самой длинной последовательности подпоследовательности внутри последовательности."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
