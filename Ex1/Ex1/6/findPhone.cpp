#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>\n";
        return 1;
    }

    int pipe1[2], pipe2[2];
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        std::cerr << "Pipe failed\n";
        return 1;
    }

    pid_t pid1 = fork();
    if (pid1 == -1) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    if (pid1 == 0) {
        // Child process 1 - Executes "grep"
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        execlp("grep", "grep", argv[1], "phonebook.txt", NULL);
        std::cerr << "Exec failed\n";
        exit(1);
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    if (pid2 == 0) {
        // Child process 2 - Executes "sed"
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        execlp("sed", "sed", "s/.*,//", NULL); // Changes everything before the comma to empty
        std::cerr << "Exec failed\n";
        exit(1);
    }
    
    

    pid_t pid3 = fork();
    if (pid3 == -1) {
        std::cerr << "Fork failed\n";
        return 1;
    }

    if (pid3 == 0) {
        // Child process 3 - Executes "awk"
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);

        execlp("awk", "awk", "{print $1}", NULL); // Now $1 should be the phone number
        std::cerr << "Exec failed\n";
        exit(1);
    }

    // Parent process - Close all pipes and wait for children
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}