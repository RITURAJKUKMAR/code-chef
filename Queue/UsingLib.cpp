#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> myQueue;
    cout<<endl<<myQueue.empty();
    myQueue.push(10);
    myQueue.push(20);
    myQueue.pop();
    myQueue.push(30);
    myQueue.push(40);
    cout<<endl<< myQueue.front();
    cout<<endl<<myQueue.back();
    int n=myQueue.size();
    cout<<endl<<n;
    cout<<endl<<myQueue.empty()<<endl;
    while(!myQueue.empty())
    {
        cout<<" "<<myQueue.front();
        myQueue.pop();
    }
    cout<<endl<<n;
    return 0;
}