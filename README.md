/*
1.  PROGRAM TITLE: Student Management System using C
2.  This program is a console-based application written in C.
3.  It is designed to manage basic student records efficiently.
4.  The program uses structures to store student information.
5.  Each student record contains roll number, first name, last name, and course.
6.  An array of structures is used to store multiple students.
7.  The maximum number of students is defined using a macro (MAX = 100).
8.  Global variables are used to store student data and count.
9.  The program follows a menu-driven approach.
10. The user can interact with the program using numeric choices.

11. The "Add Student" feature allows entering new student details.
12. It checks whether the student list has reached its maximum limit.
13. Roll number, first name, last name, and course are taken as input.
14. Each new student is stored in the next available array position.
15. After adding, the total student count is increased.

16. The "Find by Roll Number" feature searches for a student using roll number.
17. It compares the entered roll number with stored records.
18. If a match is found, the complete student details are displayed.
19. If no match is found, an appropriate message is shown.

20. The "Find by First Name" feature searches students by first name.
21. It allows multiple students with the same first name.
22. String comparison is done using the strcmp() function.
23. Matching student records are displayed in a formatted manner.

24. The "Find by Course" feature lists all students registered in a course.
25. It helps in identifying students enrolled in the same course.
26. The comparison is case-sensitive.
27. If no students are found, a message is displayed.

28. The "Update Student" feature modifies existing student details.
29. The user provides the roll number of the student to update.
30. If found, new name and course details are entered.
31. The old data is overwritten with new values.

32. The "Delete Student" feature removes a student record.
33. Deletion is done based on roll number.
34. Once deleted, remaining records are shifted left.
35. This avoids empty gaps in the array.
36. The student count is reduced after deletion.

37. The "Count Students" feature displays total number of students.
38. It simply prints the current value of student_count.
39. This helps in tracking the number of stored records.

40. The program uses functions for each operation.
41. This improves modularity and readability.
42. Each function performs a single specific task.
43. The main function controls program flow.

44. A do-while loop is used for repeated menu display.
45. The menu continues until the user selects Exit (0).
46. Switch-case is used to handle user choices.
47. Invalid choices are handled gracefully.

48. The program uses standard input/output functions.
49. scanf() is used for user input.
50. printf() is used for displaying messages.

51. String handling is done using <string.h>.
52. The program avoids dynamic memory allocation.
53. All data is stored in static memory.
54. This makes the program simple and beginner-friendly.

55. The program is suitable for learning basic C concepts.
56. It demonstrates structures and arrays.
57. It also demonstrates functions and loops.
58. Conditional statements are used effectively.

59. Error messages are provided for invalid operations.
60. The program ensures data consistency.
61. It does not allow operations on non-existing students.

62. This program can be extended further.
63. File handling can be added for permanent storage.
64. Case-insensitive search can be implemented.
65. Input validation can be improved.

66. The program is platform-independent.
67. It can be compiled using GCC or any standard C compiler.
68. It works on Windows, Linux, and macOS.

69. The program follows a clear logical structure.
70. Code readability is maintained using proper indentation.
71. Meaningful function names are used.

72. This project is ideal for academic assignments.
73. It is suitable for beginners in programming.
74. It can be used as a base for advanced projects.

75. The program demonstrates CRUD operations.
76. CRUD stands for Create, Read, Update, and Delete.
77. These operations are common in database applications.

78. The system helps in organizing student data.
79. It reduces manual record keeping.
80. It improves accuracy and efficiency.

81. The menu-driven design makes it user-friendly.
82. Users can perform multiple operations in one run.
83. The exit option safely terminates the program.

84. The program avoids unnecessary complexity.
85. Logic is kept simple and understandable.
86. Comments improve maintainability.

87. This code follows procedural programming principles.
88. No object-oriented concepts are used.
89. It focuses on core C programming skills.

90. The program is well-structured and complete.
91. It fulfills all basic student management requirements.
92. It is easy to debug and modify.

93. This system can be enhanced with GUI in future.
94. Database connectivity can also be added.
95. Sorting and reporting features can be included.

96. Overall, this program is a complete mini-project.
97. It showcases practical use of C language.
98. It is suitable for exams and viva explanations.
99. The program is efficient for small datasets.
100.End of program description.
*/
