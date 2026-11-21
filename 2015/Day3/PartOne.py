input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

x, y = 0, 0
houses = {(0, 0)}
for character in input:
	match character:
		case '^':
			y += 1
		case 'v':
			y -= 1
		case '<':
			x -= 1
		case '>':
			x += 1
	houses.add((x, y))

print("Answer:", len(houses))
