/*Dynamic24. Даны две непустые очереди; начало и конец первой равны A1 и A2,
а второй — A3 и A4. Очереди содержат одинаковое количество элементов.

Объединить очереди в одну, в которой элементы исходных очередей че-
редуются (начиная с первого элемента первой очереди). Вывести ссылки

на начало и конец полученной очереди. Новые объекты типа Node не
создавать.*/
#include <iostream>

struct Node {
    int value;
    Node* next = nullptr;

    Node(int value) : value(value) {}
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;

    void enqueue(int value) {
        Node* node = new Node(value);
        if (tail == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int dequeue() {
        if (head == nullptr)
            throw std::logic_error("Queue is empty");

        int value = head->value;
        Node* node = head;
        head = head->next;
        delete node;
        if (head == nullptr)
            tail = nullptr;
        return value;
    }

    bool is_empty() const { return head == nullptr; }

    ~Queue() {
        while (head != nullptr) {
            Node* node = head;
            head = head->next;
            delete node;
        }
    }
};

int main() {
    Queue q1, q2;
    q1.enqueue(1);
    q1.enqueue(3);
    q1.enqueue(5);
    q2.enqueue(2);
    q2.enqueue(4);
    q2.enqueue(6);

    Queue merged_queue;
    while (!q1.is_empty() && !q2.is_empty()) {
        merged_queue.enqueue(q1.dequeue());
        merged_queue.enqueue(q2.dequeue());
    }

    std::cout << "Merged queue start: " << merged_queue.head->value << std::endl;
    std::cout << "Merged queue end: " << merged_queue.tail->value << std::endl;

    return 0;
}