#include <stdio.h>

#define BUFFER_SIZE 32768

bool hasRepeat(char *string) {
	if (*string++ == '\0' || *string++ == '\0') {
		return 0;
	}
	while(*string != '\0') {
		if(*(string-2) == *string++) {
			return 1;
		}
	}
	return 0;
}

bool hasDouble(char *string) {
	char *target = string;
	if (*string++ == '\0' || *string++ == '\0') {
		return 0;
	}
	while(*string != '\0') {
		if(string[0] == target[0] && string[1] == target[1]) {
			return 1;
		}
		string++;
	}
	return 0;
}

bool hasPair(char *string) {
	while(*string != '\0') {
		if(hasDouble(string++)) {
			return 1;
		}
	}
	return 0;
}

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

	int index = 0, chars = 0, nice = 0;
	char string[BUFFER_SIZE];
	while(sscanf(input+index, "%s\n%n", string, &chars) == 1) {
		index += chars;
		if(!hasPair(string)) {
			continue;
		}
		if(!hasRepeat(string)) {
			continue;
		}
		nice++;
	}

	printf("Answer: %d\n", nice);
	return 0;
}
