#include <stdio.h>

#define BUFFER_SIZE 8192

int main(void) {
	FILE *file = fopen("input.txt", "r");
	if(file == NULL) {
		perror("error opening input.txt");
		return 0;
	}
	char input[BUFFER_SIZE];
	size_t size = fread(input, sizeof input[0], BUFFER_SIZE, file);
	fclose(file);
	if(size == BUFFER_SIZE) {
		printf("error reading input.txt: BUFFER_SIZE too small\n");
		return 0;
	}

	int floor = 0;
	int position = 0;
	while(position < size) {
		switch(input[position]) {
			case '(':
				floor++;
				break;
			case ')':
				floor--;
				break;
		}
		position++;
		if(floor < 0) {
			break;
		}
	}

	printf("Answer: %d\n", position);
	return 0;
}
