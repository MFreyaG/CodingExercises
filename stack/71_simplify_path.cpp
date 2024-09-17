#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
    public:
        string token;
        Node* next;

        Node(string token): token(token), next(nullptr) {}
};

class Stack{
    public:
        Node* top;

        Stack(): top(nullptr) {}

        void insert(string token){
            Node* new_node = new Node(token);
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
};

vector<string> tokenize(string path){
    vector<string> tokens;
    
    string curr = "";
    for(int i = 1; i < path.size(); i++){
        if(path[i] != '/'){
            curr += path[i];
        } else {
            if(curr.size() != 0){
                tokens.push_back(curr);
                curr = "";
            }
        }
    }

    return tokens;
}

string simplifyPath(string path) {
    if(path[path.size()-1] != '/')
        path += '/';

    vector<string> tokens = tokenize(path);
    vector<string> result_tokens;
    
    Stack st;
    int command = 0;
    for(int i = tokens.size() - 1; i >= 0; i--){

        if(tokens[i] == ".."){
            command += 1;
        }else{
            if(command == 0 && tokens[i] != "."){
                result_tokens.push_back(tokens[i]);
            }

            if(command != 0 && tokens[i] != ".")
                command -= 1;
        }
    }

    string final_path = "/";
    for(int i = result_tokens.size() - 1; i >= 0; i--){
        final_path = final_path + result_tokens[i] + "/";
    }

    if(final_path != "/"){
        final_path.pop_back();
    }

    return final_path;
}

int main(){
    string path1 = "/home/";
    string path2 = "/home//foo/";
    string path3 = "/home/user/Documents/../Pictures";
    string path4 = "/.../a/../b/c/../d/./";
    string path5 = "/../";
    string path6 = "/a/./b/../../c/";

    cout << simplifyPath(path1) << endl;
    cout << simplifyPath(path2) << endl;
    cout << simplifyPath(path3) << endl;
    cout << simplifyPath(path4) << endl;
    cout << simplifyPath(path5) << endl;
    cout << simplifyPath(path6) << endl;

    return 0;
}