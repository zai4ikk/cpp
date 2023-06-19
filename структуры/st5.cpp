/*Dynamic11◦

. Дана вершина A1 стека (если стек пуст, то A1 = null). Также дано
число N (> 0) и набор из N чисел. Описать класс IntStack, содержащий
следующие члены:
• закрытое поле top типа Node (вершина стека);
• конструктор с параметром aTop — вершиной существующего стека;

• процедура Push(D), которая добавляет в стек новый элемент со зна-
чением D (D — входной параметр целого типа);

• процедура Put (без параметров), которая выводит ссылку на поле top,
используя метод Put класса PT.

С помощью метода Push добавить в исходный стек данный набор чи-
сел (последнее число будет вершиной стека) и вывести ссылку на новую

вершину стека, используя для этого метод Put класса IntStack.*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class IntStack {
private:
    Node* top;

public:
    IntStack(Node* aTop = nullptr) {
        top = aTop;
    }

    void Push(int D) {
        Node* temp = new Node;
        temp->data = D;
        temp->next = top;
        top = temp;
    }

    void Put() {
        cout << "top = " << top << endl;
    }
};

int main() {
    IntStack stack;
    Node* A1 = nullptr;
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        stack.Push(num);
    }
    stack.Put();
    return 0;
}