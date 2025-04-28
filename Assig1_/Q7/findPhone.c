#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s Name\n", argv[0]);
        return 1;
    }

    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) {
        // Child 1 - GREP
        close(fd[0]); // Close read end
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(fd[1]); // Close original write end

        char *grep_args[] = {"grep", argv[1], "phonebook.txt", NULL};
        execvp("grep", grep_args);

        perror("execvp grep failed");
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) {
        // Child 2 - CUT
        close(fd[1]); // Close write end
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(fd[0]); // Close original read end

        char *cut_args[] = {"cut", "-d,", "-f2", NULL};
        execvp("cut", cut_args);

        perror("execvp cut failed");
        exit(1);
    }

    // Parent
    close(fd[0]);
    close(fd[1]);

    // Wait for both children
    wait(NULL);
    wait(NULL);

    return 0;
}
