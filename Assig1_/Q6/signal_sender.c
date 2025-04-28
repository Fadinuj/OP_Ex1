#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Function to send one bit as a signal
void send_bit(pid_t pid, int bit) {
    if (bit)
        kill(pid, SIGUSR2); // Send 1 as SIGUSR2
    else
        kill(pid, SIGUSR1); // Send 0 as SIGUSR1
    usleep(500); // Short delay to ensure receiver can handle the signal
}

int main() {
    pid_t receiver_pid;
    int number;

    // Get the PID of the receiver
    printf("Enter receiver PID: ");
    if (scanf("%d", &receiver_pid) != 1 || receiver_pid <= 0) {
        fprintf(stderr, "Invalid PID input.\n");
        return 1;
    }

    // Get the number to send (0–255)
    printf("Enter message (0-255): ");
    if (scanf("%d", &number) != 1 || number < 0 || number > 255) {
        fprintf(stderr, "Invalid number. Please enter a value between 0 and 255.\n");
        return 1;
    }

    // Send each bit from the most significant bit (MSB) to the least significant bit (LSB)
    for (int i = 7; i >= 0; --i) {
        int bit = (number >> i) & 1; // Extract i-th bit
        send_bit(receiver_pid, bit);
    }

    printf("Message sent!\n");

    return 0;
}
