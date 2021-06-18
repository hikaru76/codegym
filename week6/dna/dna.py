import sys
import cs50
import csv


def count(data, dna):
    dnalen = len(dna)
    datalen = len(data)
    maxcnt = 0
    for i in range(datalen):
        cnt = 0
        if data[i: i + dnalen] == dna:
            cnt += 1
            while data[i: i + dnalen] == data[i + dnalen: i + (2 * dnalen)]:
                cnt += 1
                i += dnalen
        if cnt > maxcnt:
            maxcnt = cnt
    return maxcnt


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    csv_file = open(sys.argv[1], "r", encoding="utf_8", errors="", newline="")
    fcsv = csv.reader(csv_file, delimiter=",", doublequote=True, lineterminator="\r\n", quotechar='"', skipinitialspace=True)
    ftxt = open(sys.argv[2], 'r')
    data = ftxt.read()
    header = next(fcsv)
    element_size = len(header) - 1
    # print(element_size)
    # print(header)
    li = []
    for i in range(1, element_size + 1):
        # li.append(data.count(header[i]))
        li.append(count(data, header[i]))
    # print(li)
    for row in fcsv:
        for i in range(1, element_size + 1):
            # print(i, row[i], li[i - 1])
            if int(row[i]) != int(li[i - 1]):
                break
            elif i == element_size:
                print(row[0])
                exit(0)
    print("No match")
    ftxt.close()


if __name__ == "__main__":
    main()