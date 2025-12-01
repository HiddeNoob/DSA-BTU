#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Boş stack oluştur
    stack<int> s;
    
    // Push: üste ekle
    cout << "\nPush:" << endl;
    s.push(10);
    cout << "  s.push(10)" << endl;
    s.push(20);
    cout << "  s.push(20)" << endl;
    s.push(30);
    cout << "  s.push(30)" << endl;
    
    cout << "  size: " << s.size() << endl;
    
    // Peek: en üsttekine bak (top)
    cout << "\nPeek: s.top() = " << s.top() << endl;
    
    // Pop: en üsttekini çıkar (LIFO)
    cout << "\nPop (LIFO):" << endl;
    cout << "  s.top() = " << s.top() << ", s.pop()" << endl;
    s.pop();
    cout << "  s.top() = " << s.top() << ", s.pop()" << endl;
    s.pop();
    cout << "  s.top() = " << s.top() << ", s.pop()" << endl;
    s.pop();
    
    cout << "\nBoş mu? " << (s.empty() ? "Evet" : "Hayır") << endl;
    
    return 0;
}
