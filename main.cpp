#include <bits/stdc++.h>

using namespace std;

struct Task {
    int starting_time;
    int finishing_time;
};

bool compareFinishingTime(Task &task1, Task &task2) {
    return task1.finishing_time < task2.finishing_time;
}

int maximumTaskSelection(vector <Task> &tasks) {
    sort(tasks.begin(), tasks.end(), compareFinishingTime);

    Task last = tasks[0];
    int count = 1;

    for (Task i: tasks) {
        if (i.starting_time >= last.finishing_time) {
            count++;
            last = i;
        }
    }

    return count;
}

int main() {
    int n, starting_time, finishing_time;

    cin >> n;

    vector <Task> tasks;

    for (int i = 0; i < n; i++) {
        cin >> starting_time >> finishing_time;

        Task input = {starting_time, finishing_time};

        tasks.push_back(input);
    }

    int work_count = maximumTaskSelection(tasks);

    cout << work_count << endl;

    return 0;
}

