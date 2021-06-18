from cs50 import get_string
from math import floor

alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
space = " "
end = ".!?"
text = get_string("Text: ")
characters = 0
words = 1
sentences = 0
for s in alphabet:
    characters += text.count(s)
for s in space:
    words += text.count(s)
for s in end:
    sentences += text.count(s)
L = characters / words * 100
S = sentences / words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(index))
