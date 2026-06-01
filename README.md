*This project has been created as part of the 42 curriculum by jangonza*

# get_next_line

## Description
### What is get_next_line?

Get_next_line is my second project in the 42 curriculum and the first project of Milestone 1. Its purpose is to read and return the next line from a file descriptor each time the function is called. 

### How it works

The program is divided into several steps: \
        1.- First, it reads the file descriptor passed as an argument. \
        2.- Then, it stores the data read from the file descriptor in different nodes of a linked list, using the defined buffer size. \
        3.- Next, the program traverses the list until it finds a newline character ('\n').
        4.- When a newline is found, it returns all the stored data up to and including that newline character. If you print the returned string, you will obtain the next line of the file. \
        5.- Finally, it updates the linked list, keeping only the remaining data that has not yet been returned.

## Instructions

First, clone the project repository using the following commands in your terminal:

```bash
git clone git@github.com:Peligorri/42GetNextLine.git get_next
cd libft
```

Once the repository has been cloned, you can compile the program with:

```bash
cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
```

Finally, you can run the program with:

```bash
./a.out
```

## Resources

- https://www.youtube.com/watch?v=8E9siq7apUU \
I used this video to understand the project and how it works.
- https://www.youtube.com/watch?v=MtqFZRXaeM0 \
- https://pasky.wordpress.com/2009/08/04/funciones-openclose-y-readwrite-en-c/ \
I used these resources to better understand the read() and open() functions and how to implement them correctly in the project.
- https://www.youtube.com/watch?v=3-u5SRuStuc \
- https://www.reddit.com/r/cprogramming/comments/1g4fy4d/understanding_linked_lists_and_how_to_create_one/?tl=es-es \
- https://www.monografias.com/trabajos90/listas-c/listas-c \
These resources helped me gain a better understanding of linked lists and how to use them in this project.
- https://chatgpt.com/ \
I used ChatGPT as a *Moulinette* to check whether my code was correct or not. It was also useful for better understanding what the functions do. Finally, I used it to improve my English texts so they look more polished and professional. I never used it to figure out how to write the code or to get direct answers for any function. 
