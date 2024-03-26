#include <iostream>
using namespace std;
template< class t>
class DoublyLinkedList
{
private:
    struct Node
    {
        t item;
        Node *prevese,*next;
    };
    Node *head,*tail;
    int counter;
public:
    DoublyLinkedList()
    {
        head=tail=NULL;
        counter=0;
    }
    void insertFirst(t element)
    {
        Node* newNode = new Node;
        newNode->item = element;
        if (counter == 0)
        {
            head = tail = newNode;
            newNode->next = newNode->prevese = NULL;
        }
        else
        {
            newNode->next =head;
            newNode->prevese = NULL;
            head->prevese=newNode;
            head = newNode;
        }
        counter++;
    }
    void insertLast(t element)
    {
        Node* newNode = new Node;
        newNode->item = element;
        if (counter == 0)
        {
            head = tail = newNode;
            newNode->next = newNode->prevese = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prevese = tail;
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }
    void insertAtPosition(int position,t element)
    {
        Node* newNode = new Node;
        newNode->item = element;
        if (position == 0)
        {
            insertFirst(element);
        }
        else if(position==counter)
        {
            insertLast(element);
        }
        else
        {
            Node *current=head;
            for(int i=1; i<position; i++)
            {
                current=current->next;
            }
            newNode->next=current->next;
            newNode->prevese=current;
            current->next->prevese=newNode;
            current->next=newNode;
        }
        counter++;
    }
    void deleteFirst()
    {
        if(counter==0)
        {
            cout<<"Linked List is Empty can`t remove element"<<endl;
        }
        else
        {
            Node *current=head;
            head=head->next;
            head->prevese=NULL;
            current->next=current->prevese=NULL;
            delete current;
            counter--;
        }
    }
    void deleteLast()
    {
        if(counter==0)
        {
            cout<<"Linked List is Empty can`t remove element"<<endl;
        }
        else
        {
            Node *current=tail;
            tail=tail->prevese;
            tail->next=NULL;
            current->next=current->prevese=NULL;
            delete current;
            counter--;
        }
    }
    void deleteAtPosition(int position)
    {
        if(position==0)
        {
            deleteFirst();
        }
        else if(position==counter-1)
        {
            deleteLast();
        }
        else
        {
            Node *current=head;
            for(int i=0; i<position; i++)
            {
                current=current->next;
            }
            current->next->prevese=current->prevese;
            current->prevese->next=current->next;
            current->next=current->prevese=NULL;
            delete current;
            counter--;
        }
    }
    void printFirst()
    {
        Node* temp = head;
        cout<<"[";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout<<"]"<<endl;
    }

    void printLast()
    {
        Node* temp = tail;
        cout<<"[";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->prevese;
        }
        cout<<"]"<<endl;
    }

};
int main()
{
    DoublyLinkedList<string> d;
    d.insertLast("karim"); //0
    d.insertLast("ali");//1
    d.insertLast("ibrahim");//2
    d.insertLast("mahmoud");//3
    d.insertLast("mostafa");//4
    d.deleteAtPosition(2);
    d.printFirst();
    return 0;
}
