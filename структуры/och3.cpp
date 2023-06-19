/*Dynamic17. Дано число D и ссылки A1 и A2 на начало и конец очереди (если

очередь является пустой, то A1 = A2 = null). Добавить элемент со значе-
нием D в конец очереди и вывести ссылки на начало и конец полученной

очереди.*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class IntQueue {
private:
    Node* front;
    Node* rear;

public:
    IntQueue(Node* aFront = nullptr, Node* aRear = nullptr) {
        front = aFront;
        rear = aRear;
    }

    void Enqueue(int D) {
        Node* temp = new Node;
        temp->data = D;
        temp->next = nullptr;
        if (front == nullptr) {
            front = temp;
            rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    void Put() {
        cout << "A1 = " << front << endl;
        cout << "A2 = " << rear << endl;
    }
};

int main() {
    IntQueue queue;
    Node* A1 = nullptr;
    Node* A2 = nullptr;
    int D;

    cout << "Enter a number: ";
    cin >> D;

    queue = IntQueue(A1, A2); // создаем пустую очередь

    queue.Enqueue(D); // добавляем элемент в конец очереди
    queue.Put(); // выводим ссылки на начало и конец очереди

    return 0;
}

