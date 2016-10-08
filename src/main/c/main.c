#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

int main() {
	int status = 0;
	if (access("main.c", F_OK) == 0) {
		status = system("gcc *.c -o main");
	} else {
		// look in src/main directory
		printf("Looking in src/main/c/\n");
		// Check if src/main/c/ directory actually exists, error if it doesn't
		DIR *dir = opendir("./src/main/c/");
		if (dir) {
			closedir(dir);
			status = system("gcc src/main/c/*.c -o main");
		} else if (ENOENT == errno) {
			printf("Error: src/main/c/ directory does not exist!\n");
			closedir(dir);
		} else {
			printf("Error\n");
			closedir(dir);
		}
		// Add ability to create config file to specify libraries
		// that either need to be compiled and linked to main project, or just
		// linked!
	}
	if (status != 0) {
		printf("\nError: Build Failed!\n");
	}

	return(0);
}
