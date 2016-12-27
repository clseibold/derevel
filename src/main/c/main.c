#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef _UNIX
#include <unistd.h>
#include <dirent.h>
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif

#ifdef _WIN32
#include <windows.h>
#include <Shlwapi.h>
#endif

int compile(const char files[1000]) {
	//return system("gcc *.c -o main");
	char path[1024];
	strcpy(path, "gcc ");
	strcat(path, files);
	strcat(path, " -o main");
#ifdef _UNIX
	return system(path);
#endif
#ifdef _WIN32
#endif	
}

int fileExists(const char *unixfilename, const char *windowsfilepath) {
#ifdef _UNIX
	return access(unixfilename, F_OK) == 0;
#endif
#ifdef _WIN32
	return PathFileExists(windowsfilepath);
#endif
}

int dirExists() {

}

int main() {
	int status = 0;
	if (fileExists("main.c", "main.c") == 0) {
		status = compile("*.c");
	} else {
		//printf("Looking in src/main/c/\n");
		// Check if src/main/c/ directory actually exists, error if it doesn't
		DIR *dir = opendir("./src/main/c/");
		if (dir) {
			closedir(dir);
			status = compile("src/main/c/*.c");
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
