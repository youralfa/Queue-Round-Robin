#include "queue.h"

int main()
{
            Queue Q1, Q2, Q3;
            antrianMaintenanceServer data;

    int pilihan, dataQ1, dataQ2, dataQ3, Quantum, PrioUp, time = 0, burstTime = 0;
    float N, sumWT = 0, sumTAT = 0;
    char backToMenu = 'Y';

    pilihan = selectMenu();
    while (pilihan != 0 && backToMenu == 'Y'){
        switch(pilihan){
            case 1 :
                createQueue(Q1);
                createQueue(Q2);
                createQueue(Q3);
                cout << "Queue has been Created" << endl;
                break;

            case 2 :
                cout << "Data Quantum   : "; cin >> Quantum;
                cout << "Data PrioUp    : "; cin >> PrioUp;
                break;

            case 3 :
                cout << "Data Q1 : "; cin >> dataQ1;
                cout << "Data Q2 : "; cin >> dataQ2;
                cout << "Data Q3 : "; cin >> dataQ3;
                N = dataQ1 + dataQ2 + dataQ3;
                break;

            case 4 :
                cout << "=========QUEUE Q1==========" << endl;
                for(int i = 0; i < dataQ1; i++){
                    cout << "Masukkan Nama      : "; cin >> data.name;
                    cout << "Masukkan BurstTime : "; cin >> data.burstTime;
                    cout << endl;
                    adr P1 = createElement(data);
                    enQueue(Q1, P1);
                }

                cout << "=========QUEUE Q2==========" << endl;
                for(int i = 0; i < dataQ2; i++){
                    cout << "Masukkan Nama      : "; cin >> data.name;
                    cout << "Masukkan BurstTime : "; cin >> data.burstTime;
                    cout << endl;
                    adr P2 = createElement(data);
                    enQueue(Q2, P2);
                }

                cout << "=========QUEUE Q3==========" << endl;
                for(int i = 0; i < dataQ3; i++){
                    cout << "Masukkan Nama      : "; cin >> data.name;
                    cout << "Masukkan BurstTime : "; cin >> data.burstTime;
                    cout << endl;
                    adr P3 = createElement(data);
                    enQueue(Q3, P3);
                }
                break;

            case 5 :
                cout << "-----Kegiatan Berprioritas Tinggi-----" << endl;
                showData(Q1);
                break;

            case 6 :
                cout << "-----Kegiatan Berprioritas Sedang-----" << endl;
                showData(Q2);
                break;

            case 7 :
                cout << "-----Kegiatan Berprioritas Rendah-----" << endl;
                showData(Q3);
                break;

            case 8 :
                cout << "-----Kegiatan Berprioritas Tinggi-----" << endl;
                showData(Q1);

                cout << "-----Kegiatan Berprioritas Sedang-----" << endl;
                showData(Q2);

                cout << "-----Kegiatan Berprioritas Rendah-----" << endl;
                showData(Q3);
                break;

            case 9 :
                sortAndSum(Q1, Q2, Q3, Quantum, PrioUp, N, sumWT, sumTAT, time, burstTime);
                break;
        }

        cout << "Kembali ke menu utama? (Y/N)  "; cin >> backToMenu;
        while(backToMenu != 'Y' && backToMenu != 'N'){
            cout << "Kembali ke menu utama? (Y/N)  "; cin >> backToMenu;
        }
        cout << endl;
        backToMenu == 'Y' ? pilihan = selectMenu() : pilihan = 0;
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    cout << endl;
    return 0;
}
