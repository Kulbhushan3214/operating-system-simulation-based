#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

int main() {
    const int TOTAL_TIME = 120;  // total time available in minutes
    const int STUDENT_TIME = 5;  // time dedicated to each student query in minutes
    const int FACULTY_TIME = 10;  // time dedicated to each faculty query in minutes

    queue<int> studentQueue, facultyQueue;  // queues to store requests

    srand(time(nullptr));  // seed the random number generator

    int time = 0;  // current time in minutes
    int totalHandledTime = 0;  // total time spent on handling queries
    int totalQueriesHandled = 0;  // total number of queries handled
    while (time < TOTAL_TIME) {
        while (!studentQueue.empty() && time < TOTAL_TIME) {
            cout << "Handling student query #" << studentQueue.front() << endl;
            totalHandledTime += STUDENT_TIME;
            totalQueriesHandled++;
            studentQueue.pop();
            time += STUDENT_TIME;
        }

        while (!facultyQueue.empty() && time < TOTAL_TIME) {
            cout << "Handling faculty query #" << facultyQueue.front() << endl;
            totalHandledTime += FACULTY_TIME;
            totalQueriesHandled++;
            facultyQueue.pop();
            time += FACULTY_TIME;
        }

        if (rand() % 2 == 0) {
            studentQueue.push(totalQueriesHandled + 1);
        } else {
            facultyQueue.push(totalQueriesHandled + 1);
        }
    }
    cout << "Session summary:" << endl;
    cout << "Total time spent on handling queries: " << totalHandledTime << " minutes" << endl;
    cout << "Total number of queries handled: " << totalQueriesHandled << endl;
    cout << "Average query time: " << avgQueryTime << " minutes" << endl;

    return 0;
}
