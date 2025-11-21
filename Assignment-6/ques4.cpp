#include <iostream>
using namespace std;

struct DChar {
    char ch;
    DChar* prev;
    DChar* next;
    DChar(char c): ch(c), prev(nullptr), next(nullptr) {}
};

DChar* buildDoublyChars(char arr[], int n) {
    if (n == 0) return nullptr;
    DChar* head = new DChar(arr[0]);
    DChar* tail = head;
    for (int i = 1; i < n; ++i) {
        DChar* node = new DChar(arr[i]);
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    return head;
}

bool isPalindrome(DChar* head) {
    if (!head) return true;
    DChar* tail = head;
    
    while (tail->next) tail = tail->next;

    DChar* l = head;
    DChar* r = tail;
    while (l != r && l->prev != r) { 
        if (l->ch != r->ch) return false;
        l = l->next;
        r = r->prev;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    char *arr = new char[n];
    cout << "Enter characters (space separated):\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    DChar* head = buildDoublyChars(arr, n);
    bool ok = isPalindrome(head);
    cout << (ok ? "True" : "False") << "\n";

    delete [] arr;
    return 0;
}
