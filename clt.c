#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void send_message(pid_t pid, const char *message) {
    pid_t client_pid = getpid();
    for (int i = sizeof(pid_t) - 1; i >= 0; i--) {
        char byte = (client_pid >> (i * 8)) & 0xFF;
        for (int j = 7; j >= 0; j--) {
            int bit = (byte >> j) & 1;
            if (bit == 0) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            usleep(150); // Wait time between signals
        }
    }

    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        for (int j = 7; j >= 0; j--) {
            int bit = (c >> j) & 1;
            if (bit == 0) {
                kill(pid, SIGUSR1);
            } else {
                kill(pid, SIGUSR2);
            }
            usleep(150); // Wait time between signals
        }
    }

    // Send null character to indicate the end of the message
    for (int j = 7; j >= 0; j--) {
        kill(pid, SIGUSR1);
        usleep(150); // Wait time between signals
    }
}

void ack_handler(int signal) {
    printf("Server acknowledged receipt of the message.\n");
    fflush(stdout);
    exit(0); // Exit after acknowledgment is received
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-pid> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t server_pid = atoi(argv[1]);
    const char *message = argv[2];

    struct sigaction sa;
    sa.sa_handler = ack_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);

    send_message(server_pid, message);

    while (1) {
        pause(); // Wait for acknowledgment from server
    }

    return 0;
}
