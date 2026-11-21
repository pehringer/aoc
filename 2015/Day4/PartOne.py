import hashlib
import re

input = ""
with open("PuzzleInput.txt") as file:
	input = file.read()

input = input.strip()

answer = 0
while True:
	combo = input + str(answer)
	hash = hashlib.md5(combo.encode()).hexdigest()
	if re.match("^00000", hash):
		break
	answer += 1

print("Answer:", answer)
