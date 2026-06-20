#include <iostream>
#include <cstring>
using namespace std;


class Film {
protected:
    char*naslov;
    int *ocenki;
    int br_ocenki;
public:
    Film(char naslov[] = "film" , int* ocenki = nullptr, int br_ocenki = 0) {
        this->naslov = new char[strlen(naslov)+1];
        strcpy(this->naslov , naslov);
        this->ocenki = new int[br_ocenki];

        this->br_ocenki = br_ocenki;
        for (int i = 0; i < br_ocenki; i++) {
            this->ocenki[i] = ocenki[i];
        }
    }

    Film(const Film& f) {
        this->naslov = new char[strlen(f.naslov)+1];
        strcpy(this->naslov , f.naslov);
        this->ocenki = new int[f.br_ocenki];

        this->br_ocenki = f.br_ocenki;
        for (int i = 0; i < f.br_ocenki; i++) {
            this->ocenki[i] = f.ocenki[i];
        }
    }

    Film& operator=(const Film& f) {
        delete [] naslov;
        delete [] ocenki;
        this->naslov = new char[strlen(f.naslov)+1];
        strcpy(this->naslov , f.naslov);
        this->ocenki = new int[f.br_ocenki];

        this->br_ocenki = f.br_ocenki;
        for (int i = 0; i < f.br_ocenki; i++) {
            this->ocenki[i] = f.ocenki[i];
        }
        return *this;
    }

    ~Film() {
        delete[] naslov;
        delete[] ocenki;
    }

    friend ostream& operator<<(ostream &o, const Film& f) {
        o<<"Film: "<<f.naslov<<endl;
        o<<"Grades: ";
        for (int i = 0; i < f.br_ocenki; i++) {
            o<<f.ocenki[i]<<" ";
        }
        return o;
    }

    bool isFilmGood() {
        if (br_ocenki < 6) {
            return  false;
        }

        bool moznost = false;
        for (int i = 0;i < br_ocenki; i++) {
            if (ocenki[i] == 10 ) {
                moznost = true;
            }
            if (ocenki[i] < 4) {
                return false;
            }
        }
        return moznost;
    }
};


int main() {
    int N;
    Film films[100];

    cin>>N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        char naslov [50];
        int ocenki[50];
        int br_ocenki;

        cin.getline(naslov, 50);

        cin>>br_ocenki;

        for (int j = 0; j < br_ocenki; j++) {
            cin>>ocenki[j];
        }

        cin.ignore();
        films[i] = Film(naslov , ocenki, br_ocenki);

    }

    int choice;
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < N; ++i) {
            cout << films[i] << endl;
        }
    } else if (choice == 2) {
        for (int i = 0; i < N; ++i) {
            if (films[i].isFilmGood()) {
                cout << "GOOD FILM" << endl;
            } else {
                cout << "BAD FILM" << endl;
            }
        }
    } else {
        cout << "Test default constructor" << endl;
        cout << films[N+1] << endl;
    }
}