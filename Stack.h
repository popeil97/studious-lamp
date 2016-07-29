/* 
 * File:   Stack.h
 * Author: fox2eagle1
 *
 * Created on July 6, 2016, 10:59 PM
 */

#ifndef STACK_H
#define	STACK_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cmath>

using namespace std;

struct Node {
    double value;
    Node *down;
};

class Queue {
private:
    Node *top = nullptr;
    Node *iterator = nullptr;
public:
    Node* createNode(int num) {
        Node *node = new Node;
        node->value = num;
        return node;
    }
    
    void push(int num) {
        if(top == nullptr) {
            top = createNode(num);
            iterator = top;
        }
        
        else {
            iterator->down = createNode(num);
            iterator = iterator->down;
        }
    }
    
    void pop() {
        Node *temp = top;
        top = top->down;
        
        delete temp;
    }
    
    double peek() {
        return top->value;
    }
    
    void printQueue() {
        Node *temp = top;
        while(temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->down;
        }
        
        cout << endl;
    }
};

class Stack {

private:
    Node *top = nullptr;
    bool empty = false;
   
public:
    void push(int num) {
        if(top == nullptr) {
            top = createNode(num);
        }
        
        else {
            Node *temp = top;
            top = createNode(num);
            top->down = temp;
        }
    }
    
    void pop() {
        
        if(top->down == nullptr) {
            cout << "Stack is Empty" << endl;
            empty = true;
        }
        
        else {
            top = top->down;
        }
    }
    
    double getTop() {
        return top->value;
    }
    
    bool isEmpty() {
        if(empty) {
            return true;
        }
        
        else {
            return false;
        }
    }
    
    Node* createNode(int num) {
        Node *node = new Node;
        node->value = num;
        node->down = nullptr;
        return node;
    }
    
    void printStack() {
        Node *iterator = top;
        
        while(iterator != nullptr) {
            cout << iterator->value << " ";
            iterator = iterator->down;
        }
        
        cout << endl;
    }
    
    
};




#endif	/* STACK_H */

