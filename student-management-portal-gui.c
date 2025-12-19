#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <commctrl.h>

#define MAX 100
#define IDC_ROLL 101
#define IDC_FNAME 102
#define IDC_LNAME 103
#define IDC_COURSE 104
#define IDC_OUTPUT 105
#define IDC_ADD 201
#define IDC_FIND_ROLL 202
#define IDC_FIND_NAME 203
#define IDC_FIND_COURSE 204
#define IDC_UPDATE 205
#define IDC_DELETE 206
#define IDC_COUNT 207

// Student structure
typedef struct {
    int roll;
    char fname[30];
    char lname[30];
    char course[30];
} Student;

// Global data
Student s[MAX];
int student_count = 0;

// Window handles
HWND hRoll, hFname, hLname, hCourse, hOutput;

// Helper function to display messages
void ShowMessage(const char *msg) {
    SetWindowTextA(hOutput, msg);
}

// Helper to get text from edit control
void GetEditText(HWND hEdit, char *buffer, int maxLen) {
    GetWindowTextA(hEdit, buffer, maxLen);
}

// Add Student
void OnAdd() {
    if (student_count >= MAX) {
        ShowMessage("Student list is full!");
        return;
    }
    
    char roll_text[10], fname[30], lname[30], course[30];
    GetEditText(hRoll, roll_text, 10);
    GetEditText(hFname, fname, 30);
    GetEditText(hLname, lname, 30);
    GetEditText(hCourse, course, 30);
    
    if (strlen(roll_text) == 0 || strlen(fname) == 0) {
        ShowMessage("Error: Roll and First Name cannot be empty!");
        return;
    }
    
    s[student_count].roll = atoi(roll_text);
    strncpy(s[student_count].fname, fname, 29);
    strncpy(s[student_count].lname, lname, 29);
    strncpy(s[student_count].course, course, 29);
    student_count++;
    
    SetWindowTextA(hRoll, "");
    SetWindowTextA(hFname, "");
    SetWindowTextA(hLname, "");
    SetWindowTextA(hCourse, "");
    
    ShowMessage("Student added successfully!");
}

// Find by Roll
void OnFindRoll() {
    char roll_text[10];
    GetEditText(hRoll, roll_text, 10);
    int roll = atoi(roll_text);
    
    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            char buffer[512];
            sprintf(buffer, "Found:\r\nRoll: %d\r\nName: %s %s\r\nCourse: %s",
                    s[i].roll, s[i].fname, s[i].lname, s[i].course);
            ShowMessage(buffer);
            return;
        }
    }
    ShowMessage("Student not found!");
}

// Find by Name
void OnFindName() {
    char search_name[30];
    GetEditText(hFname, search_name, 30);
    char result[2048] = "Results:\r\n";
    int found = 0;
    
    for (int i = 0; i < student_count; i++) {
        if (strcmp(s[i].fname, search_name) == 0) {
            char line[256];
            sprintf(line, "Roll: %d | Name: %s %s | Course: %s\r\n",
                    s[i].roll, s[i].fname, s[i].lname, s[i].course);
            strcat(result, line);
            found = 1;
        }
    }
    
    ShowMessage(found ? result : "No student found with this name!");
}

// Find by Course
void OnFindCourse() {
    char search_course[30];
    GetEditText(hCourse, search_course, 30);
    char result[2048] = "Results:\r\n";
    int found = 0;
    
    for (int i = 0; i < student_count; i++) {
        if (strcmp(s[i].course, search_course) == 0) {
            char line[256];
            sprintf(line, "Roll: %d | Name: %s %s | Course: %s\r\n",
                    s[i].roll, s[i].fname, s[i].lname, s[i].course);
            strcat(result, line);
            found = 1;
        }
    }
    
    ShowMessage(found ? result : "No students in this course!");
}

// Update Student
void OnUpdate() {
    char roll_text[10];
    GetEditText(hRoll, roll_text, 10);
    int roll = atoi(roll_text);
    
    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            GetEditText(hFname, s[i].fname, 30);
            GetEditText(hLname, s[i].lname, 30);
            GetEditText(hCourse, s[i].course, 30);
            ShowMessage("Student updated successfully!");
            return;
        }
    }
    ShowMessage("Student not found for update!");
}

