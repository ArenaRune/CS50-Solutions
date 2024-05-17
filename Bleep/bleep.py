from cs50 import get_string
from sys import argv

words = set()


def main():
    if len(argv) != 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    load(argv[1])
    s = get_string("What message would you like to censor: ")
    n = s.split()
    new = []
    for w in n:
        if check(w):
           new.append(len(w)*"*")
        else:
            new.append(w)
    s = " ".join(new)
    print(s)


def check(word):
    return word.lower() in words


def load(dictionary):
    file = open(dictionary,"r")
    for line in file:
        words.add(line.rstrip("\n"))
    file.close()


if __name__ == "__main__":
    main()
