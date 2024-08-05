#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    cout << q.front(); // 2
    q.pop();
    cout << q.front(); // 3
    q.pop();
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.front(); // 4
    q.pop();
    cout << q.front(); // 5
    q.pop();
    cout << q.front(); // 6
    q.pop();
}