#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

#define head(Q) (Q).head
#define tail(Q) (Q).tail
#define info(P) (P)->info
#define next(P) (P)->next
#define nil NULL

struct antrianMaintenanceServer{
    string name;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

typedef struct elmQue *adr;

struct elmQue{
    antrianMaintenanceServer info;
    adr next;
};

struct Queue{
    adr head;
    adr tail;
};

void createQueue(Queue &Q);
adr createElement(antrianMaintenanceServer data);
void enQueue(Queue &Q, adr P);
void deQueue(Queue &Q, adr &P);
void showData(Queue Q);
void firstComeFirstServe(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum, int PrioUp, float &sumWT, float &sumTAT, int &time, int &burstTime);
void firstComeFirstServePriority(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum , float &sumWT, float &sumTAT, int &time, int &burstTime);
void sortAndSum(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum, int PrioUp, int n, float &sumWT, float &sumTAT, int &time, int &burstTime);
int selectMenu();

#endif // QUEUE_H_INCLUDED
