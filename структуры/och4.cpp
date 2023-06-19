/*Dynamic18. Дано число D и ссылки A1 и A2 на начало и конец очереди, со-
держащей не менее двух элементов. Добавить элемент со значением D в

конец очереди и извлечь из очереди первый (начальный) элемент. Выве-
сти значение извлеченного элемента, а также ссылки на начало и конец

полученной очереди. После извлечения элемента из очереди вызвать для
него метод Dispose.*/
#include <iostream>

struct Node {
    int value;
    Node* next = nullptr;

    ~Node() { std::cout << "Disposed node with value " << value << std::endl; }
};

struct Queue {
    Node* head = nullptr;
    Node* tail = nullptr;

    void enqueue(int value) {
        Node* node = new Node{value};
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

    ~Queue() {
        while (head != nullptr) {
            Node* node = head;
            head = head->next;
            delete node;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    int removed_value = q.dequeue();
    std::cout << "Removed value: " << removed_value << std::endl;
    q.enqueue(3);
    std::cout << "Head value: " << q.head->value << std::endl;
    std::cout << "Tail value: " << q.tail->value << std::endl;
    return 0;
}