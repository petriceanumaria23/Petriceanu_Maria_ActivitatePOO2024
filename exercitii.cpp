#include<iostream>
using namespace std;

class Vapor {
private:
	
	static int nrVapoare;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePersoane;
	string numeVapor;
	float lungime;

public:
	Vapor() : nrPersoaneImbarcate(0) {
		this->nrVapoare = 4;
		this->capacitate = 200;
		this->varstePersoane = NULL;
		this->numeVapor = "Titanic";
		this->lungime = 269;



	}

	Vapor(int capacitate, int nrPersoaneImbarcate, string numeVapor, float lungime) {  
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->varstePersoane = new int[nrPersoaneImbarcate]; 
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePersoane[i] = varstePersoane[i];
		}
		if (numeVapor.length() > 4) {
			this->numeVapor = numeVapor;
		}
		this->lungime = lungime;


	}

	~Vapor() {         
		if (this->varstePersoane) {
			delete[]this->varstePersoane;
		}
	}


	Vapor(const Vapor& v) {
		this->capacitate = v.capacitate;
		this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
		this->varstePersoane = new int[v.nrPersoaneImbarcate];
		for (int i = 0; i < v.nrPersoaneImbarcate; i++) {
			this->varstePersoane[i] = v.varstePersoane[i];
		}

		this->numeVapor = v.numeVapor;
		this->lungime = v.lungime;


	}

	int getCapacitate() {   
		return this->capacitate;
	}


	string getNumeVapor() {
		return this->numeVapor;
	}

	float getLungime() {
		return this->lungime;
	}

	void setCapacitate(int capacitateNoua) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}

	}

	void setNumeVapor(string numeVaporNou) {
		if (numeVapor.length() > 4) {
			this->numeVapor = numeVapor;
		}
	}
	void setLungime(float lungimeNoua) {
		if (lungime > 0) {
			this->lungime = lungime;
		}

	}
	
	void afisare();
	
};


int Vapor::nrVapoare = 0;

void Vapor::afisare() {
	cout << "capacitate:" << this->capacitate << endl;
	cout << "lungime:" << this->lungime << endl;
	cout << "numevapor:" << this->numeVapor << endl;
}


	int main() {
		int varste[] = { 15,30,70 };
		Vapor v1(200, 50, "Titanic", 400);
		v1.afisare();  

		v1.setCapacitate(120);
		v1.setLungime(125);
		v1.setNumeVapor("Olympic");
		v1.afisare();  

		Vapor v2 = v1;  //copie a lui v1
		v2.afisare();

		//modificare v1 si verificare v2
		v1.setCapacitate(130);
	    v1.setNumeVapor("Queen Elizabeth");
		v1.setLungime(50);
		v1.afisare();
		v2.afisare(); 

		return 0;


	}
