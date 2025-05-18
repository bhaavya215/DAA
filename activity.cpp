//WEEK 10, Q1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store activity with index
struct Activity {
    int index;
    int start;
    int finish;
};

// Comparator function to sort activities by their finishing time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);
    cout << "Enter starting times: ";
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    cout << "Enter finishing times: ";
    for (int i = 0; i < n; i++) {
        cin >> finish[i];
    }

    // Store activities with their original index
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        activities[i] = {i + 1, start[i], finish[i]};
    }

    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), compare);

    // Select non-conflicting activities
    vector<int> selected;
    int lastFinishTime = 0;

    for (const auto& act : activities) {
        if (act.start >= lastFinishTime) {
            selected.push_back(act.index);
            lastFinishTime = act.finish;
        }
    }

    // Output the result
    cout << "Maximum number of non-conflicting activities: " << selected.size() << endl;
    cout << "Selected activities (by index): ";
    for (int i : selected) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}