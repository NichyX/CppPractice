#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Entry.h"

using namespace std;

void printTransazioni(const vector<Entry>& v) {
    unsigned int dimensione = v.size();
    for(unsigned int i = 0; i < dimensione; i++){
        cout << v[i].getDate() << " " << v[i].getDescription() << " " << v[i].getAmount() << endl;
    }
}

int getBilancio(const vector<Entry>& v) {
    int bilancio = 0;
    unsigned int dimensione = v.size();
    for(unsigned int i = 0; i < dimensione; i++){
      bilancio += v[i].getAmount();
    }
    return bilancio;
}

int main(int argc, char* argv[]) {

    bool errore = false;
    string nomeFileAperto = "";
    int scelta = -1;
    vector <Entry> transazioni;
    string data;
    string descrizione;
    string ammontares;
    int ammontare;

    // Leggo l'argomento che viene passato in input, ci serve il nome del file da aprire
    // argc 2 == transactions.txt

    if (argc != 2) {
        cerr << "Il programma accetta solo un argomento, Esempi di utilizzo: programma.exe transactions.txt " << endl;
        errore = true;
    } else {
        string argNomeFile = argv[1];
        ifstream mioFile;
        mioFile.open(argNomeFile);
        if (mioFile.is_open()) {
            cout << "\nIl file e' stato trovato ed aperto e si chiama: " << argNomeFile << endl;
            nomeFileAperto = argNomeFile;
        } else {
            cout << "\nNessun file trovato con questo nome, prego fornirne uno: " << endl;
            string nomeFile = "";
            cin >> nomeFile;
            mioFile.open(nomeFile);
            if (mioFile.is_open()) {
                cout << "\nIl file e' stato trovato ed aperto e si chiama: " << nomeFile << endl;
                nomeFileAperto = nomeFile;
            } else {
                cerr << "\nNessun file trovato." << endl;
                return 0;
            }
       }

       if(!nomeFileAperto.empty()){
           string riga;
           while ( getline (mioFile,riga) )
           {
             Entry t;
             data = "";
             descrizione = "";
             ammontare = -1;
             ammontares = "";
             stringstream ss(riga);
             getline(ss, data, ',');  // https://www.youtube.com/watch?v=_IzYGiuX8QM
             getline(ss, descrizione, ',');
             getline(ss, ammontares, ',');
             ammontare = stoi(ammontares);
             t.setDate(data);
             t.setDescription(descrizione);
             t.setAmount(ammontare);
             transazioni.push_back(t);
          }
       } else {
         return 0;
       }

}

while (errore != true) {
    scelta = 0;
    cout << "\n\n";
    cout << "*******************************\n";
    cout << " 1 - Visualizza Transazioni.\n";
    cout << " 2 - Aggiungi Transazione.\n";
    cout << " 3 - Esci.\n";
    cout << "*******************************\n";
    cout << " Scegli: ";

    cin >> scelta;

    switch (scelta) {

        case 1:
        {
            cout << "\nEcco le tue transazioni attuali: \n \n";
            printTransazioni(transazioni);
            break;
        }

        case 2:
        {
            cout << "Aggiungi la tua Transazione: \n";
            Entry t;
            data = "";
            descrizione = "";
            ammontare = -1;
            ammontares = "";
            cout << "Inserisci la data nel formato GG/MM/AAAA: \n";
            cin >> data;
            cout << "Inserisci una descrizione: \n";
            cin >> descrizione;
            cout << "Inserisci l'ammontare: \n";
            cin >> ammontare;
            t.setDate(data);
            t.setDescription(descrizione);
            t.setAmount(ammontare);
            transazioni.push_back(t);

            // Adesso inseriamo nel file la nuova Transazione
            std::ofstream mioFile;
            mioFile.open(nomeFileAperto, std::ios_base::app);
            mioFile << "\n" << t.getDate() << "," << t.getDescription() << "," << t.getAmount();
            mioFile.close();
            break;
        }

        case 3:
        {
            int bilancio = getBilancio(transazioni);
            cout << "\nEcco le tuo bilancio: \n" << bilancio;
            cout << "\nProgramma terminato.\n";
            errore = true;
            break;
        }

        default:
        {
            cout << "Scelta non valida. \n";
            cout << "Scegli ancora: \n";
            cin >> scelta;
            break;
        }
    }

} // Fine loop

    return 0;
}
