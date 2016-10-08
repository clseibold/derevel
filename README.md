# Derevel
A minimalistic and easy build system for small C projects. This is a work in progress and is nowhere near ready for use in actual software!

NOTE: Only tested on linux. You must have gcc installed in order to use this.

## Compiling
To compile the latest version, simply run `./main`. You are using a previous version of derevel to build the next one!! This will update the main executable. Then, you can just copy the file into your projects to use it.

## Usage
Right now, the build system can only compile a program that doesn't have any dependencies (besides any that are standard on OS's). You can either put all of your code into the same directory as the executable, or you can be more organized and put the source code into the `src/main/c/` directory.

## Future Features
* Ability to have a config file to specify name and version of project and the libraries to be linked to the main program
