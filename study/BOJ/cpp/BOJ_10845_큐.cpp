//#include <iostream>
#include "bits/stdc++.h"

std::stack<int> st;

class Queue
{
private:
    int arr[10002];
    int head, rear;
public: 
    Queue() : head{ 0 }, rear{ 0 } {}

    void push(int val) {
        arr[rear++] = val;
    }

    void pop() {
        if (rear - head == 0)
            std::cout << -1 << std::endl;
        else
            std::cout << arr[head++] << std::endl;
    }

    void size() {
        std::cout << rear - head << std::endl;
    }

    void empty() {
        if (head == rear) std::cout << 1 << std::endl;
        else std::cout << 0 << std::endl;
    }

    void front() {
        if (rear - head == 0)
            std::cout << -1 << std::endl;
        else
            std::cout << arr[head] << std::endl;
    }

    void back() {
        if (rear - head == 0)
            std::cout << -1 << std::endl;
        else
            std::cout << arr[rear - 1] << std::endl;
    }
};

int main(void)
{
    Queue q;

    int n, val;
    std::string order;
    std::cin >> n;
    while(n--)
    {
        std::cin >> order;
        if (order == "push") {
            std::cin >> val;
            q.push(val);
        }
        else if (order == "pop") {
            q.pop();
        }
        else if (order == "size") {
            q.size();
        }
        else if (order == "empty") {
            q.empty();
        }
        else if (order == "front") {
            q.front();
        }
        else if (order == "back") {
            q.back();
        }
    }
    return 0;
}