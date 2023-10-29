# ifndef PIPEX_H
 # define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define STDERR 2

//error
# define ERR_INPUT "Error: Invalid arguments\n"
# define ERR_OPEN "Error: failed open()\n"
# define ERR_PIPE "Error: failed pipe()\n"

typedef struct s_pipex{
    int infile;
    int outfile;

    char *path_addr;
    char **paths;

    pid_t pid1;
    pid_t pid2;

    int pipefd[2];
}   t_pipex;


//path.c
char *find_path_addr(char **envp);

//init.c
void get_infile(t_pipex *pipex, char *infile);
void get_outfile(t_pipex *pipex, char *outfile);
void create_pipe(t_pipex *pipex);

//childs.c
char *find_command(char **paths, char *cmd);
void child_exe_cmd1();
void child_exe_cmd2();

//main.c

//error.c
void    error_message(char *error_message);

 #endif