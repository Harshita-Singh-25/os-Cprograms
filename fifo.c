#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int frameCount) {
    int frames[frameCount];
    int front = 0, count = 0, pageFaults = 0;

    // Initialize frames to -1 (empty)
    for (int i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    printf("-------------------------------\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        // Check if page is already present
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            // Page Fault
            frames[front] = pages[i];
            front = (front + 1) % frameCount;
            pageFaults++;
            printf("%d\t", pages[i]);
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tFault\n");
        } else {
            // Page Hit
            printf("%d\t", pages[i]);
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\tHit\n");
        }
    }

    int hits = n - pageFaults;
    printf("\nSummary:\n");
    printf("Total Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", hits);
    printf("Hit Ratio: %.2f\n", (float)hits / n);
    printf("Miss Ratio: %.2f\n", (float)pageFaults / n);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 1, 3, 0, 1, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameCount = 3;

    printf("FIFO Page Replacement Algorithm\n");
    printf("Page Reference String: ");
    for (int i = 0; i < n; i++)
        printf("%d ", pages[i]);
    printf("\nNumber of Frames: %d\n", frameCount);

    fifoPageReplacement(pages, n, frameCount);

    return 0;
}
