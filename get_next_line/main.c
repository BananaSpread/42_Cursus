#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	int fd = open(argv[0], O_RDONLY);
	char *line = get_next_line(fd);

	while (line) {
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}