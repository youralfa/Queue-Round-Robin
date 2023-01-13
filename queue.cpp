#include "queue.h"

void createQueue(Queue &Q){
    head(Q) = nil;
    tail(Q) = nil;
};

adr createElement(antrianMaintenanceServer data){
    adr P = new elmQue;
    info(P).name = data.name;
    info(P).burstTime = data.burstTime;
    info(P).waitingTime = 0;
    info(P).turnAroundTime = 0;
    next(P) = nil;
    return P;
}

void enQueue(Queue &Q, adr P){
    if(head(Q) == nil){
        head(Q) = P;
        tail(Q) = P;
    }else{
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void deQueue(Queue &Q, adr &P){
    if(head(Q) == nil){
        cout << "Queue kosong" << endl;
        P = nil;
    }else if(head(Q) == tail(Q)){
        P = head(Q);
        head(Q) = nil;
        tail(Q) = nil;
    }else{
        P = head(Q);
        head(Q) = next(head(Q));
        next(P) = nil;
    }
}

void showData(Queue Q){
    adr P = head(Q);

    if(head(Q) == nil && tail(Q) == nil){
        cout << "Queue kosong" << endl;
    }else{
        while(P != nil){
            cout << "Nama             : " << info(P).name << endl;
            cout << "Burst Time       : " << info(P).burstTime << endl;
            cout << "Waiting Time     : " << info(P).waitingTime << endl;
            cout << "Turn Around Time : " << info(P).turnAroundTime << endl;
            cout << endl;
            P = next(P);
        }
    }
};


void firstComeFirstServe(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum, int PrioUp, float &sumWT, float &sumTAT, int &time, int &burstTime){
    adr P1 = head(Q1);
    while(P1 != nil && (time == 0 || time % PrioUp != 0)){
        if(info(P1).burstTime < Quantum){
            sumWT += info(P1).waitingTime;
            time += info(P1).burstTime;
            info(P1).turnAroundTime = time;
            sumTAT += time;
            burstTime = info(P1).burstTime;
            P1 = next(P1);

            adr deleteMaintenance = nil;
            deQueue(Q1, deleteMaintenance);

            adr S1 = head(Q1);
            while(S1 != nil){
                info(S1).waitingTime += burstTime;
                S1 = next(S1);
            }

            adr S2 = head(Q2);
            while(S2 != nil){
                info(S2).waitingTime += burstTime;
                S2 = next(S2);
            }

            adr S3 = head(Q3);
            while(S3 != nil){
                info(S3).waitingTime += burstTime;
                S3 = next(S3);
            }
        }else{
            time += Quantum;
            burstTime = Quantum;
            info(P1).burstTime -= Quantum;
            P1 = next(P1);

            adr deleteMaintenance = nil;
            deQueue(Q1, deleteMaintenance);

            adr S1 = head(Q1);
            while(S1 != nil){
                info(S1).waitingTime += Quantum;
                S1 = next(S1);
            }

            adr S2 = head(Q2);
            while(S2 != nil){
                info(S2).waitingTime += Quantum;
                S2 = next(S2);
            }

            adr S3 = head(Q3);
            while(S3 != nil){
                info(S3).waitingTime += Quantum;
                S3 = next(S3);
            }
            enQueue(Q1, deleteMaintenance);
        }
    }
};

void firstComeFirstServePriority(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum, float &sumWT, float &sumTAT, int &time, int &burstTime){
    adr P1 = head(Q1);
    if(info(P1).burstTime < Quantum){
        sumWT += info(P1).waitingTime;
        time += info(P1).burstTime;
        info(P1).turnAroundTime = time;
        sumTAT += time;
        burstTime = info(P1).burstTime;
        P1 = next(P1);

        adr deleteMaintenance = nil;
        deQueue(Q1, deleteMaintenance);

        adr S1 = head(Q1);
        while(S1 != nil){
            info(S1).waitingTime += burstTime;
            S1 = next(S1);
        }

        adr S2 = head(Q2);
        while(S2 != nil){
            info(S2).waitingTime += burstTime;
            S2 = next(S2);
        }

        adr S3 = head(Q3);
        while(S3 != nil){
            info(S3).waitingTime += burstTime;
            S3 = next(S3);
        }
    }else{
        time += Quantum;
        burstTime = Quantum;
        info(P1).burstTime -= Quantum;
        P1 = next(P1);

        adr deleteMaintenance = nil;
        deQueue(Q1, deleteMaintenance);

        adr S1 = head(Q1);
        while(S1 != nil){
            info(S1).waitingTime += Quantum;
            S1 = next(S1);
        }

        adr S2 = head(Q2);
        while(S2 != nil){
            info(S2).waitingTime += Quantum;
            S2 = next(S2);
        }

        adr S3 = head(Q3);
        while(S3 != nil){
            info(S3).waitingTime += Quantum;
            S3 = next(S3);
        }
        enQueue(Q1, deleteMaintenance);
    }
};

void sortAndSum(Queue &Q1, Queue &Q2, Queue &Q3, int Quantum, int PrioUp, int n, float &sumWT, float &sumTAT, int &time, int &burstTime){
    while(head(Q1) != nil){
        if (time == 0 || time % PrioUp != 0){
            firstComeFirstServe(Q1, Q2, Q3, Quantum, PrioUp, sumWT, sumTAT, time, burstTime);
        }else{
            if(head(Q2) != nil){
                while(head(Q2) != nil){
                    adr newAntrian = new elmQue;
                    deQueue(Q2, newAntrian);
                    enQueue(Q1, newAntrian);
                }
            }
            if(head(Q3) != nil){
                while(head(Q3) != nil){
                    adr newAntrian = new elmQue;
                    deQueue(Q3, newAntrian);
                    enQueue(Q2, newAntrian);
                }
            }
            firstComeFirstServePriority(Q1, Q2, Q3, Quantum, sumWT, sumTAT, time, burstTime);
        }
    }
    cout << "Average Waiting Time       : " << sumWT/n << endl;
    cout << "Average Turn Around Time   : " << sumTAT/n << endl;
};

int selectMenu(){
    cout << "=========================== MENU ===========================" << endl;
    cout << "1. Create Element Queue" << endl;
    cout << "2. Masukkan Data Quantum dan Prio Up" << endl;
    cout << "3. Masukkan Jumlah Data Queue" << endl;
    cout << "4. Masukkan Data Queue" << endl;
    cout << "5. Menampilkan Data Queue Prioritas Tinggi" << endl;
    cout << "6. Menampilkan Data Queue Prioritas Sedang" << endl;
    cout << "7. Menampilkan Data Queue Prioritas Rendah" << endl;
    cout << "8. Menampilkan Semua Data Queue" << endl;
    cout << "9. Average" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu : ";

    int input = 0;
    cin >> input;
    cout << endl;

    return input;
};



