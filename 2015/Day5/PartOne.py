import re

input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input = input.split()

vowels = re.compile(r"([aeiou].*){3}")
double = re.compile(r"(.)\1")
cannot = re.compile(r"(ab|cd|pq|xy)")
nice = 0
for string in input:
	if not vowels.search(string):
		continue
	if not double.search(string):
		continue
	if cannot.search(string):
		continue
	nice += 1

print("Answer:", nice)
