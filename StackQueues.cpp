#include <iostream>
#include <queue>
#include <stack>
#include <cmath>


class Stack {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};


class Queue {
private:
    std::stack<int> inbox;
    std::stack<int> outbox;

public:
    void push(int x) {
        inbox.push(x);
    }

    int pop() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        int frontElement = outbox.top();
        outbox.pop();
        return frontElement;
    }

    int front() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top();
    }

    bool empty() {
        return inbox.empty() && outbox.empty();
    }
};


void towerOfHanoi(int numDisks, std::stack<int>& source, std::stack<int>& aux, std::stack<int>& destination) {
    int totalMoves = pow(2, numDisks) - 1;

    if (numDisks % 2 == 0) {
        std::swap(aux, destination);
    }

    for (int i = 1; i <= totalMoves; ++i) {
        if (i % 3 == 1) {
            if (!source.empty() && (destination.empty() || source.top() < destination.top())) {
                destination.push(source.top());
                source.pop();
            }
            else {
                source.push(destination.top());
                destination.pop();
            }
        }
        else if (i % 3 == 2) {
            if (!source.empty() && (aux.empty() || source.top() < aux.top())) {
                aux.push(source.top());
                source.pop();
            }
            else {
                source.push(aux.top());
                aux.pop();
            }
        }
        else {
            if (!aux.empty() && (destination.empty() || aux.top() < destination.top())) {
                destination.push(aux.top());
                aux.pop();
            }
            else {
                aux.push(destination.top());
                destination.pop();
            }
        }
    }
}

int main() {

}

