/************************************************************************************
 * InsertCommas.hpp
 * 
 * What it is:      Creates a linked list queue
 *                  that holds chars. This is 
 *                  intended to hold numbers
 *                  then insert commas in the correct 
 *                  positions for currency in North
 *                  America
 * 
 * Author:          Jered Stevens
 * Date:            06/09/2020
 ************************************************************************************/

#include <iostream>

using namespace std;

/*****************************************************************************************
 * Node
 * 
 * Holds a char, keeps track of its position in the queue and points to the next node and prev node
 * 
 * Can be passed a character to store.
 ******************************************************************************************/

struct Node{
    Node* next;
    Node* prev;
    int position;
    char data;
    Node(){
        next = NULL;
        position = 0;
        data = '0';
    }
    Node(char d){
        next = NULL;
        prev = NULL;
        position = 0;
        data = d;
    }
};

/**********************************************************************************************
 * ListQueue
 * 
 * Holds our nodes and connects them in a linked list.
 * 
 **********************************************************************************************/

class ListQueue{
    private:
        Node* front;
        Node* rear;
        int size;
    public:
        ListQueue(){
            front = nullptr;
            rear = nullptr;
            size = 0;
        }

/********************************************************************
 * function:        push()
 * 
 * Params:          char x
 * 
 * Whats it do?     pushes one char at a time into
 *                  a list queue. Excludes periods ('.')
 ********************************************************************/

        void push(char x){
            if (!front){
                                                //cout << "Front Created\n";
                                                
                rear = front = new Node(x);
                size = rear->position = 1;
                                                //cout <<"Node "<< front->data << " created" << endl;
            }else if (x == '.'){}
            else{
                
                Node* temp = rear;
                rear->next = new Node(x);
                                                //cout << "Node " << rear->next->data << " created\n";                                 
                rear = rear->next;
                rear->prev = temp;
                size++;
                rear->position = size;
            }
        }

/********************************************************************
 * function:        print()
 * 
 * Params:          none
 *
 * Whats it do?     prints contents of list in US currency
 *                  format with commas in correct places
 *                  and a decimal for cents.
 ********************************************************************/
        void print(){ 
            Node* current = front;
            cout << "$";
            while(current->next->next != nullptr){
                                                //cout << " position is: " << current->position << endl;
                cout << current->data;
                addCommas(current);
                current = current->next;
            }
            //cout << endl << "Size is: " << size;
        };

/********************************************************************
 * function:        addCommas(Node*)
 * 
 * Params:          Node* current
 * 
 * Whats it do?     Adds commas to a number to be printed
 *                  in the correct US currency format
 ********************************************************************/

        void addCommas(Node* current){
            //if its bigger than 5 digits (including cents but not commas or decimal) it will need a comma
            if(size >= 6){
                //cout << "\nin Add Commas()\n";
                if (getSize() % 3 == 0){
                    if((current->position - 1) % 3 == 0  && current->next->next->next != nullptr){
                        cout << ",";
                    }                    
                }else if((getSize() - 1) % 3 == 0){
                    if((current->position - 2) % 3 == 0  && current->next->next->next != nullptr){
                        cout << ",";
                    }
                }else if((getSize() - 2) % 3 == 0){
                    if((current->position - 3) % 3 == 0  && current->next->next->next != nullptr){
                        cout << ",";
                    }
                }else{
                    cout << "error code %3210\n";
                }
            }if(current->next->next->next == nullptr){
                cout<<"."<<current->next->data << current ->next->next->data;
            };
        }

/********************************************************************
 * function:        getSize()
 * 
 * Params:          none
 * 
 * Whats it do?     returns size
 ********************************************************************/

        int getSize(){
            return size;
        }



};
    

//          For Testing Use
// int main(){
//     ListQueue list;
//     list.push('1');
//     list.push('2');
//     list.push('3');
//     list.push('4');
//     list.push('5');
//     list.push('6');
//     list.push('7');
//     list.push('.');
//     list.push('2');
//     list.push('1');
//     list.print();
// }