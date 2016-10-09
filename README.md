# Derevel
[![Documentation Status](https://readthedocs.org/projects/derevel/badge/?version=latest)](http://derevel.readthedocs.io/en/latest/?badge=latest)
[![license](https://img.shields.io/github/license/mashape/apistatus.svg?maxAge=2592000)]()
[![Waffle.io](https://img.shields.io/waffle/label/evancohen/smart-mirror/in%20progress.svg?maxAge=2592000)](https://waffle.io/krixano/derevel)

A minimalistic and easy build system for small C projects. This is a work in progress and is nowhere near ready for use in actual software! Contributions are welcome.

The goal is to have an easy, simple, and fast build system that can be used to build small and middle sized C projects with minimal configuration!

NOTE: Only tested on linux. You must have gcc installed in order to use this.

See documentation at: [http://derevel.readthedocs.io/en/latest/](http://derevel.readthedocs.io/en/latest/)

## Compiling
To compile the latest version, simply run `./main`. You are using a previous version of derevel to build the next one!! This will update the main executable. Then, you can just copy the file into your projects to use it.

## Usage
Right now, the build system can only compile a program that doesn't have any dependencies (besides any that are standard on OS's). You can either put all of your code into the same directory as the executable, or you can be more organized and put the source code into the `src/main/c/` directory.

## Future Features
* Ability to have a config file to specify name and version of project and the libraries to be linked to the main program
* Multiplatform support
* Support clang and msvc
* Subcommands for debug and release versions, along with `dist` subcommand to create 32-bit and 64-bit release executables for distribution (you can disallow 64-bit in config file). Creates for multiple platforms if supported compiler installed.
* Allow `dist` command to copy over licenses for project and libraries used (and attribution file if provided) and create zip files for easy distribution.
