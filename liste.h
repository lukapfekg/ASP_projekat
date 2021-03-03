#include <iostream>
using namespace std;
struct nodel {
	int x;
	int br;
	nodel *next;
};

class Lista {

private:


public:
	int broj = 0;
	int br = 2;
	nodel *head, *mid;

	void napraviListu() {
		head = NULL;
		mid = NULL;
		broj = 0;
	}

	void izbrisiListu() {
		nodel *q = head->next, *temp;
		while (q != head) {
			temp = q;
			q = q->next;
			free(temp);
		}
		free(q);
	}

	void ipsisiElemente() {
		if (head == NULL) cout << "Prazna lista" << endl;
		else {
			nodel *temp = head->next;
			while (temp != head) {
				cout << temp->x << "  ";
				temp = temp->next;
			}
			cout << head->x << "  " << endl;
		}
	}

	void pretraga(int a) {
		nodel *tek = head->next;
		int  j = 0;
		if (head->x == a) {
			cout << "postoji element" << endl;
		}
		else if (head->x < a) cout << "element ne postoji" << endl;
		else {
			while (tek != head && j == 0) {
				if (tek->x == a) {
					cout << "postoji element" << endl;
					j = 1;
				}
				else if (tek->x < a) break;
				tek = tek->next;
			}
			if (j == 0) cout << "element ne postoji" << endl;
		}

	}

	void brisanjeELementa(int a) {
		nodel *q = head->next;
		nodel *p = head;
		int b;
		b = head->br;
		while (q != head) {
			if (q->x == a) {
				p->next = q->next;
				q->next = NULL;
				broj--;
				break;
			}
			else if (q->x > a) break;
			q = q->next;
			p = p->next;
		}
		if (q == head && q->x == a) {
			p->next = q->next;
			q->next = NULL;
			head = p;
			broj--;
		}
	}

	void brisanjeOpsega(int a, int b) {
		nodel *q, *p, *t = NULL;
		int i = 0, x;
		p = head;
		q = head->next;
		x = head->br;
		if (a > b) {
			int t = b;
			b = a;
			a = t;
		}
		while (q != head) {
			if (q->x >= a && q->x <= b) {
				p->next = q->next;
				q->next = NULL;
				free(q);
				q = p->next;
				i = 1;
				broj--;
			}
			else {
				if (i == 1) break;
				q = q->next;
				p = p->next;
			}
		}
		if (q->x >= a && q->x <= b) {
			if (p == head) {
				head = NULL;
				free(q);
			}
			else {
				p->next = q->next;
				q->next = NULL;
				head = p;
				broj--;
			}
		}
	}

	int brojElemenata() {
		int l;
		if (head == NULL) cout << "prazan skup" << endl;
		else cout << "broj elemenata u skupu " << broj + 1 << endl;
		l = broj + 1;
		return l;
	}

	void unesiElement(int a) {
		nodel *temp = new nodel;
		nodel *q = NULL, *t = head;
		nodel *p = head;
		int j = br;
		temp->x = a;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			head->next = head;
			mid = head;
		}
		else if (head == mid) {
			if (a > head->x) {
				br++;
				temp->next = head->next;
				head->next = temp;
				head = temp;
				broj++;
			}
			else if (a < head->x) {
				br++;
				temp->next = head->next;
				head->next = temp;
				mid = temp;
				broj++;
			}
			else {
				free(temp);
			}
		}
		else {
			if (a > head->x) {
				if (j % 2 == 0) mid = mid->next;
				br++;
				temp->next = head->next;
				head->next = temp;
				head = temp;
				broj++;
			}
			else if (a == head->x) {
				free(temp);
			}
			else if (a == mid->x) free(temp);
			else {
				br = 2;
				q = head->next;
				if (a < mid->x && broj > 4) {
					p = head;
					q = head->next;
					t = mid;
				}
				else if (a > mid->x && broj > 4) {
					p = mid;
					q = mid->next;
					t = head;
				}
				while (q != t) {
					if (a == q->x) {
						temp = NULL;
						break;
					}
					else if (a > q->x) {
						p = q;
						q = q->next;
						if (q == t) {
							p->next = temp;
							temp->next = q;
							if (q == mid || p == mid) mid = temp;
							broj++;
							break;
						}
					}
					else {
						p->next = temp;
						temp->next = q;
						if (q == mid || p == mid) mid = temp;
						broj++;
						break;
					}
				}
			}
		}
	}

};

Lista unija(Lista l1, Lista l2) {
	nodel *temp1 = l1.head;
	nodel *temp2 = l2.head;
	nodel *q, *p, *r;
	int i, j, k = 0;
	i = l1.brojElemenata();
	j = l2.brojElemenata();
	if (l1.head == NULL && l2.head == NULL) return l1;
	if (l1.head != NULL && l2.head == NULL) return l1;
	if (l1.head == NULL && l2.head != NULL) return l2;
	Lista t;
	if (j > i) {
		t = l1;
		l1 = l2;
		l2 = t;
		temp1 = l1.head;
		temp2 = l2.head;
	}
	r = temp2->next;
	p = temp1;
	q = temp1->next;
	while (r != temp2) {
		temp2->next = r->next;
		r->next = NULL;
		if (r->x > l1.head->x) {
			l1.unesiElement(r->x);
			free(r);
			r = temp2->next;
			l1.broj++;
		}
		else if (r->x < q->x) {
			p->next = r;
			r->next = q;
			p = r;
			r = temp2->next;
			l1.broj++;
		}
		else if (r->x == q->x) {
			free(r);
			r = temp2->next;
		}
		else if (r->x > q->x) {
			while (q->x < r->x) {
				p = q;
				q = q->next;
			}
			if (q->x == r->x) {
				free(r);
				r = temp2->next;
			}
			else if (q->x > r->x) {
				p->next = r;
				r->next = q;
				p = r;
				r = temp2->next;
				l1.broj++;
			}
		}
		if (r == temp2) {
			if (r->x > l1.head->x) {
				l1.unesiElement(r->x);
				free(r);
				r = temp2->next;
				l1.broj++;
			}
			else if (r->x < q->x) {
				p->next = r;
				r->next = q;
				p = r;
				l1.broj++;
			}
			else if (r->x == q->x) 	free(r);

			else if (r->x > q->x) {
				while (q->x < r->x) {
					p = q;
					q = q->next;
				}
				if (q->x == r->x)	free(r);


				else if (q->x > r->x) {
					p->next = r;
					r->next = q;
					p = r;
					l1.broj++;
				}
			}

			break;
		}
	}
	return l1;
}