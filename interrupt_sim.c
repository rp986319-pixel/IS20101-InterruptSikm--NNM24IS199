#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int mask_keyboard = 0;
int mask_mouse = 1;
int mask_printer = 0;
pthread_mutex_t lock;

void *keyboard_interrupt(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Keyboard Interrupt Received -> Processing ISR -> Done\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *mouse_interrupt(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Mouse Interrupt Received -> Processing ISR -> Done\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *printer_interrupt(void *arg) {
    pthread_mutex_lock(&lock);
    printf("Printer Interrupt Received -> Processing ISR -> Done\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    printf("=== INTERRUPT HANDLER SIMULATION ===\n");
    printf("Priority: Keyboard > Mouse > Printer\n\n");

    for (int i = 0; i < 6; i++) {
        int dev = rand() % 3;
        if (dev == 0 && !mask_keyboard)
            pthread_create(&tid, NULL, keyboard_interrupt, NULL);
        else if (dev == 1 && !mask_mouse)
            pthread_create(&tid, NULL, mouse_interrupt, NULL);
        else if (dev == 2 && !mask_printer)
            pthread_create(&tid, NULL, printer_interrupt, NULL);
        else
            printf("Interrupt Ignored (Masked Device)\n");
        pthread_join(tid, NULL);
        sleep(1);
    }

    printf("\nAll interrupts handled successfully. Execution complete.\n");
    pthread_mutex_destroy(&lock);
    return 0;
}
