#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// We create a structure to hold the Call details
struct EmergencyCall {
    int priority;       // Higher number = Higher Urgency
    string description;

    // This logic tells the Priority Queue how to sort (Max-Heap behavior)
    bool operator<(const EmergencyCall& other) const {
        return priority < other.priority; 
    }
};

int main() {
    // SYLLABUS REFERENCE: This uses the STL Priority Queue (Unit 16 of C++ Syllabus)
    priority_queue<EmergencyCall> callCenter;

    // 1. How new calls are added (Push)
    cout << "--- Incoming Calls ---" << endl;
    
    callCenter.push({2, "Cat stuck in tree"});
    cout << "Added: Cat stuck in tree (Priority 2)" << endl;

    callCenter.push({10, "Building Fire"});
    cout << "Added: Building Fire (Priority 10)" << endl;

    callCenter.push({5, "Car Accident"});
    cout << "Added: Car Accident (Priority 5)" << endl;

    // 2. How the most urgent call is removed (Pop)
    cout << "\n--- Dispatching Units (Highest Priority First) ---" << endl;
    
    while(!callCenter.empty()) {
        EmergencyCall currentCall = callCenter.top(); // Peek at top
        callCenter.pop(); // Remove from queue
        
        cout << "DISPATCHING UNIT FOR: " << currentCall.description 
             << " (Priority " << currentCall.priority << ")" << endl;
    }

    return 0;
}
