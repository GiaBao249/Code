#include <bits/stdc++.h>

std::queue<int> q;

void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int pop()
{
    int tmp = q.front();
    q.pop();
    return tmp;
}

int top()
{
    return q.front();
}

bool empty()
{
    return q.empty();
}

int main()
{
}