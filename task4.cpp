#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks, const string& description);	
void addTask(vector<Task>& tasks, const string& description) {					// Function to add a task to the list
    tasks.push_back(Task(description));
    cout<<"Task added successfully.\n";
}
void viewTasks(const vector<Task>& tasks);										// Function declarations
void viewTasks(const vector<Task>& tasks) {										// Function to view all tasks with their status
    cout<<"\n====== Tasks ======\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
    cout<< i + 1 << ". " << tasks[i].description;
    if (tasks[i].completed) {
    cout<<" [Completed]";
    }
    cout<<"\n";
    }
}
void markTaskCompleted(vector<Task>& tasks, int index);

void markTaskCompleted(vector<Task>& tasks, int index) {						// Function to mark a task as completed
    if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout<<"Task marked as completed.\n";
    } else {
        cout<<"Invalid task index.\n";
    }
}
void removeTask(vector<Task>& tasks, int index);
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout<<"Task removed successfully.\n";
    } else {
        cout<<"Invalid task index.\n";
    }
}
int main () {
    vector<Task> tasks; 													// Vector to store tasks

    char choice;
    do {
        cout<<"\n==== To-Do List Manager ====\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Tasks\n";
        cout<<"3. Mark Task as Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice (1-5): ";
        cin>>choice;

        switch (choice) {
        case '1': {
                string taskDescription;
                cout<<"Enter task description: ";
                cin.ignore(); 												// Clear the input buffer
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
        case '2':
                viewTasks(tasks);
                break;
                
        case '3': {
                int index;
                cout<<"Enter task index to mark as completed: ";
                cin>>index;
                markTaskCompleted(tasks, index);
                break;
            }
        case '4': {
                int index;
                cout<<"Enter task index to remove: ";
                cin>>index;
                removeTask(tasks, index);
                break;
            }
        case '5':
                cout<<"Exiting the To-Do List Manager.\n";
                break;
                
        default:
                cout<<"Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != '5');
    return 0;
}
