#include <stdio.h>

#define BUFFER_SIZE 32768

bool hasVowels(char *string) {
	int vowels = 0;
	while(*string != '\0') {
		switch(*string++) {
			case 'a':
		 	case 'e':
		 	case 'i':
		 	case 'o':
		 	case 'u':
		 		if(++vowels == 3) {
					return 1;
				}
				break;
		}
	}
	return 0;
}

bool hasDouble(char *string) {
	while(*string != '\0') {
		if(*string++ == *string) {
			return 1;
		}
	}
	return 0;
}

bool hasCannot(char *string) {
	while(*string != '\0') {
		switch(*string++) {
			case 'a':
				if(*string == 'b') {
					return 1;
				}
				break;
			case 'c':
				if(*string == 'd') {
					return 1;
				}
				break;
			case 'p':
				if(*string == 'q') {
					return 1;
				}
				break;
			case 'x':
				if(*string == 'y') {
					return 1;
				}
				break;
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
		if(!hasVowels(string)) {
			continue;
		}
		if(!hasDouble(string)) {
			continue;
		}
		if(hasCannot(string)) {
			continue;
		}
		nice++;
	}

	printf("Answer: %d\n", nice);
	return 0;
}
