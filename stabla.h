#include <iostream>
#include <stack>
using namespace std;


struct node {
	int x;
	node *l, *r;
};

struct stekNode {
	node **x;
	stekNode *next;

};

class stek {
private:

public:
	stekNode *top;
	int count;
	int maxnum = 50000;
	int stackData;

	void napraviStek() {
		top = NULL;
		count = 0;
	}

	void push(node **element) {

		if (count == maxnum) cout << "stek je pun" << endl;
		else {
			stekNode *newTop = new stekNode;
			if (top == NULL) {
				newTop->x = element;
				newTop->next = NULL;
				top = newTop;
				count++;
			}
			else {
				newTop->x = element;
				newTop->next = top;
				top = newTop;
				count++;
			}
		}
	}
	void pop()
	{
		if (top == NULL)
			cout << "nothing to pop";
		else
		{
			stekNode *old = top;
			top = top->next;
			count--;
			delete(old);
		}
	}
};

class Stablo {
private:
public:
	int broj = 0;
	node *root;

	void napraviStablo() {
		root = NULL;

	}

	void unesiElement(node *a) {
		node *temp = new node;
		node *q = root, *p = NULL;
		int i = 0;
		temp = a;
		if (a != NULL) {
			while (q != NULL) {
				p = q;
				if (a->x == q->x) {
					free(temp);
					i = 1;
					broj--;
					break;
				}
				else if (a->x < q->x) q = q->l;
				else q = q->r;
			}


			if (p == NULL) root = temp;
			else if (i == 0) {
				if (a->x < p->x) p->l = temp;
				else p->r = temp;
			}
			broj++;
		}
	}

	node *obrisiStablo(node *p_tree)
	{
		if (p_tree == NULL)
			return NULL;
		stek stack_tree;
		stack_tree.napraviStek();
		stack_tree.push(&p_tree);
		while (1)
		{
			node *p_node = *stack_tree.top->x;
			if (p_node->l)
			{
				stack_tree.push(&(p_node->l));
				continue;
			}
			if (p_node->r)
			{
				stack_tree.push(&(p_node->r));
				continue;
			}
			cout << "deleting " << p_node->x << endl;
			delete p_node;
			*stack_tree.top->x = NULL;
			stack_tree.pop();
			if (stack_tree.count == 0)
				return NULL;
		}
	}

	void obrisiElement(int a, node *nod) {
		node *temp = nod;
		node *q = nod;
		node *p = NULL;
		int i = 0;

		if (root->x == a) {
			if (root->l == NULL && root->r == NULL) {
				root = NULL;
			}
			else {
				q = nod->l;
				p = nod->r;
				free(root);
				root = p;
				unesiElement(q);
			}
		}
		else {
			while (q != NULL) {
				if (q->x > a) {
					p = q;
					q = q->l;
					i = 1;
				}
				else if (q->x < a) {
					p = q;
					q = q->r;
					i = 2;
				}
				else {
					node *r = q->r;
					node *l = q->l;
					if (i == 1) {
						if (l == NULL && r == NULL) {
							p->l = NULL;
							free(q);
							break;
						}
						else if (l != NULL && r != NULL) {
							p->l = r;
							unesiElement(l);
							free(q);
							break;
						}
						else if (l != NULL && r == NULL) {
							p->l = l;
							free(q);
							break;
						}
						else if (l == NULL && r != NULL) {
							p->l = r;
							free(q);
							break;
						}
					}
					else if (i == 2) {
						if (l == NULL && r == NULL) {
							p->r = NULL;
							free(q);
							break;
						}
						if (l != NULL && r != NULL) {
							p->r = r;
							unesiElement(l);
							free(q);
							break;
						}
						else if (l != NULL && r == NULL) {
							p->r = l;
							free(q);
							break;
						}
						else if (l == NULL && r != NULL) {
							p->r = r;
							free(q);
							break;
						}
					}
				}
			}
		}
	}

	int brojElemenata() {
		int l;
		l = broj;
		cout << "broj elemenata " << l << endl;
		return l;
	}

	void pronadjiElement(int a) {
		node *q = root;

		while (q != NULL) {
			if (q->x > a) {
				q = q->l;
				if (q == NULL) {
					cout << "ne postoji element" << endl;
					break;
				}
			}
			else if (q->x < a) {
				q = q->r;
				if (q == NULL) {
					cout << "ne postoji element" << endl;
					break;
				}
			}
			else {
				cout << "postoji element" << endl;
				break;
			}
		}

	}

	void obrisiOpseg(int a, int b) {
		node *q = root;
		if (q->x < a)
			while (q->x < a) {
				if (q->r == NULL) {
					q = q->r;
					break;
				}
				q = q->r;
			}
		if (q->x > b)
			while (q->x > b) {
				if (q->l == NULL) {
					q = q->l;
					break;
				}
				q = q->l;
			}
		if (q != NULL) {
			node *l = q->l;
			node *r = q->r;
			node *l1 = q, *r1 = q;
			int i = 0, j = 0;
			while (l != NULL) {

				if (l->x < a || l->x > b) {
					l1 = l;
					l = l->r;
					i = 1;
				}
				else if (l->x >= a && l->x <= b) {
					obrisiElement(l->x, l1);
					l = NULL;
				}
				if (l == NULL && l1->x >= a && l1->x <= b)
					l = l1->l;
				else if (l == NULL && (l1->x < a || l1->x > b))
					l = l1->r;
			}
			while (r != NULL) {


				if (r->x < a || r->x > b) {
					r1 = r;
					r = r->l;

				}
				else if (r->x >= a && r->x <= b) {
					obrisiElement(r->x, r1);
					r = NULL;
				}
				if (r == NULL && r1->x >= a && r1->x <= b)
					r = r1->r;
				else if (r == NULL && (r1->x < a || r1->x > b))
					r = r1->l;
			}
			obrisiElement(q->x, root);
		}
	}

};


void ispis(node *p) {
	stek q;
	node *tek = NULL;

	q.napraviStek();
	q.push(&p);
	if (p == NULL) cout << "nema elemenata" << endl;
	else {
		while (q.count != 0 || tek != NULL) {
			tek = *q.top->x;
			if (tek == NULL && q.top->next == NULL) break;
			if (tek) {
				q.push(&(tek->l));
			}
			else {
				q.pop();
				tek = *q.top->x;
				q.pop();
				cout << tek->x << "  ";
				q.push(&(tek->r));
			}
		}
	}
	cout << endl;
}

Stablo unija(Stablo s1, Stablo s2) {
	node *q = s1.root;
	node *p = s2.root;
	if (q == NULL && p == NULL) return s1;
	if (q != NULL && p == NULL) return s1;
	if (q == NULL && p != NULL) return s2;
	Stablo t;
	if (s1.broj < s2.broj) {
		t = s1;
		s1 = s2;
		s2 = t;
	}
	while (s2.root != NULL) {
		p = s2.root;
		s2.root = s2.root->r;
		s2.unesiElement(p->l);
		p->l = NULL;
		p->r = NULL;
		s1.unesiElement(p);
	}
	return s1;
}