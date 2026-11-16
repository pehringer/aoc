import re

input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input = re.sub("\n$", "", input)
input = re.split("\n|x", input)
input = [int(digits) for digits in input]

paper = 0
for i in range(0, len(input), 3):
	l, w, h = input[i:i+3]
	lw, wh, hl = l*w, w*h, h*l
	smallest = min(lw, wh, hl)
	paper += 2 * lw + 2 * wh + 2 * hl + smallest

print("Answer:", paper)
