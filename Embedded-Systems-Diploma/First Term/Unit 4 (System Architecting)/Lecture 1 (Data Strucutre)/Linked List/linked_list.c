/*
 * linked_list.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Amr
 */

#include"linked_list.h"

struct SNode* gpFirstNode = NULL;

void AddNode()
{
    struct SNode* pNewNode = NULL;
    struct SNode* pLastNode = NULL;
    char temp[40];
    //check if list is empty
    if(gpFirstNode == NULL)
    {
        //if it is empty -> create new node
        pNewNode = (struct SNode*)malloc(1*sizeof(struct SNode));
        //assign gpfirst to new node
        gpFirstNode = pNewNode;
    }
    else //list is not empty
    {
        //navigate till the end
        pLastNode=gpFirstNode;
        while(pLastNode->pNextNode)
        {
            pLastNode = pLastNode->pNextNode;
        }
        //create new node
        pNewNode = (struct SNode*)malloc(1*sizeof(struct SNode));
        //pnext node points to new node
        pLastNode->pNextNode = pNewNode;
    }

    //fill data
    printf("\n Enter the ID of student: ");
    gets(temp);
    pNewNode->data.ID = atoi(temp);

    printf("\n Enter the name of student: ");
    gets(pNewNode->data.name);

    printf("\n Enter the height of student: ");
    gets(temp);
    pNewNode->data.height = atof(temp);

    //assign pnext to NULL
    pNewNode->pNextNode = NULL;
}

int DeleteNode()
{
    char temp[40];
    int selected_id=0;
    struct SNode* pSelectedNode = gpFirstNode;
    struct SNode* pPreviousNode = NULL;
    printf("\nEnter the ID of the student to be deleted: ");
    gets(temp);
    selected_id = atoi(temp);

    //is the linked list empty?
    if (gpFirstNode == NULL) //empty
    {
        printf("Error: The list is empty");
        return 0;
    }
    else //not empty
    {
        //loop on all nodes
        while(pSelectedNode)
        {
            if(pSelectedNode->data.ID == selected_id) //if the ID matches
            {
                if (pPreviousNode) //first node NOT to be deleted
                {
                    pPreviousNode->pNextNode=pSelectedNode->pNextNode;
                }
                else //1st node to be deleted
                {
                    gpFirstNode=pSelectedNode->pNextNode;
                }
                free(pSelectedNode);
                return 1;
            }
            
            pPreviousNode=pSelectedNode; //previous pointer steps on step
            pSelectedNode=pSelectedNode->pNextNode; //selected pointer steps one step
        } 
        printf("Error: ID does not exist");
        return 0;
    }

    
}

int PrintAll()
{
    struct SNode* pCurrentNode = gpFirstNode;
    int count=0;
    if(gpFirstNode == NULL)
    {
        printf("Error: The list is empty");
        return 0;
    }
    else
    {
        while(pCurrentNode)
        {
            printf("\nNode number (%d)",count+1);
            printf("\n \tID: %d",pCurrentNode->data.ID);
            printf("\n \tName: %s",pCurrentNode->data.name);
            printf("\n \theight: %f",pCurrentNode->data.height);
            pCurrentNode=pCurrentNode->pNextNode;
            count++;
        }
        return 1;
    }
    
}

int DeleteAll()
{
    struct SNode* pCurrentNode = gpFirstNode;
    struct SNode* pTempNode=pCurrentNode;
    if(gpFirstNode == NULL)
    {
        printf("Error: The list is empty");
        return 0;
    }
    else
    {
        while(pCurrentNode)
        {
            pTempNode=pCurrentNode;
            pCurrentNode=pCurrentNode->pNextNode;
            free(pTempNode);
        }
        gpFirstNode=NULL;
        return 1;
    }
}

