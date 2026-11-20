input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input.strip()

turn = False
robot_x, robot_y = 0, 0
santa_x, santa_y = 0, 0
houses = {(0, 0)}
for character in input:
	x, y = 0, 0
	match character:
		case '^':
			y = +1
		case 'v':
			y = -1
		case '<':
			x = -1
		case '>':
			x = +1
	if turn:
		robot_x += x
		robot_y += y
		houses.add((robot_x, robot_y))
	else:
		santa_x += x
		santa_y += y
		houses.add((santa_x, santa_y))
	turn = not turn

print("Answer:", len(houses))
