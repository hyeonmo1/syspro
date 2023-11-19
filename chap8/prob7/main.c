#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_environment_variable(char *env_name) {
    char *env_value = getenv(env_name);
    if (env_value != NULL) {
        printf("%s=%s\n", env_name, env_value);
    } else {
        printf("Environment variable %s not found.\n", env_name);
    }
}

void print_user_info() {
    printf("My Realistic user ID: %d\n", getuid());
    printf("My Valid user ID: %d\n", geteuid());
    printf("My Reallistic group ID: %d\n", getgid());
    printf("My Valid group ID: %d\n", getegid());
}

void print_process_info() {
    printf("my Process number: %d\n", getpid());
    printf("my Parent Process number: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-e[env_name]] [-u] [-g] [-i] [-p]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'e') {
            char *env_name = &argv[i][2];
            print_environment_variable(env_name);
        } else if (argv[i][0] == '-' && argv[i][1] == 'u') {
            print_user_info();
        } else if (argv[i][0] == '-' && argv[i][1] == 'i') {
            print_process_info();
        } else {
            printf("Invalid option: %s\n", argv[i]);
            return 1;
        }
    }

    return 0;
}
