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

        void addCommas(Node* current){
            //if its bigger than 5 digits (including cents but not commas or decimal) it will need a comma
            if(size >= 6){
                //cout << "\nin Add Commas\n";
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