#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int coefficient, exponent;
    node *next;
    node(int coef, int expo) {
        coefficient = coef;
        exponent = expo;
        next = NULL;
    }
};

class polynomial {
    public:
        node *head;
        node *tail;
        polynomial() {
            head = tail = NULL;
        }
    void insert(int coef, int expo) {
        node *temp = new node(coef, expo);
        if (head == NULL) {
        head = tail = temp;
        }
        else {
            node *fence = head;
            node *before_fence = NULL;
            while (fence != NULL && expo < fence->exponent) {
                before_fence = fence;
                fence = fence->next;
            }
            if(fence == NULL) {
                tail->next = temp;
                tail = temp;
            }
            else if(fence == head) {
                temp->next = head;
                head = temp;
            }
            else{
                before_fence->next = temp;
                temp->next = fence;
            }
        }
    }
    void display() {
        node *current = head;
        bool isFirstTerm = true;
        while (current != NULL) {
            if (!isFirstTerm) {
                cout << " + ";
            }
            isFirstTerm = false;
            if (current->coefficient != 1 || current->exponent == 0) {
                cout << current->coefficient;
            }
            if (current->exponent > 0) {
                cout << "x";
            }
            if (current->exponent > 1) {
                cout << "^" << current->exponent;
            }
            current = current->next;
        }
        cout << endl;
    }
    polynomial add(polynomial poly2) {
        polynomial result;
        node *curr1 = head;
        node *curr2 = poly2.head;

        while (curr1 != NULL && curr2 != NULL) {
            if (curr1->exponent > curr2->exponent) {
                result.insert(curr1->coefficient, curr1->exponent);
                curr1 = curr1->next;
            }
            else if (curr1->exponent < curr2->exponent) {
                result.insert(curr2->coefficient, curr2->exponent);
                curr2 = curr2->next;
            }
            else {
                int coef = curr1->coefficient + curr2->coefficient;
                if (coef != 0) {
                    result.insert(coef, curr1->exponent);
                }
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }

        while (curr1 != NULL) {
            result.insert(curr1->coefficient, curr1->exponent);
            curr1 = curr1->next;
        }

        while (curr2 != NULL) {
            result.insert(curr2->coefficient, curr2->exponent);
            curr2 = curr2->next;
        }

        return result;
    }
    polynomial multiply(polynomial poly2) {
        polynomial result;
        node *curr1 = head;

        while (curr1 != NULL) {
            node *curr2 = poly2.head;
            while (curr2 != NULL) {
                int coef = curr1->coefficient * curr2->coefficient;
                int expo = curr1->exponent + curr2->exponent;
                result.insert(coef, expo);
                curr2 = curr2->next;
            }
            curr1 = curr1->next;
        }
        return result;
    }
};

int main() {
    polynomial equation1, equation2;
    equation1.insert(8, 3);
    equation1.insert(7, 5);
    equation1.insert(10, 0);
    equation1.insert(3, 2);

    equation2.insert(4, 4);
    equation2.insert(2, 2);
    equation2.insert(1, 1);
    equation2.insert(2, 0);

    polynomial sum = equation1.add(equation2);
    cout << "Sum: ";
    sum.display();
    polynomial product = equation1.multiply(equation2);
    cout << "Product: ";
    product.display();

    return 0;
}