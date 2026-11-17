#include <stdio.h>

#define BUFFER_SIZE 8192

int min(int a, int b, int c) {
	if(a <= b && a <= c) {
		return a;
	}
	if(b <= a && b <= c) {
		return b;
	}
	return c;
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

	int index = 0, l, w, h, chars, paper = 0;
	while(sscanf(input+index, "%dx%dx%d\n%n", &l, &w, &h, &chars) == 3) {
		index += chars;
		int lw = l * w, wh = w * h, hl = h * l;
		int smallest = min(lw, wh, hl);
		paper += 2 * lw + 2 * wh + 2 * hl + smallest;
	}

	printf("Answer: %d\n", paper);
	return 0;
}
