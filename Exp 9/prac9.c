#include <stdio.h>
#include <stdbool.h>

void print_frames(int frames[], int capacity) {
    printf("[");
    for (int j = 0; j < capacity; j++) {
        if (frames[j] != -1) {
            printf("%d", frames[j]);
        } else {
            printf("-");
        }
        
        if (j < capacity - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    int n, capacity;

    printf("Enter the total number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    int frames[capacity];
    int faults = 0;
    int oldest_index = 0;

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("\n%-10s %-20s %s\n", "Incoming", "Memory State", "Status");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        int current_page = pages[i];
        bool is_hit = false;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == current_page) {
                is_hit = true;
                break;
            }
        }

        printf("%-10d ", current_page);
        
        if (is_hit) {
            print_frames(frames, capacity);
            printf("      HIT\n");
        } else {
            frames[oldest_index] = current_page;
            oldest_index = (oldest_index + 1) % capacity;
            faults++;
            
            print_frames(frames, capacity);
            printf("      MISS (Fault)\n");
        }
    }

    printf("-------------------------------------------------\n");
    printf("Total Page Faults: %d\n", faults);

    return 0;
}
