#include "../incs/pipex_bonus.h"

void pipex_clear(t_pipex *pipex)
{
    close(pipex->infile);
    close(pipex->outfile);
    if(pipex->is_heredoc)
        unlink(".temp_heredoc");
    while(pipex->paths)
    {
        free(*(pipex->paths));
        pipex->paths++;
    }
    free(pipex->paths);
    free(pipex->pipe_ends);
}

void pipex_clear_by_get_paths(t_pipex *pipex)
{
    close(pipex->infile);
    close(pipex->outfile);
    if(pipex->is_heredoc)
        unlink(".temp_heredoc");
    free(pipex->pipe_ends);
    error_message(ERR_PATH);
    exit(1);
}