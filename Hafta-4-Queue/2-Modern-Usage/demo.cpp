#include <queue>

using namespace std;

int main() {
    queue<int> q;
    
    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);
    
    // Dequeue
    q.front();
    q.pop();
    q.front();
    q.pop();
    
    return 0;
}
