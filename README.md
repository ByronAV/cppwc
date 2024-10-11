# CPP Word Count Tool

This is an implementation of the famous `wc` tool provided in *nix environments. It maintains the same
behaviour as the original tool, meaning it can parse the following commands:
- h, help : Print the help message
- b, size : Print the total size of the file
- l, line : Print the total lines in the file
- w, word : Print the total words in the file
- m, char : Print the total characters in a file.

If the user doesn't provide a known flag and provides only a file, the output of the combined
`-lwc` will be printed.

# Compiling

This tool is compiled with CMake in the following manner.
```
mkdir build
cd build
cmake ..
```
This will create a directory called `build` where the user can execute the
script.

# Executing

The user can execute the tool in the following way from the command line:
```
cppwc <optional_flags> <filename>
```

# Acknowledgments

This is part of John Cricket's Coding Challenges which can be found [here](https://codingchallenges.fyi/challenges/challenge-wc)
