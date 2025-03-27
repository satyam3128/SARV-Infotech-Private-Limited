#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#ifdef _WIN32
    #define CLEAR_SCREEN "CLS"
#else
    #define CLEAR_SCREEN "clear"
#endif
using namespace std;
struct Task {
    string description;
    bool completed;
};
void clearScreen() {
    system(CLEAR_SCREEN);
}
void displayMenu() {
    cout << "\n";
    cout << "           TO-DO LIST MANAGER            \n";   
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "0. Exit\n";
    cout << "\n";
    cout << "Enter your choice: ";
}
void displayTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "\nNo tasks in the list.\n";
    } else {
        cout << "\n";
        cout << "                TASK LIST                  \n";
       
        for (size_t i = 0; i < todoList.size(); ++i) {
            cout << i + 1 << ". " << todoList[i].description
                 << " [" << (todoList[i].completed ? "Completed" : "Pending") << "]\n";
        }
        cout << "\n";
    }
}
int main() {
    vector<Task> todoList;
    int choice;

    do {
        clearScreen();
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1: {
                
                Task newTask;
                cout << "\nEnter task description: ";
                getline(cin, newTask.description);
                newTask.completed = false;
                todoList.push_back(newTask);
                cout << "\nTask added successfully!\n";
                cout << "\nPress ENTER to continue...";
                cin.get();
                break;
            }
            case 2: {
                clearScreen();
                displayTasks(todoList);
                cout << "\nPress ENTER to continue...";
                cin.get();
                break;
            }
            case 3: {
                
                if (todoList.empty()) {
                    cout << "\nNo tasks to mark as completed.\n";
                } else {
                    displayTasks(todoList);
                    int taskIndex;
                    cout << "\nEnter task number to mark as completed: ";
                    cin >> taskIndex;

                    if (taskIndex > 0 && taskIndex <= static_cast<int>(todoList.size())) {
                        todoList[taskIndex - 1].completed = true;
                        cout << "\nTask marked as completed!\n";
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 4: {   
                if (todoList.empty()) {
                    cout << "\nNo tasks to remove.\n";
                } else {
                    displayTasks(todoList);
                    int taskIndex;
                    cout << "\nEnter task number to remove: ";
                    cin >> taskIndex;

                    if (taskIndex > 0 && taskIndex <= static_cast<int>(todoList.size())) {
                        todoList.erase(todoList.begin() + (taskIndex - 1));
                        cout << "\nTask removed successfully!\n";
                    } else {
                        cout << "\nInvalid task number.\n";
                    }
                }
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
            }
            case 0:
                cout << "\nExiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
                cout << "\nPress ENTER to continue...";
                cin.ignore();
                cin.get();
                break;
        }

    } while (choice != 0);
    return 0;
}