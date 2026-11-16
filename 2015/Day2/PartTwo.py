import re

input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input = re.sub("\n$", "", input)
input = re.split("\n|x", input)
input = [int(digits) for digits in input]

ribbon = 0
for i in range(0, len(input), 3):
	l, w, h = sorted(input[i:i+3])
	ribbon += l + l + w + w + l * w * h

print("Answer:", ribbon)