// Delete Student
void OnDelete() {
    char roll_text[10];
    GetEditText(hRoll, roll_text, 10);
    int roll = atoi(roll_text);
    
    for (int i = 0; i < student_count; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < student_count - 1; j++)
                s[j] = s[j + 1];
            student_count--;
            ShowMessage("Student deleted successfully!");
            return;
        }
    }
    ShowMessage("Student not found!");
}

// Count Students
void OnCount() {
    char buffer[50];
    sprintf(buffer, "Total students: %d", student_count);
    ShowMessage(buffer);
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            // Create input labels and fields
            CreateWindowA("STATIC", "Roll Number:", WS_VISIBLE | WS_CHILD,
                         20, 20, 100, 20, hwnd, NULL, NULL, NULL);
            hRoll = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                 130, 18, 330, 25, hwnd, (HMENU)IDC_ROLL, NULL, NULL);
            
            CreateWindowA("STATIC", "First Name:", WS_VISIBLE | WS_CHILD,
                         20, 55, 100, 20, hwnd, NULL, NULL, NULL);
            hFname = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                  130, 53, 330, 25, hwnd, (HMENU)IDC_FNAME, NULL, NULL);
            
            CreateWindowA("STATIC", "Last Name:", WS_VISIBLE | WS_CHILD,
                         20, 90, 100, 20, hwnd, NULL, NULL, NULL);
            hLname = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                  130, 88, 330, 25, hwnd, (HMENU)IDC_LNAME, NULL, NULL);
            
            CreateWindowA("STATIC", "Course:", WS_VISIBLE | WS_CHILD,
                         20, 125, 100, 20, hwnd, NULL, NULL, NULL);
            hCourse = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                                   130, 123, 330, 25, hwnd, (HMENU)IDC_COURSE, NULL, NULL);
            
            // Create buttons
            CreateWindowA("BUTTON", "Add Student", WS_VISIBLE | WS_CHILD,
                         20, 165, 215, 30, hwnd, (HMENU)IDC_ADD, NULL, NULL);
            CreateWindowA("BUTTON", "Find by Roll", WS_VISIBLE | WS_CHILD,
                         245, 165, 215, 30, hwnd, (HMENU)IDC_FIND_ROLL, NULL, NULL);
            
            CreateWindowA("BUTTON", "Find by First Name", WS_VISIBLE | WS_CHILD,
                         20, 205, 215, 30, hwnd, (HMENU)IDC_FIND_NAME, NULL, NULL);
            CreateWindowA("BUTTON", "Find by Course", WS_VISIBLE | WS_CHILD,
                         245, 205, 215, 30, hwnd, (HMENU)IDC_FIND_COURSE, NULL, NULL);
            
            CreateWindowA("BUTTON", "Update", WS_VISIBLE | WS_CHILD,
                         20, 245, 215, 30, hwnd, (HMENU)IDC_UPDATE, NULL, NULL);
            CreateWindowA("BUTTON", "Delete", WS_VISIBLE | WS_CHILD,
                         245, 245, 215, 30, hwnd, (HMENU)IDC_DELETE, NULL, NULL);
            
            CreateWindowA("BUTTON", "Count", WS_VISIBLE | WS_CHILD,
                         20, 285, 440, 30, hwnd, (HMENU)IDC_COUNT, NULL, NULL);
            
            // Create output area
            CreateWindowA("STATIC", "Output/Results:", WS_VISIBLE | WS_CHILD,
                         20, 325, 440, 20, hwnd, NULL, NULL, NULL);
            hOutput = CreateWindowA("EDIT", "Ready. Use the fields above and buttons to manage student data.",
                                   WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | 
                                   ES_AUTOVSCROLL | ES_READONLY | WS_VSCROLL,
                                   20, 350, 440, 120, hwnd, (HMENU)IDC_OUTPUT, NULL, NULL);
            break;
        }
        
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDC_ADD: OnAdd(); break;
                case IDC_FIND_ROLL: OnFindRoll(); break;
                case IDC_FIND_NAME: OnFindName(); break;
                case IDC_FIND_COURSE: OnFindCourse(); break;
                case IDC_UPDATE: OnUpdate(); break;
                case IDC_DELETE: OnDelete(); break;
                case IDC_COUNT: OnCount(); break;
            }
            break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "StudentMgmtClass";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    RegisterClassA(&wc);
    
    HWND hwnd = CreateWindowA("StudentMgmtClass", "Student Management System",
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                             500, 550, NULL, NULL, hInstance, NULL);
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
