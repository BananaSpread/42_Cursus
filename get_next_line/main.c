#include "get_next_line.h"
#include <stdio.h>

int main() {
	char *file_name = "test.txt";
	int fd = open(file_name, O_RDONLY);
	char *line = get_next_line(fd);

	if (!line) {
		printf("Error reading line\n");
		return (1);
	}
	printf("Printing lines\n\n");
	while (line) {
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}