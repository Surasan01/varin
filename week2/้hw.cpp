#include <iostream>
using namespace std;
struct Node {
 int coef;
 int exp;
 Node* next;
};
void insert(Node** head, int coef, int exp) {
 Node* newNode = new Node;
 newNode->coef = coef;
 newNode->exp = exp;
 newNode->next = nullptr;
 if (*head == nullptr) {
 *head = newNode;
 return;
 }
 Node* cur = *head;
 while (cur->next != nullptr) {
 cur = cur->next;
 }
 cur->next = newNode;
}
Node* addPolynomials(Node* a, Node* b) {
 Node* res = nullptr;
 while (a != nullptr && b != nullptr) {
 if (a->exp > b->exp) {
 insert(&res, a->coef, a->exp);
 a = a->next;
 }
 else if (b->exp > a->exp) {
 insert(&res, b->coef, b->exp);
 b = b->next;
 }
 else {
 int coef = a->coef + b->coef;
 insert(&res, coef, a->exp);
 a = a->next;
 b = b->next;
 }
 }
 while (a != nullptr) {
 insert(&res, a->coef, a->exp);
 a = a->next;
 }
 while (b != nullptr) {
 insert(&res, b->coef, b->exp);
 b = b->next;
 }
 return res;
}
Node* multiplyPolynomials(Node* a, Node* b) {
 Node* res = nullptr;
 while (a != nullptr) {
 Node* cur = b;
 while (cur != nullptr) {
 int coef = a->coef * cur->coef;
 int exp = a->exp + cur->exp;
 insert(&res, coef, exp);
 cur = cur->next;
 }
 a = a->next;
 }
 return res;
}
void printPolynomial(Node* poly) {
 while (poly != nullptr) {
 cout << poly->coef << "x^" << poly->exp;
 poly = poly->next;
 if (poly != nullptr) {
 cout << " + ";
 }
 }
 cout << endl;
}
int main() {
 Node* a = nullptr;
 insert(&a, 2, 2);
 insert(&a, 1, 1);
 insert(&a, 3, 0);
 Node* b = nullptr;
 insert(&b, 3, 2);
 insert(&b, 2, 1);
 insert(&b, 1, 0);
 Node* sum = addPolynomials(a, b);
 Node* prod = multiplyPolynomials(a, b);
 cout << "a: ";
 printPolynomial(a);
 cout << "b: ";
 printPolynomial(b);
 cout << "a + b: ";
 printPolynomial(sum);
 cout << "a * b: ";
 printPolynomial(prod);
 return 0;
}