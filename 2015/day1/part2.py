input = ""
with open("input.txt") as file:
	input = file.read()

floor = 0
position = 0
for character in input:
	match character:
		case '(':
			floor += 1
		case ')':
			floor -= 1
	position += 1
	if floor < 0:
		break

print("Answer:", position)
