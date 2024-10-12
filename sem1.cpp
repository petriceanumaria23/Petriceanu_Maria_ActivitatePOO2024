#include<iostream>

using namespace std;
struct Masina {
	int nrUsi;
	bool esteElectrica;
	float capacitateMotor;
	string model;
};

void afisareMasina(Masina masina) {
	cout << "Model:" << masina.model << endl;
	cout << "nr usi" << masina.nrUsi << endl;
	cout << "capacitate motor:" << masina.capacitateMotor << endl;
	cout << "este Electrica:" << (masina.esteElectrica == true ? "da":"nu") << endl;

}

void modificanrUsi(Masina *masina, int nrUsi) {
	masina->nrUsi = nrUsi;

}

void modificanrUsiRef(Masina& masina, int nrUsi) {
	masina.nrUsi =nrUsi;
}

int main() {
	Masina masina;
	masina.nrUsi = 5;
	masina.esteElectrica = false;
	masina.capacitateMotor = 1.5;
	masina.model = "Audi Q5";


	afisareMasina(masina);
	cout << "Model:" << masina.model << endl;
	cout << "nr usi" << masina.nrUsi << endl;
	cout << "capacitate motor:" << masina.capacitateMotor << endl;
	cout << "este Electrica:" << (masina.esteElectrica == true ? "da" : "nu") << endl;
	
	Masina masina2;
	cout << "Introduceti modelul:";
	cin >> masina2.model;
	cout << " capac motor:";
	cin >> masina2.capacitateMotor;
	cout << " nr usi:";
	cin >> masina2.nrUsi;
	cout << "masina este electrica(1-da; 0-nu):";
	cin >> masina2.esteElectrica;

	afisareMasina(masina2);
	modificanrUsi(&masina2, 6);
	afisareMasina(masina2);
	modificanrUsiRef(masina2, 8);

	return 0;

}
