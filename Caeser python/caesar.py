from sys import argv
from cs50 import get_string

def main():
    if len(argv) != 2:
        print("Usage: python caesar.py key")
        exit(1)
    key = int(argv[1])
    old = get_string("plaintext: ")
    new = []
    for symbol in old:
        if symbol.isalpha():
            new.append(caesar(symbol,key))
        else:
            new.append(symbol)
    print("ciphertext:","".join(new))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)

if __name__ == "__main__":
    main()