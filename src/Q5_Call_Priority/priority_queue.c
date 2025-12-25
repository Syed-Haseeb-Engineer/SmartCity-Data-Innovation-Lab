#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 100

// Define the structure for a call
typedef struct {
    int priority;        // Higher number = Higher Urgency
    char description[50];
} EmergencyCall;

// Global Heap structure
EmergencyCall heap[MAX_CALLS];
int heapSize = 0;

// Function to swap two calls in memory
void swap(EmergencyCall *a, EmergencyCall *b) {
    EmergencyCall temp = *a;
    *a = *b;
    *b = temp;
}

// 1. PUSH FUNCTION (Add to Heap)
// Logic: Add to end, then "bubble up" if it's bigger than its parent
void push(int priority, const char* desc) {
    if (heapSize >= MAX_CALLS) {
        printf("Queue is full!\n");
        return;
    }

    // Insert new element at the end
    heap[heapSize].priority = priority;
    strcpy(heap[heapSize].description, desc);
    
    int current = heapSize;
    heapSize++;

    // Bubble up (Max-Heap Logic)
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current].priority > heap[parent].priority) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

// 2. POP FUNCTION (Remove Highest Priority)
// Logic: Replace root with last item, then "bubble down"
void pop() {
    if (heapSize <= 0) return;

    // Replace root with the last element
    heap[0] = heap[heapSize - 1];
    heapSize--;

    // Bubble down
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int largest = current;

        // Check if left child exists and is larger
        if (left < heapSize && heap[left].priority > heap[largest].priority) {
            largest = left;
        }
        // Check if right child exists and is larger
        if (right < heapSize && heap[right].priority > heap[largest].priority) {
            largest = right;
        }

        // If current is the largest, we are done
        if (largest == current) break;

        swap(&heap[current], &heap[largest]);
        current = largest;
    }
}

// Helper to peek at the top element
EmergencyCall top() {
    return heap[0];
}

int isEmpty() {
    return heapSize == 0;
}

int main() {
    printf("--- Incoming Calls ---\n");

    push(2, "Cat stuck in tree");
    printf("Added: Cat stuck in tree (Priority 2)\n");

    push(10, "Building Fire");
    printf("Added: Building Fire (Priority 10)\n");

    push(5, "Car Accident");
    printf("Added: Car Accident (Priority 5)\n");

    printf("\n--- Dispatching Units (Highest Priority First) ---\n");

    while (!isEmpty()) {
        EmergencyCall currentCall = top();
        pop();

        printf("DISPATCHING UNIT FOR: %s (Priority %d)\n", 
               currentCall.description, currentCall.priority);
    }

    return 0;
}
