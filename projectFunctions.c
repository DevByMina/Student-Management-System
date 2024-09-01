/*
 * projectFunctions.c
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


struct node *head = NULL; 		//defining a pointer to points to the head(start) of the linked list
struct node *current= NULL; 	//current pointer used to loop on the linked list
struct node *previous= NULL;	//previous pointer used to be one step a back from the current pointer for deleting a node in the middle of the list

void addStudent(const struct student *const ptr){
	/*
	 * this function gets a filled structure student by a constant data constant pointer to structure
	 * then loop on the linked list to see if the input ID is previously reserved or not
	 * if ID isn't repeated it allocates a structure node space in memory using function malloc() which return the address of the allocated structure
	 * fill the node data with the passed pointer data
	 * check if this is the first node in the list if yes place the head pointer on this node and makethe node points to null
	 * if this isn't the first node the node is placed at the end of the list
	 */
	current=head;
	while(current != NULL){
		if((current->data.id)==(ptr->id)){
			printf("this ID is already preserved\n");
		    return;
		}
		current= current->next;
	}
	current=head;
	struct node *new=NULL;
	new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL){
		printf("node allocation in memory failed\n");
		return;
	}
	new->data= *ptr;
	if(head==NULL){
		head=new;
		new->next=NULL;
		return;
	}
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=new;
	new->next=NULL;
}
void displayStudents(void){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the function loops on the nodes outputting its data
	 */
	if(head==NULL){
		printf("No student details is added to the database yet\n");
	}
	current=head;
	while(current!=NULL){
		printf("[ ID: %d Name: %s Age: %d GPA: %f]\n", current->data.id, current->data.name, current->data.age, current->data.gpa);
		current=current->next;
	}
}
void searchStudentByID(int id){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the function loops on the nodes checking its ID compared to the ID passed to the function
	 * if the ID's matched the function prints the data of this node
	 */
	if(head==NULL ){
		printf("Their is no students in the Database\n");
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->data.id==id){
			printf("Student Found!\n[ ID: %d Name: %s Age: %d GPA: %f]\n", current->data.id, current->data.name, current->data.age, current->data.gpa);
			return;
		}
		current=current->next;
	}
	printf("Student ID is not found in the Database\n");
}
void updateStudent(int id){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the function loops on the nodes checking its ID compared to the ID passed to the function
	 * if the ID's matched the function asks the user to input new data to modify the current data of the specified node
	 * and if the passed ID isn't found the function return an error message to the user
	 */
	if(head==NULL){
		printf("Their is no students in the Database\n");
		return;
	}
	current=head;
	while(current!=NULL){
		if(current->data.id==id){
			printf("Update Student with ID: %d Data\n", id);
			printf("Enter Name: ");
			scanf(" %s",current->data.name);
			printf("Enter age: ");
			scanf(" %d", &current->data.age);
			printf("Enter GPA: ");
			scanf(" %f", &current->data.gpa);
			return;
		}
		current=current->next;
	}
	printf("Student ID is not found in the Database\n");
}
void deleteStudent(int id){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the function loops on the nodes using two pointers moving after each others checking its ID compared to the ID passed to the function
	 * if the ID's matched the previous node next address is updated to points to the current node next address to remove it from the list
	 * then the removed node is deleted from memory using free()
	 */
	if(head==NULL){
			printf("Their is no students in the Database\n");
			return;
		}
		current=head;
		previous=current;
	while(current!=NULL){
		if(current->data.id==id){
			if(current==head){
				head= current->next;
				free(current);
				printf("Student is Deleted Successfully\n");
				return;
			}
			previous->next=current->next;
			free(current);
			printf("Student is Deleted Successfully\n");
			return;
		}
		previous=current;
		current=current->next;
	}
	printf("Student ID is not found in the Database\n");
}
float calculateAverageGPA(void){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the function loops on the nodes summing the GPA of all nodes and also counting the number of nodes
	 * after looping on the whole list average is calculated and returned to the caller
	 */
	int count=0;
	float sum=0;
	if(head==NULL ){
		return 0;
	}
	current=head;
	while(current!=NULL){
		sum=sum+current->data.gpa;
		count++;
		current=current->next;
	}
	printf("Average GPA for %d Students is ",count);
	return sum/count;
}
void searchHighestGPA(void){
	/*
	 * check if the list contain nodes or not if it doesn't have nodes it output a message to the user
	 * if it contains nodes the first node is taken as the highest gpa and then check it against the gpa od the other nodes and updating the gpa and the ID of the highest gpa student
	 * then the highest gpa ID is sent to the searchStudentByID(highID) function to print its data
	 */
	int highID;
	float highGPA;
	if(head==NULL){
				printf("Their is no students in the Database\n");
				return;
	}
	current=head;
	highID=current->data.id;
	highGPA=current->data.gpa;
	current=current->next;
	while(current!=NULL){
		if(current->data.gpa > highGPA){
			highID=current->data.id;
			highGPA=current->data.gpa;
		}
		current=current->next;
	}
	printf("Highest GPA ");
	searchStudentByID(highID);
}
