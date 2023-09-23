/*
 * linked_list.h
 *
 *  Created on: Sep 12, 2023
 *      Author: Amr
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//Type Definitions
typedef struct {
    int ID;
    char name[40];
    float height;
}Sdata;

struct SNode {
    Sdata data;
    struct SNode* pNextNode;
};



typedef enum{
    NodeNull,
    NodeEmptyList
}NodeStatus_t;


//APIs
void AddNode();
int DeleteNode();
int PrintAll();
int DeleteAll();
int GetNth();
int GetLength();
int GetNthEnd();
int GetMiddle();
int DetectLoop();
int ReverseList();

#endif /* LINKED_LIST_H_ */
