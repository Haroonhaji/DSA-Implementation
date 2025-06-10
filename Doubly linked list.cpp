#include <iostream>
#include <vector>
using namespace std;

struct Node_d {
    Node_d *next;
    int data;
    Node_d *prev;
};

void create(int A[], int n, Node_d *&p) {
    p = new Node_d{nullptr, A[0], nullptr};
    Node_d *last = p;

    for (int i = 1; i < n; ++i) {
        Node_d *t = new Node_d{nullptr, A[i], last};
        last->next = t;
        last = t;
    }
}

int count(Node_d *p) {
    int cnt = 0;
    while (p) {
        ++cnt;
        p = p->next;
    }
    return cnt;
}

void insert(Node_d *&p, int x, int position) {
    Node_d *q = new Node_d{nullptr, x, nullptr};

    if (position == 0) {
        q->next = p;
        if (p) p->prev = q;
        p = q;
    } else {
        Node_d *r = p;
        for (int i = 0; i < position - 1 && r; ++i)
            r = r->next;

        q->next = r->next;
        q->prev = r;
        if (r->next) r->next->prev = q;
        r->next = q;
    }
}

void Delete(Node_d *&p, int pos) {
    if (!p) return;
    Node_d *q = p;

    if (pos == 1) {
        p = p->next;
        if (p) p->prev = nullptr;
        delete q;
    } else {
        for (int i = 0; i < pos - 2 && q; ++i)
            q = q->next;

        Node_d *temp = q->next;
        if (!temp) return;

        q->next = temp->next;
        if (temp->next) temp->next->prev = q;
        delete temp;
    }
}

void Display(Node_d *p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverse(Node_d *&p) {
    Node_d *curr = p, *temp = nullptr;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) p = temp->prev;
}

void deleteAllOccurOfX(Node_d *&head_ref, int x) {
    Node_d *p = head_ref;
    while (p) {
        if (p->data == x) {
            Node_d *temp = p;
            if (p == head_ref) {
                head_ref = p->next;
                if (head_ref) head_ref->prev = nullptr;
                p = head_ref;
            } else {
                if (p->prev) p->prev->next = p->next;
                if (p->next) p->next->prev = p->prev;
                p = p->next;
            }
            delete temp;
        } else {
            p = p->next;
        }
    }
}

vector<pair<int, int>> findPairsWithGivenSum(Node_d *head, int target) {
    vector<pair<int, int>> arr;
    Node_d *front = head, *rear = head;

    while (rear && rear->next) rear = rear->next;

    while (front && rear && front != rear && front->prev != rear) {
        int sum = front->data + rear->data;
        if (sum == target) {
            arr.emplace_back(front->data, rear->data);
            front = front->next;
            rear = rear->prev;
        } else if (sum > target) {
            rear = rear->prev;
        } else {
            front = front->next;
        }
    }

    return arr;
}

int main() {
    int A[] = {1, 2, 1, 5, 1, 8, 9};
    Node_d *t;
    create(A, 7, t);

    cout << "Original list: ";
    Display(t);

    deleteAllOccurOfX(t, 1);
    cout << "After deleting all 1s: ";
    Display(t);

    insert(t, 99, 0);
    insert(t, 77, 3);
    cout << "After insertions: ";
    Display(t);

    Delete(t, 2);
    cout << "After deleting 2nd node: ";
    Display(t);

    reverse(t);
    cout << "After reversing: ";
    Display(t);

    auto pairs = findPairsWithGivenSum(t, 85);
    cout << "Pairs with sum 85: ";
    for (auto &pr : pairs) {
        cout << "(" << pr.first << ", " << pr.second << ") ";
    }
    cout << endl;

    return 0;
}


