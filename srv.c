#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#define INITIAL_MSG_SIZE 1024

typedef struct {
    int bit_count;
    int current_char;
    char *message;
    int message_index;
    pid_t client_pid;
    int pid_bytes_received;
    int receiving_pid;
    size_t message_size;
} ServerState;
ServerState state = {0, 0, NULL, 0, 0, 0, 1, INITIAL_MSG_SIZE};

void handle_signal(int signal) {
    if (signal == SIGUSR1) {
        state.current_char = (state.current_char << 1) | 0;
    } else if (signal == SIGUSR2) {
        state.current_char = (state.current_char << 1) | 1;
    }

    state.bit_count++;

    if (state.receiving_pid) {
        if (state.bit_count == sizeof(pid_t) * 8) {
            state.client_pid = state.current_char;
            state.receiving_pid = 0;
            state.bit_count = 0;
        }
    } else {
        if (state.message_index >= state.message_size - 1) {
            state.message_size *= 2;
            state.message = malloc(state.message);
            if (state.message == NULL)
                exit(EXIT_FAILURE);
			state.message_size = malloc(state.message_size);
			if (state.message_size == NULL)
                exit(EXIT_FAILURE);
        }

        state.message[state.message_index++] = state.current_char;

        if (state.current_char == '\0') {
            // Imprime a mensagem recebida diretamente
            printf("Received message from PID %d: %s\n", state.client_pid, state.message);

            // Limpar o buffer da mensagem
            free(state.message);
            state.message = NULL;
            state.message_index = 0;
            state.message_size = INITIAL_MSG_SIZE;
            state.receiving_pid = 1;
            state.client_pid = 0;
        }
    }
}

int main() {
    printf("Server PID: %d\n", getpid());

    // Inicialização do buffer de mensagem
    state.message = malloc(INITIAL_MSG_SIZE);
    if (state.message == NULL) {
        perror("Erro ao alocar memória para mensagem");
        exit(EXIT_FAILURE);
    }

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause();
    }

    // Liberação da memória alocada
    if (state.message != NULL) {
        free(state.message);
    }
    return 0;
}
