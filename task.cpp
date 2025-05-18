//WEEK 10, Q2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int index;
    int time;
    int deadline;
};

// Comparator to sort tasks by deadline
bool compare(const Task& a, const Task& b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<int> time(n), deadline(n);
    cout << "Enter time taken for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }

    cout << "Enter deadline for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> deadline[i];
    }

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        tasks[i] = {i + 1, time[i], deadline[i]}; // Correct order: index, time, deadline
    }

    // Sort tasks based on deadline
    sort(tasks.begin(), tasks.end(), compare);

    int currentTime = 0;
    vector<int> selectedTasks;

    for (const auto& task : tasks) {
        if (currentTime + task.time <= task.deadline) {
            currentTime += task.time;
            selectedTasks.push_back(task.index);
        }
    }

    // Output result
    cout << "Max number of tasks completed: " << selectedTasks.size() << endl;
    cout << "Selected task indices : ";
    for (int idx : selectedTasks) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}