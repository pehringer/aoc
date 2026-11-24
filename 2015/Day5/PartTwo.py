import re

input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input = input.split()

pairs = re.compile(r"(.)(.).*\1\2")
skips = re.compile(r"(.).\1")
nice = 0
for string in input:
	if not pairs.search(string):
		continue
	if not skips.search(string):
		continue
	nice += 1

print("Answer:", nice)
