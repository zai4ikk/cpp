/*Dynamic14. Дан набор из 10 чисел. Создать очередь, содержащую данные
числа в указанном порядке (первое число будет размещаться в начале
очереди, последнее — в конце), и вывести ссылки A1 и A2 на начало и
конец очереди.*/

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
    IntQueue() {
        front = nullptr;
        rear = nullptr;
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
    for (int i = 0; i < 10; i++) {
        int num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        queue.Enqueue(num);
    }
    queue.Put();
    return 0;
}