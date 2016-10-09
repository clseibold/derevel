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
		//printf("Looking in src/main/c/\n");
		// Check if src/main/c/ directory actually exists, error if it doesn't
		DIR *dir = opendir("./src/main/c/");
		if (dir) {
			closedir(dir);
			status = system("gcc src/main/c/*.c -o main");
		} else if (ENOENT == errno) {
			closedir(dir);
			printf("[Error] src/main/c/ directory does not exist!\n");
			status = 1;
		} else {
			closedir(dir);
			printf("[Error]\n");
			status = 1;
		}
		// Add ability to create config file to specify libraries
		// that either need to be compiled and linked to main project, or just
		// linked!
	}
	if (status != 0) {
		printf("\n[Info] Build Failed! Returned error code '%d'.\n", status);
	} else {
		printf("\n[Info] Build Succeded! Returned error code '%d'.\n", status);
	}

	return(status);
}
