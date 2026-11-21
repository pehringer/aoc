#include <stdio.h>

#define BUFFER_SIZE 16381 //Prime close to 16384.

int main(void) {
	FILE *file = fopen("PuzzleInput.txt", "r");
	if(file == NULL) {
		perror("error opening PuzzleInput.txt");
		return 0;
	}
	char input[BUFFER_SIZE];
	size_t size = fread(input, sizeof input[0], BUFFER_SIZE, file);
	fclose(file);
	if(size == BUFFER_SIZE) {
		printf("error reading PuzzleInput.txt: BUFFER_SIZE too small\n");
		return 0;
	}

	int keys[BUFFER_SIZE] = {0};
	char used[BUFFER_SIZE] = {1};
	bool turn = 0;
	int count = 1, santa_x = 0, robot_x = 0, santa_y = 0, robot_y = 0;
	for(int i = 0; i < size; i++) {
		int x = 0, y = 0;
		switch(input[i]) {
		case '^':
			y++;
			break;
		case 'v':
			y--;
			break;
		case '<':
			x--;
			break;
		case '>':
			x++;
			break;
		}
		if(turn) {
			robot_x += x;
			robot_y += y;
			x = robot_x;
			y = robot_y;
		} else {
			santa_x += x;
			santa_y += y;
			x = santa_x;
			y = santa_y;
		}
		turn = !turn;
		int key = (x << 16) | (y & 0xFFFF);
		int hash = (unsigned) key % BUFFER_SIZE;
		while(used[hash] && keys[hash] != key) {
			hash = (hash + 1) % BUFFER_SIZE;
		}
		if(!used[hash]) {
			keys[hash] = key;
			used[hash] = 1;
			count++;
		}
	}

	printf("Answer: %d\n", count);
	return 0;
}
