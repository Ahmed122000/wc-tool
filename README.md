
# WC Tool

This project is a custom implementation of the Unix command-line tool `wc`. The Unix command line tools are known for their simplicity and adherence to the Unix Philosophy:
- **Modularity**: Each tool does one thing well and provides a simple CLI that handles text input from files or streams.
- **Composability**: Tools can be easily connected to others, creating powerful combinations.

## Features

The tool supports the following functionalities:

- **File Input**: Specify a file to read or pipe input directly into the tool.
- **Counting Options**:
  - `-c`: Count the number of bytes in the input text file.
  - `-l`: Count the number of lines in the input text file.
  - `-w`: Count the number of words in the input text file.
  - `-m`: Count the number of characters in the input text file (based on the locale).
  - **Default**: If no argument is provided, the tool counts the number of bytes, lines, and words (`-c`, `-l`, `-w`).

## Usage

### Command Structure

The tool can be invoked in the following ways:

- **File Input**:
  ```
  ccwc [options] [path_for_input_file]
  ```

- **Standard Input**:
  ```
  cat input.txt | ccwc [options]
  ```

### Arguments

- `-c`: Count the number of bytes in the input text file.
- `-l`: Count the number of lines in the input text file.
- `-w`: Count the number of words in the input text file.
- `-m`: Count the number of characters in the input text file (based on the locale).
- **Default**: Counts bytes, lines, and words (`-c`, `-l`, `-w`).

## Acknowledgments

This application was inspired by a challenge provided by [Coding Challenges](https://codingchallenges.fyi/).
