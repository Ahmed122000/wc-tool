<H1>WC Tool</H1>
This challenge is to build my own version of the Unix command line tool wc!

The Unix command line tools are a great metaphor for good software engineering and they follow the Unix Philosophies of:
- Writing simple parts connected by clean interfaces - each tool does just one thing and provides a simple CLI that handles text input from either files or file streams.
- Design programs to be connected to other programs - each tool can be easily connected to other tools to create incredibly powerful compositions.

the tool has the following structure
> `ccwc [argument] [path_for_input_file]`

The tool have different argument each argument has its own task:
- `-c`: count number of the bytes in the input text file
- `-l`: count number of lines in the input text file
- `-w`: count number of words in the input text file 
- `-m`: count number of characters in the input text file __based on the locale__
- default (no argument): it apply the first 3 argument together (`-c`, `-l`, `-w`)

the tool also supports the **standard input**  
> `cat input.txt | ccwc [argument]` 

<h6>this task is the first challege provided by <a href=https://codingchallenges.fyi/>Coding Challenges</a></h6>
