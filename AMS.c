//주소관리 시스템
//주소(address), 소유주 이름(owner name), 사람 인원(number of people), 건물 이름(building name), 건축 날짜(date of construction)
// 1 : 생성 2 : 조회 3 : 수정 4 : 삭제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct AddressManegementSystem {
    int key;
    char address[40];
    char OwnerName[10];
    int NumberOfPeople;
    char BuildingName[20];
    int DateOfConstruction;
} AMS;

struct Node {
    struct Node *next;
    struct AddressManegementSystem ams;
};

void InsertData(struct Node *target, AMS ams) {
    struct Node *new = malloc(sizeof(struct Node));
    new->ams.key = ams.key;
    new->ams.NumberOfPeople = ams.NumberOfPeople;
    new->ams.DateOfConstruction = ams.DateOfConstruction;
    strcpy(new->ams.address, ams.address);
    strcpy(new->ams.OwnerName, ams.OwnerName);
    strcpy(new->ams.BuildingName, ams.BuildingName);
    new->next = target->next;
    target->next = new;
}

AMS * RetrieveData(struct Node *head, int key) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->ams.key == key) {
            return &current->ams;
        } else {
            current = current->next;
        }
    }
    return NULL;
}


//void ModifyData(struct Node *head, int key, AMS ams) {
//    struct Node *current = head;
//    struct Node *overwrite = malloc(sizeof(struct Node));
//    while (current != NULL) {
//        if (current->ams.key == key) {
//            overwrite->ams.key = ams.key;
//            overwrite->ams.NumberOfPeople = ams.NumberOfPeople;
//            overwrite->ams.DateOfConstruction = ams.DateOfConstruction;
//            strcpy(overwrite->ams.address, ams.address);
//            strcpy(overwrite->ams.OwnerName, ams.OwnerName);
//            strcpy(overwrite->ams.BuildingName, ams.BuildingName);
//            overwrite->next = head->next;
//            head->next = overwrite;
//        }
//    }
//}

void DeleteData(struct Node *head, int key) {
    struct Node *temp = NULL;
    struct Node *current = head;
    while (current->next != NULL) {
        if (current->next->ams.key == key) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        } else {
            current = current->next;
        }
    }
    
}

//void ModifyData(struct Node *head, int key, AMS ams) {
//    DeleteData(head, 2);
//    InsertData(head, ams);
//}

void ModifyData(struct Node *head, int key, AMS ams) {
//    struct Node * current = head;
//    struct Node * overwrite = malloc(sizeof(struct Node));
//    while (current != NULL) {
//        if (current->ams.key == key) {
//            overwrite->ams.key = ams.key;
//            overwrite->ams.NumberOfPeople = ams.NumberOfPeople;
//            overwrite->ams.DateOfConstruction = ams.DateOfConstruction;
//            strcpy(overwrite->ams.address, ams.address);
//            strcpy(overwrite->ams.OwnerName, ams.OwnerName);
//            strcpy(overwrite->ams.BuildingName, ams.BuildingName);
//            break;
//        }
//        else {
//            current = current->next;
//        }
//    }
    struct Node * current = head;
    while (current != NULL) {
        if (current->ams.key == key) {
            current->ams.NumberOfPeople = ams.NumberOfPeople;
            current->ams.DateOfConstruction = ams.DateOfConstruction;
            strcpy(current->ams.address, ams.address);
            strcpy(current->ams.OwnerName, ams.OwnerName);
            strcpy(current->ams.BuildingName, ams.BuildingName);
            return;
        } else {
            current = current->next;
        }
    }
}


int main(void) {
    struct Node *head = malloc(sizeof(struct Node));
    
    
//    printf("1.생성    2.조회    3.수정    4.삭제");
//    printf("번호 입력 : ");
//    scanf("%d", &navigation);
    
    AMS * testData1 = malloc(sizeof(AMS));
    AMS * testData2 = malloc(sizeof(AMS));
    AMS * testData3 = malloc(sizeof(AMS));
    
    AMS * retrievedData = NULL;
    
    testData1->key = 1;
    strcpy(testData1->address, "asdf");
    strcpy(testData1->OwnerName, "유동호");
    
    testData2->key = 2;
    strcpy(testData2->address, "와우");
    strcpy(testData2->OwnerName, "유동관");
    
    testData3->key = 3;
    strcpy(testData3->address, "홀리쉣");
    strcpy(testData3->OwnerName, "관동유");
    

    InsertData(head, *testData1);
    InsertData(head->next, *testData2);
    
    printf("%s", head->next->ams.address);
    printf("%s", head->next->ams.OwnerName);
    printf("\n");
    
    retrievedData = RetrieveData(head, 2);
    
    printf("%s", retrievedData->address);
    printf("%s", retrievedData->OwnerName);
    printf("\n");
    
    
    
    ModifyData(head, 2, *testData3);
    ModifyData(head, 2, *testData3);
    
    testData3 = RetrieveData(head, 2);
    
    printf("%s", testData3->address);
    printf("%s", testData3->OwnerName);
    printf("\n");
}


