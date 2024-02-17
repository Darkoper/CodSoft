#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nOptions:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter option: ";
        int option;
        cin >> option;

        switch (option) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
                break;
        }
    }

    return 0;
}

