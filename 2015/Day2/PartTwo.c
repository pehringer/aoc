#include <stdio.h>

#define BUFFER_SIZE 8192

int min(int *a, int *b) {
	if(*b < *a) {
		int t = *a;
		*a = *b;
		*b = t;
	}
}

int sort(int *a, int *b, int *c) {
	min(a, b);
	min(b, c);
	min(a, b);
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
	input[size] = '\0';

	int index = 0, l, w, h, chars, ribbon = 0;
	while(sscanf(input+index, "%dx%dx%d\n%n", &l, &w, &h, &chars) == 3) {
		index += chars;
		sort(&l, &w, &h);
		ribbon += l + l + w + w + l * w * h;
	}

	printf("Answer: %d\n", ribbon);
	return 0;
}
