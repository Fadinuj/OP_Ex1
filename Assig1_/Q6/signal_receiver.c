#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variables to store the received bits and reconstructed number
volatile sig_atomic_t bit_count = 0;
volatile sig_atomic_t result = 0;

// Unified signal handler for both SIGUSR1 and SIGUSR2
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        result = (result << 1) | 0; // Append 0 to result
    } else if (sig == SIGUSR2) {
        result = (result << 1) | 1; // Append 1 to result
    }
    bit_count++;
}

int main() {
    // Print the PID so the sender knows where to send signals
    printf("My PID is %d\n", getpid());

    // Set up the signal handler
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Register the handler for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // Loop forever to receive signals
    while (1) {
        pause(); // Wait for a signal
        if (bit_count == 8) { // After receiving 8 bits
            printf("Received: %d\n", result);
            bit_count = 0;
            result = 0;
        }
    }
}
