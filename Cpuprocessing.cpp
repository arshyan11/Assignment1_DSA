#include <iostream>
using namespace std;

// Node structure to represent a process
class Process {
public:
    int process_id;
    int execution_time;
    int remaining_time;
    Process* next;

    Process(int id, int exec_time) {
        process_id = id;
        execution_time = exec_time;
        remaining_time = exec_time;
        next = nullptr;
    }
};

// Circular Linked List Scheduler
class CPUScheduler {
private:
    Process* head;
    int time_slice; // Time allocated to each process per cycle

public:
    CPUScheduler(int slice) {
        head = nullptr;
        time_slice = slice;
    }

    // Add a new process to the circular linked list
    void addProcess(int id, int exec_time) {
        Process* newProcess = new Process(id, exec_time);
        if (!head) {
            head = newProcess;
            head->next = head;
        } else {
            Process* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newProcess;
            newProcess->next = head;
        }
    }

    // Run the scheduler cycle by cycle
    void runScheduler() {
        int cycle = 1;  // Track the number of cycles
        while (head != nullptr) {
            cout << "Cycle " << cycle++ << ":" << endl;
            Process* current = head;
            Process* cycleStart = head;  // To detect when a full cycle completes

            // Traverse the circular linked list and process each node once per cycle
            do {
                cout << "Running Process: " << current->process_id << ", Remaining Time: " << current->remaining_time << endl;

                // Deduct the time slice from the remaining time
                if (current->remaining_time <= time_slice) {
                    cout << "Process " << current->process_id << " completed!" << endl;
                    Process* nextProcess = current->next;
                    removeProcess(current); // Remove completed process
                    current = nextProcess;
                    if (!head) break; // Exit if no more processes are left
                } else {
                    current->remaining_time -= time_slice;
                    cout << "Process " << current->process_id << " now has " << current->remaining_time << " remaining time." << endl;
                    current = current->next;
                }
            } while (current != cycleStart && head);  // Process each process once per cycle

            // Display state of the system after each cycle
            displayProcesses();
           
        }
    }

    // Remove a process from the circular linked list
    void removeProcess(Process* processToRemove) {
        if (head == processToRemove && head->next == head) {
            // Only one process in the list
            delete head;
            head = nullptr;
        } else {
            Process* temp = head;
            while (temp->next != processToRemove) {
                temp = temp->next;
            }
            // Remove processToRemove
            if (processToRemove == head) {
                head = head->next;
            }
            temp->next = processToRemove->next;
            delete processToRemove;
        }
    }

    // Display the state of all processes
    void displayProcesses() {
        if (!head) {
            cout << "No processes remaining." << endl;
            return;
        }
        Process* temp = head;
        do {
            cout << "Process ID: " << temp->process_id << ", Remaining Time: " << temp->remaining_time << endl;
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    // Create a scheduler with a time slice of 3 units
    CPUScheduler scheduler(3);

    // Add processes to the scheduler
    cout << "Initial Processes: [(P1, 10), (P2, 5), (P3, 8)]" << endl;
    scheduler.addProcess(1, 10); // Process 1 with 10 units of execution time
    scheduler.addProcess(2, 5);  // Process 2 with 5 units of execution time
    scheduler.addProcess(3, 8);  // Process 3 with 8 units of execution time

    // Run the scheduler
    scheduler.runScheduler();

    return 0;
}
