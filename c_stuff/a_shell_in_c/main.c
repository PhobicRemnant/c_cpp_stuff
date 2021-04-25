#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 1024

char* read_line(){

    int buff_size = BUFF_SIZE;
    int position = 0;
    char* buffer = malloc(sizeof(char)* buff_size);
    int c;

    if(!buffer){
        fprintf(stderr, "shell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while(1){
        // Read line
        c = getchar();

        // If we hit the EOF, replace with a null character and return
        if( c == EOF || c == '\n'){
            buffer[position] = '\0';
            return buffer;
        }
        else{
            buffer[position] = c;
        }
        position++;

        // If buffer size is exceded, reallocate
        if(position >= buff_size){
            buff_size += BUFF_SIZE;
            buffer = realloc(buffer,buff_size);

            if(!buffer){
                fprintf(stderr, "shell:allocation error\n");
                exit(EXIT_FAILURE);
            }

        }

    }


}

void shell_loop(){

    char *line;
    char **args;
    int status;

    do{
        print(">");
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free(args);

    }while(status);


}

int main(){

    // Show shell start
    printf("Welcome to new shell:\n");

    // Run shell
    shell_loop();

    return EXIT_SUCCESS;
}