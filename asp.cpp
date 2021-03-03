#include <iostream>	
#include "liste.h"
#include "stabla.h"	
#include "vreme.h"
#include <iomanip>
#include <fstream>
using namespace std;


int main() {

	Lista l1, l2;
	Stablo s1, s2;
	ifstream fajl;
	int b, j, n, m;
	int i = 0;
	while (i != 10) {

		cout << "Izabrati operaciju" << endl;
		cout << "0. Unistiti skup" << endl;
		cout << "1. Stvori prazan skup" << endl;
		cout << "2. Pretraga za zadati element" << endl;
		cout << "3. Ubacivanje elementa u skup" << endl;
		cout << "4. Brisanje elementa iz skupa" << endl;
		cout << "5. Brisanje elemetna skupa u zadatom opsegu" << endl;
		cout << "6. Dohvatanje ukupnog broja elementa u skupu" << endl;
		cout << "7. Unija dva skupa" << endl;
		cout << "8. Test" << endl;
		cin >> i;

		if (i == 0) { ////////////////////////////////////////////////////////////////////////////////
			cout << "obrisi listu - 1" << endl;
			cout << "obrisi stablo - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "obrisi prvu listu - 1" << endl;
				cout << "obrisi drugu listu - 2" << endl;
				cin >> i;
				if(i == 1)l1.izbrisiListu();
				else if(i == 2) l2.izbrisiListu();
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else if (i == 2) {
				cout << "obrisi prvo stablo - 1" << endl;
				cout << "obrisi drugo stablo - 2" << endl;
				cin >> i;
				if(i == 1) s1.root = s1.obrisiStablo(s1.root);
				else if(i == 2)s1.root = s1.obrisiStablo(s1.root);
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else cout << "izabrali ste pogresan broj" << endl;
		}
		else if (i == 1) { /////////////////////////////////////////////////////////////////////////
			s1.napraviStablo();
			s1.napraviStablo();
			l1.napraviListu();
			l2.napraviListu();		
		}
		else if (i == 2) { //////////////////////////////////////////////////////////////////////////
			cout << "pronadji u listi - 1" << endl;
			cout << "pronadji u stablu - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "prva lista - 1" << endl;
				cout << "druga lista - 2" << endl;
				cin >> i;
				cout << "uneti broj" << endl;
				cin >> b;
				if (i == 1) {
					l1.pretraga(b);
				}
				else if (i == 2) {
					l1.pretraga(b);
				}
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else if (i == 2) {
				cout << "prvo stablo - 1" << endl;
				cout << "drugo stablo - 2" << endl;
				cin >> i;
				cout << "uneti broj" << endl;
				cin >> b;
				if (i == 1) {
					s1.pronadjiElement(b);
				}
				else if (i == 2) {
					s2.pronadjiElement(b);
				}
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else cout << "izabrali ste pogresan broj" << endl;
		
		
		}
		else if (i == 3) {///////////////////////////////////////////////////////////////
			cout << "uneti iz txt fajla - 1" << endl;
			cout << "uneti sa standardnog ulaza - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "uneti u listu - 1" << endl;
				cout << "uneti u stablo - 2" << endl;
				cin >> i;
				fajl.open("num.txt");
				if (i == 1) {
					cout << "prva lista - 1" << endl;
					cout << "druga lista - 2" << endl;
					cin >> i;
					if (i == 1) {
						while (!fajl.eof()) {
							fajl >> b;
							l1.unesiElement(b);
						}
					}
					else if (i == 2) {
						while (!fajl.eof()) {
							fajl >> b;
							l2.unesiElement(b);
						}
					}
					else cout << "izabrali ste pogresan broj" << endl;
				}
				else if (i == 2) {
					cout << "prvo stablo- 1" << endl;
					cout << "drugo stablo - 2" << endl;
					cin >> i;
					if (i == 1) {
						while (!fajl.eof()) {
							fajl >> b;
							node *tek = new node;
							tek->x = b;
							tek->l = NULL;
							tek->r = NULL;
							s1.unesiElement(tek);
						}
						ispis(s1.root);
					}
					else if (i == 2) {
						while (!fajl.eof()) {
							fajl >> b;
							node *tek = new node;
							tek->x = b;
							tek->l = NULL;
							tek->r = NULL;
							s1.unesiElement(tek);
						}
					}
					else cout << "izabrali ste pogresan broj" << endl;

				}
				else cout << "izabrali ste pogresan broj" << endl;			
				fajl.close();
			}
			else if (i == 2) {
				cout << "uneti u listu - 1" << endl;
				cout << "uneti u stablo - 2" << endl;
				cin >> i;
				if (i == 1) {
					cout << "prva lista - 1" << endl;
					cout << "druga lista - 2" << endl;
					cin >> i;
					cout << "uneti broj" << endl;
					cin >> b;
					if (i == 1) {
						l1.unesiElement(b);
					}
					else if (i == 2) {
						l2.unesiElement(b);
					}
					else cout << "izabrali ste pogresan broj" << endl;
				}
				else if (i == 2) {
					cout << "prvo stablo - 1" << endl;
					cout << "drugo stablo - 2" << endl;
					cin >> i;
					cout << "uneti broj" << endl;
					cin >> b;
					node *tek = new node;
					tek->x = b;
					tek->l = NULL;
					tek->r = NULL;
					if (i == 1) {
						s1.unesiElement(tek);
					}
					else if (i == 2) {
						s2.unesiElement(tek);
					}
					else cout << "izabrali ste pogresan broj" << endl;
				}
				else cout << "izabrali ste pogresan broj" << endl;
			}
		}
		else if (i == 4) {//////////////////////////////////////////////////////////////////////////
			cout << "obrisi iz liste - 1" << endl;
			cout << "obrisi iz stabla - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "prva lista - 1" << endl;
				cout << "druga lista - 2" << endl;
				cin >> i;
				cout << "uneti broj" << endl;
				cin >> b;
				if (i == 1) {
					l1.brisanjeELementa(b);
				}
				else if (i == 2) {
					l2.brisanjeELementa(b);
				}
				else cout << "izabrali ste pogresan broj" << endl;
				
			}
			else if (i == 2) {
				cout << "prvo stablo - 1" << endl;
				cout << "drugo stablo - 2" << endl;
				cin >> i;
				cout << "uneti broj" << endl;
				cin >> b;
				if (i == 1) {
					s1.obrisiElement(b, s1.root);
				}
				else if (i == 2) {
					s2.obrisiElement(b, s1.root);
				}
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else cout << "izabrali ste pogresan broj" << endl;
		}
		else if (i == 5) {//////////////////////////////////////////////////////////////////////////
			cout << "obrisi opseg iz liste - 1" << endl;
			cout << "obrisi opseg iz stabla - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "prva lista - 1" << endl;
				cout << "druga lista - 2" << endl;
				cin >> i;
				cout << "uneti granice" << endl;
				cin >> b;
				cin >> j;
				if (i == 1) {
					l1.brisanjeOpsega(b, j);
					l1.ipsisiElemente();
				}
				else if (i == 2) {
					l2.brisanjeOpsega(b, j);
				}
				else cout << "izabrali ste pogresan broj" << endl;

			}
			else if (i == 2) {
				cout << "prvo stablo - 1" << endl;
				cout << "drugo stablo - 2" << endl;
				cin >> i;
				cout << "uneti granice" << endl;
				cin >> b;
				cin >> j;
				if (i == 1) {
					s1.obrisiOpseg(b, j);
					ispis(s1.root);
				}
				else if (i == 2) {
					s2.obrisiOpseg(b, j);
				}
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else cout << "izabrali ste pogresan broj" << endl;
		
		}
		else if (i == 6) {//////////////////////////////////////////////////////////////////////////////
			cout << "broj elemenata liste - 1" << endl;
			cout << "broj elemenata stabla - 2" << endl;
			cin >> i;
			if (i == 1) {
				cout << "prva lista - 1" << endl;
				cout << "druga lista - 2" << endl;
				cin >> i;
				if (i == 1) b = l1.brojElemenata();
				if (i == 2) b = l2.brojElemenata();
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else if (i == 2) {
				cout << "prvo stablo - 1" << endl;
				cout << "drugo stablo - 2" << endl;
				cin >> i;
				if (i == 1) b = s1.brojElemenata();
				if (i == 2) b = s2.brojElemenata();
				else cout << "izabrali ste pogresan broj" << endl;
			}
			else cout << "izabrali ste pogresan broj" << endl;
		}
		else if (i == 7) {/////////////////////////////////////////////// 
			cout << "unija sa listama - 1" << endl;
			cout << "unija sa stablima - 2" << endl;
			cin >> i;
			if (i == 1) {
				l1 = unija(l1, l2);
				l1.ipsisiElemente();
			}
			else if (i == 2) {
				s1 = unija(s1, s2);
				ispis(s1.root);
			}
			else cout << "izabrali ste pogresan broj" << endl;		
		}
		else if (i == 8) {///////////////////////////////////////////////////////////////////
			cout << "test liste - 1" << endl;
			cout << "test stabla - 2" << endl;
			cin >> i;
			if (i == 1){
				int b;
				int i, j, n;
				double d[50], s = 0, q;
				Lista l1, l2;
				PerfCalc pc;
				for (int k = 0; k < 6; k++) {
					if (k == 0) n = 200;
					else if (k == 1)n = 500;
					else if (k == 2)n = 1000;
					else if (k == 3)n = 10000;
					else if (k == 4)n = 100000;
					else if (k == 5)n = 100000;
					l2.napraviListu();
					for (j = 0; j < 3; j++) {
						l1.napraviListu();
						pc.start();
						for (i = 0; i < n; i++) {
							b = rand()*(RAND_MAX + 1) + rand();
							l1.unesiElement(b);
						}
						pc.stop();
						q = pc.elapsedMillis();
						cout << q << endl;
						s = s + q;
					}
					s = s / 3;
					d[5 * k] = s;
					for (i = 0; i < n; i++) {
						b = rand()*(RAND_MAX + 1) + rand();
						l2.unesiElement(b);
					}
					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						l1.unesiElement(b);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}
					s = s / 3;
					d[5 * k + 1] = s;
					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						l1.brisanjeELementa(b);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}
					s = s / 3;
					d[5 * k + 2] = s;
					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						l1.pretraga(b);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}
					s = s / 3;
					d[5 * k + 3] = s;
					pc.start();
					l1 = unija(l1, l2);
					pc.stop();
					s = pc.elapsedMillis();
					d[5 * k + 4] = s;
				}
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|velicina skupa|  200  |  500  | 1000  | 10000 |100000 |1000000|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|formiranje    |" << fixed << setprecision(5) << d[0] << "|" << setprecision(5) << d[5] << "|" << setprecision(5) << d[10] << "|" << setprecision(3) << d[15] << "|" << setprecision(1) << d[20] << "|" << setprecision(1) << d[25] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|umetanje      |" << setprecision(5) << d[1] << "|" << d[6] << "|" << d[11] << "|" << d[16] << "|" << d[21] << "|" << d[26] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|brisanje      |" << d[2] << "|" << d[7] << "|" << d[12] << "|" << d[17] << "|" << setprecision(5) << d[22] << "|" << setprecision(5) << d[27] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|pretraga      |" << d[3] << "|" << d[8] << "|" << d[13] << "|" << d[18] << "|" << setprecision(5) << d[23] << "|" << setprecision(5) << d[28] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|skup operacija|" << d[4] << "|" << d[9] << "|" << d[14] << "|" << d[19] << "|" << setprecision(4) << d[24] << "|" << setprecision(4) << d[29] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cin >> b;	
			}
			if (i == 2) {
				int b;
				int i, j, n;
				double d[50], s = 0, q;
				Stablo s1, s2;
				PerfCalc pc;
				for (int k = 0; k < 6; k++) {
					if (k == 0) n = 200;
					else if (k == 1)n = 500;
					else if (k == 2)n = 1000;
					else if (k == 3)n = 10000;
					else if (k == 4)n = 100000;
					else if (k == 5)n = 1000000;					
					s2.napraviStablo();
					for (j = 0; j < 3; j++) {
						s1.napraviStablo();
						pc.start();
						for (i = 0; i < n; i++) {
							b = rand()*(RAND_MAX + 1) + rand();
							node *tek = new node;
							tek->l = NULL;
							tek->r = NULL;
							tek->x = b;
							s1.unesiElement(tek);
						}
						pc.stop();
						q = pc.elapsedMillis();
						cout << q << endl;
						s = s + q;
					}
					s = s / 3;
					d[5 * k] = s;

					for (i = 0; i < n; i++) {
						b = rand()*(RAND_MAX + 1) + rand();
						node *tek = new node;
						tek->l = NULL;
						tek->r = NULL;
						tek->x = b;
						s2.unesiElement(tek);
					}

					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						node *tek = new node;
						tek->l = NULL;
						tek->r = NULL;
						tek->x = b;
						s1.unesiElement(tek);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}

					s = s / 3;
					d[5 * k + 1] = s;
					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						s1.obrisiElement(b, s1.root);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}

					s = s / 3;
					d[5 * k + 2] = s;
					s = 0;
					for (j = 0; j < 3; j++) {
						pc.start();
						b = rand()*(RAND_MAX + 1) + rand();
						s1.pronadjiElement(b);
						pc.stop();
						q = pc.elapsedMillis();
						s = s + q;
					}

					s = s / 3;
					d[5 * k + 3] = s;

					pc.start();
					s1 = unija(s1, s2);
					pc.stop();
					s = pc.elapsedMillis();
					d[5 * k + 4] = s;

				}


				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|velicina skupa|  200  |  500  | 1000  | 10000 |100000 |1000000|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|formiranje    |" << fixed << setprecision(5) << d[0] << "|" << setprecision(5) << d[5] << "|" << setprecision(5) << d[10] << "|" << setprecision(5) << d[15] << "|" << setprecision(3) << d[20] << "|" << setprecision(2) << d[25] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|umetanje      |" << setprecision(5) << d[1] << "|" << d[6] << "|" << d[11] << "|" << d[16] << "|" << d[21] << "|" << d[26] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|brisanje      |" << d[2] << "|" << d[7] << "|" << d[12] << "|" << d[17] << "|" << d[22] << "|" << d[27] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|pretraga      |" << d[3] << "|" << d[8] << "|" << d[13] << "|" << d[18] << "|" << d[23] << "|" << d[28] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cout << "|skup operacija|" << d[4] << "|" << d[9] << "|" << d[14] << "|" << d[19] << "|" << setprecision(4) << d[24] << "|" << setprecision(3) << d[29] << "|" << endl;
				cout << "+--------------+-------+-------+-------+-------+-------+-------+" << endl;
				cin >> b;
			}
		}




	}
}