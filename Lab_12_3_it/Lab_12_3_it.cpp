#include <iostream>
using namespace std;

struct Elem
{
    int data;
    Elem* prev;
    Elem* next;
};

class DoublyLinkedList
{
    private:
        Elem* head;
        Elem* tail;

    public:
        DoublyLinkedList()
        {
            head = NULL;
            tail = NULL;
        }

    void add(int val)
    {
        Elem* new_elem = new Elem;
        new_elem->data = val;
        new_elem->prev = tail;
        new_elem->next = NULL;

        if (head == NULL)
        {
            head = new_elem;
            tail = new_elem;
        }
        else
        {
            tail->next = new_elem;
            tail = new_elem;
        }
    }

    void printList()
    {
        Elem* current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void duplicateWithValue(int val)
    {
        Elem* current = head;
        while (current != NULL)
        {
            if (current->data == val)
            {
                Elem* new_elem = new Elem;
                new_elem->data = val;
                new_elem->prev = current;
                new_elem->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = new_elem;
                }
                else
                {
                    tail = new_elem;
                }
                current->next = new_elem;
                current = new_elem->next;
            }
            else
            {
                current = current->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(1);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(1);

    cout << "Початковий список:" << endl;
    list.printList();

    list.duplicateWithValue(1);
    list.duplicateWithValue(2);
    list.duplicateWithValue(3);
    list.duplicateWithValue(4);
    list.duplicateWithValue(5);
    list.duplicateWithValue(6);

    cout << "Список після дублювання кожного елементу списку:" << endl;
    list.printList();

    return 0;
}