int GetNth()
{
    int count=1, choice=1;
    struct SNode* pCurrentNode=gpFirstNode;
    printf("\nEnter the index of the required node: ");
    scanf("%d",&choice);

    if (gpFirstNode == NULL) //empty
    {
        printf("\nError: The list is empty");
        return 0;
    }
    else //not empty
    {
        while(pCurrentNode)
        {
            if(choice == count)
            {
                printf("\nNode number (%d)",choice);
                printf("\n \tID: %d",pCurrentNode->data.ID);
                printf("\n \tName: %s",pCurrentNode->data.name);
                printf("\n \theight: %f",pCurrentNode->data.height);
                return 1;
            }
            pCurrentNode=pCurrentNode->pNextNode; //navigate through the list
            count++;
        }
        if(choice>count-1 || choice==0)
        {
            printf("\nError: the entered index is not in the list");
        }
    }
}

int GetLength()
{
    struct SNode* pCountNode = gpFirstNode;
    int count=0;
    if(pCountNode == NULL)
    {
        printf("Error: The list is empty");
        return 0;
    }
    else
    {
        while(pCountNode)
        {
            count++;
            pCountNode=pCountNode->pNextNode;
        }
        return count;
    }
}

int GetNthEnd()
{
    int choice=0, i=0;
    if (gpFirstNode == NULL) //empty
    {
        printf("\nError: The list is empty");
        return 0;
    }
    else
    {
        printf("\nEnter the index of node from the end: ");
        scanf("%d",&choice);
        struct SNode* pMain = gpFirstNode;
        struct SNode* pRef = gpFirstNode;

        for(i=0;i<choice;i++)
        {
            pRef=pRef->pNextNode;
        }
        while(pRef)
        {
            pRef=pRef->pNextNode;
            pMain=pMain->pNextNode;
        }
        printf("\nNode number (%d) from end",choice);
        printf("\n \tID: %d",pMain->data.ID);
        printf("\n \tName: %s",pMain->data.name);
        printf("\n \theight: %f",pMain->data.height);
        return 1;
    }
    
    
}

int GetMiddle()
{
    struct SNode* pFast = gpFirstNode;
    struct SNode* pSlow = gpFirstNode;
    if (gpFirstNode == NULL) //empty
    {
        printf("\nError: The list is empty");
        return 0;
    }
    else
    {
        while(pFast && pFast->pNextNode)
        {
            pFast=pFast->pNextNode->pNextNode;
            pSlow=pSlow->pNextNode;
        }
        printf("\nThe middle node");
        printf("\n \tID: %d",pSlow->data.ID);
        printf("\n \tName: %s",pSlow->data.name);
        printf("\n \theight: %f",pSlow->data.height);
        return 1;
    }
}

int DetectLoop()
{
    struct SNode* pFast = gpFirstNode;
    struct SNode* pSlow = gpFirstNode;
    int flag=0;
    if (gpFirstNode == NULL) //empty
    {
        printf("\nError: The list is empty");
        return 0;
    }
    else
    {
        while(pFast && pFast->pNextNode)
        {
            pFast=pFast->pNextNode->pNextNode;
            pSlow=pSlow->pNextNode;
            if(pFast == pSlow)
                flag=1;
        }
    }
    if(flag==1)
    {
        printf("\nThe list is looped");
        return 1;
    }
    else
    {
        printf("\nThe list is NOT looped");
        return 1;
    }
}

int ReverseList()
{
    struct SNode* pCurrentNode=gpFirstNode;
    struct SNode* pNext=NULL;
    struct SNode* pPreviuosNode=NULL;
    if (gpFirstNode == NULL) //empty
    {
        printf("\nError: The list is empty");
        return 0;
    }
    else
    {
        while(pCurrentNode)
        {
           pNext=pCurrentNode->pNextNode; //store next
           pCurrentNode->pNextNode=pPreviuosNode; //reverse current node's pointer
           pPreviuosNode=pCurrentNode; //move pointer one step
           pCurrentNode=pNext; //move pointer one step
        }
        gpFirstNode=pPreviuosNode;
    }
}