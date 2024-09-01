/*
 * projectmain.c
 *
 * Author: Mina Sameh Tawfik
 * Group: 88
 * Date: 13/8/2024
 * Part of the Embedded System Diploma
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "projectFunctions.h"

int main(void){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int id;
	float average;
	int choice,flag=1;
	while(flag){
		printf("--------------------------------------------------\n");
		printf("1. Add Student\n");
		printf("2. Display Student\n");
		printf("3. Search Student by ID\n");
		printf("4. Update Student Information\n");
		printf("5. Delete Student\n");
		printf("6. Calculate Average GPA\n");
		printf("7. Search for Student with Highest GPA\n");
		printf("8. Exit\n");
		printf("Enter Choice: ");
		scanf(" %d", &choice);
		printf("--------------------------------------------------\n");
		switch(choice){
			case 1:
				struct student new;
				printf("Enter Student ID: ");
					scanf(" %d", &new.id);
					printf("Enter Name: ");
					scanf(" %s",new.name);
					printf("Enter age: ");
					scanf(" %d", &new.age);
					printf("Enter GPA: ");
					scanf(" %f", &new.gpa);
				addStudent(&new);
				break;
			case 2:
				displayStudents();
				break;
			case 3:
				printf("Enter ID: ");
				scanf(" %d", &id);
				searchStudentByID(id);
				break;
			case 4:
				printf("Enter Student ID to Update its Information: ");
				scanf(" %d", &id);
				updateStudent(id);
				break;
			case 5:
				printf("Enter Student ID to Delete its data: ");
				scanf(" %d", &id);
				deleteStudent(id);
				break;
			case 6:
				average= calculateAverageGPA();
				printf(" %f\n", average);
				break;
			case 7:
				searchHighestGPA();
				break;
			case 8:
				printf("Exiting...");
				flag=0;
				break;
			default:
				printf("Invalid Choice Please enter a choice from the list\n");
		}

	}
	return 0;
}

