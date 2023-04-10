#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_REQUESTS 1000
typedef enum { STUDENT, FACULTY } RequestType;
typedef struct {
 RequestType type;
 time_t arrival_time;
} Request;
int main() {
 Request student_requests[MAX_REQUESTS],
faculty_requests[MAX_REQUESTS];
 int num_student_requests = 0, num_faculty_requests = 0;
 time_t start_time = time(NULL);
 time_t end_time = start_time + 2*60*60; // 2 hours from start time
 int total_num_requests = 0;
 double total_time_spent = 0.0;
 // Process requests until end time is reached
 while (time(NULL) < end_time) {
 // Check for new requests from stdin
 RequestType type;
 printf("Enter request type (0 for student, 1 for faculty): ");
 scanf("%d", &type);
 if (type != STUDENT && type != FACULTY) {
 printf("Invalid request type.\n");
 continue;
 }
 // Add request to appropriate queue
 if (type == STUDENT) {
 if (num_student_requests < MAX_REQUESTS) {
 student_requests[num_student_requests].type = STUDENT;
 student_requests[num_student_requests].arrival_time =
time(NULL);
 num_student_requests++;
 total_num_requests++;
 } else {
 printf("Student request queue is full.\n");
 }
 } else {
 if (num_faculty_requests < MAX_REQUESTS) {
 faculty_requests[num_faculty_requests].type = FACULTY;
 faculty_requests[num_faculty_requests].arrival_time =
time(NULL);
 num_faculty_requests++;
 total_num_requests++;
 } else {
 printf("Faculty request queue is full.\n");
 }
 }
 // Process requests from queues
 if (num_student_requests > 0) {
 printf("Processing student request...\n");
 time_t current_time = time(NULL);
 double query_time = difftime(current_time,
student_requests[0].arrival_time);
 total_time_spent += query_time;
 printf("Query time: %g seconds.\n", query_time);
 num_student_requests--;
 for (int i = 0; i < num_student_requests; i++) {
 student_requests[i] = student_requests[i+1];
 }
 }
 if (num_faculty_requests > 0) {
 printf("Processing faculty request...\n");
 time_t current_time = time(NULL);
 double query_time = difftime(current_time,
faculty_requests[0].arrival_time);
 total_time_spent += query_time;
 printf("Query time: %g seconds.\n", query_time);
 num_faculty_requests--;
 for (int i = 0; i < num_faculty_requests; i++) {
 faculty_requests[i] = faculty_requests[i+1];
 }
 }
 }
 // Print summary statistics
 double avg_query_time = total_time_spent / total_num_requests;
 printf("Total time spent: %g seconds.\n", total_time_spent);
 printf("Average query time: %g seconds.\n", avg_query_time);
 return 0;
}