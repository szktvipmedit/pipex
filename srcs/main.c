//error_message
//  存在しないcmd -bash: cmd: command not found
//  存在しないファイル -bash: file_name: No such file or directory
//  権限のないファイル -bash: file1: Permission denied

#include "../incs/pipex.h"

void init_pipe(t_pipex *pipex, char **argv, char **envp)
{
    get_infile(pipex, argv[1]);
    get_outfile(pipex, argv[4]);
    create_pipe(pipex);
    pipex->path_addr = find_path_addr(envp);
    pipex->paths = ft_split(pipex->path_addr, ':');
}

int main(int argc, char **argv, char **envp)
{
    if(argc == 5)
    {
        t_pipex pipex;
        init_pipe(&pipex, argv, envp);
        pipex.pid1 = fork();
        printf("pid1 %i\n", pipex.pid1);
        if(pipex.pid1 == 0)
        //    child_exe_cmd1(pipex.paths, argv[2]);
        pipex.pid2 = fork();
        printf("pid2 %i\n", pipex.pid2);
        if(pipex.pid2 == 0)   
            // child_exe_cmd2(pipex.paths, argv[3]); 
        // close_pipe();
        waitpid(pipex.pid1, NULL, 0);
        waitpid(pipex.pid2, NULL, 0);

    }
    else
        error_message(ERR_INPUT);
}