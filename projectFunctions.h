/*
 * projectFunctions.h
 *
 * Author: Mina Sameh Tawfik
 * Group: 88
 * Date: 13/8/2024
 * Part of the Embedded System Diploma 
 */

#ifndef PROJECTFUNCTIONS_H_
#define PROJECTFUNCTIONS_H_

struct student{
	int id;
	char name[50];
	int age;
	float gpa;
};
struct node{
	struct student data;
	struct node *next;
};

void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
void deleteStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);

#endif /* PROJECTFUNCTIONS_H_ */
