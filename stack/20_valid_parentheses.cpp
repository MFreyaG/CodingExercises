#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node* next;

        Node(char data): data(data), next(nullptr) {}
};

class Stack{
    public:
        Node* top;

        Stack(): top(nullptr) {}

        bool isEmpty(){
            if(top == nullptr)
                return true;

            return false;
        }

        void insert(char data){
            Node* new_node = new Node(data);
            if(top == nullptr){
                top = new_node;
            } else {
                new_node->next = top;
                top = new_node;
            }
        }

        void pop(){
            if(top != nullptr){
                if(top->next == nullptr){
                    top = nullptr;
                } else {
                    top = top->next;
                }
            }
        }

        Node* get_top(){
            return this->top;
        }
};

bool validateMatch(char stack_char, char next_char){
    if(stack_char == '(' && next_char == ')')
        return true;
    else if(stack_char == '{' && next_char == '}')
        return true;
    else if(stack_char == '[' && next_char == ']')
        return true;
    else
        return false;
}

bool isValid(string s){
    Stack st;
    for(int i = 0; i < s.size(); i++){
        if(st.isEmpty())
            st.insert(s[i]);
        else
            if(validateMatch(st.get_top()->data, s[i]))
                st.pop();
            else
                st.insert(s[i]);
    }

    return st.isEmpty();
}

int main(){
    string s = "([)]";

    cout << isValid(s) << endl;

    return 0;
}