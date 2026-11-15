input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

floor = 0
for character in input:
	match character:
		case '(':
			floor += 1
		case ')':
			floor -= 1

print("Answer:", floor)
