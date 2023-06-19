/*Dynamic15. Дан набор из 10 чисел. Создать две очереди: первая должна со-
держать числа из исходного набора с нечетными номерами (1, 3, . . ., 9),

а вторая — с четными (2, 4, . . ., 10); порядок чисел в каждой очереди
должен совпадать с порядком чисел в исходном наборе. Вывести ссылки
на начало и конец первой, а затем второй очереди.*/

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
        cout << "Front = " << front << endl;
        cout << "Rear = " << rear << endl;
    }
};

int main() {
    IntQueue oddQueue; // очередь с нечетными номерами
    IntQueue evenQueue; // очередь с четными номерами

    for (int i = 0; i < 10; i++) {
        int num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        if ((i + 1) % 2 == 1) { // нечетное число
            oddQueue.Enqueue(num);
        }
        else { // четное число
            evenQueue.Enqueue(num);
        }
    }

    cout << "Odd queue:" << endl;
    oddQueue.Put(); // выводим ссылки на начало и конец очереди с нечетными номерами

    cout << endl;

    cout << "Even queue:" << endl;
    evenQueue.Put(); // выводим ссылки на начало и конец очереди с четными номерами

    return 0;
}