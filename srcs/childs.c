#include "../incs/pipex.h"


char *find_command(char **paths, char *cmd)
{
    char *tmp;
    char *command;
    while(*paths)
    {
        tmp = ft_strjoin(*paths, "/");
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if(access(command, 0) == 0)
            return command;
        free(command);
        paths++;
    }
    return NULL;
}

void child_exe_cmd1()
{
    printf("");
}

void child_exe_cmd2()
{
    printf("");

}