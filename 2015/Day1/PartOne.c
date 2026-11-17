#include <stdio.h>

#define BUFFER_SIZE 8192

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

	int floor = 0;
	for(int i = 0; i < size; i++) {
		switch(input[i]) {
			case '(':
				floor++;
				break;
			case ')':
				floor--;
				break;
		}
	}

	printf("Answer: %d\n", floor);
	return 0;
}
