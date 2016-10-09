# Getting Started
To get started making a project to use with derevel, you must put your source files in the right place! Currently, Derevel allows you to organize your code in 3 different ways! The different options for organizing your code are outlined below:

* Option 1
  * Simply put all of your source files in the root directory of your project.
  * Use this option if you don't need to compile seperate libraries.
* Option 2
  * Put all of your source files in the `src/main/c/` directory, and you header files in the `src/main/headers/` directory. This is very similar to the gradle setup.
  * This option is best if you have libraries that are compiled seperately and must be linked with the main project.
* Option 3
  * Put all of your source and headers filed in the `src/` directory.
  * Use this option if you don't need to compile seperate libraries.
