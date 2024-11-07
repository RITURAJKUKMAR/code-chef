#include <bits/stdc++.h>
#include <deque>

using namespace std;
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, data;
        cin >> n;
        char str[n];
        deque<int> myDequestr;
        deque<int> myDeque;
        for(int i=0;i<n;i++)
            cin>>str[i];
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                myDequestr.push_back(0);
            else if (str[i] == '1')
                myDequestr.push_back(1);
        }
        while (!myDequestr.empty())
        {
            if (myDequestr.front() == 1)
                myDeque.push_back(myDequestr.front());
            else
                myDeque.push_front(myDequestr.front());
            myDequestr.pop_front();

            if (myDequestr.back() == 1)
                myDeque.push_front(myDequestr.back());
            else
                myDeque.push_back(myDequestr.back());

            myDequestr.pop_back();
        }
        while (!myDeque.empty())
        {
            cout << myDeque.front();
            myDeque.pop_front();
        }
        cout << endl;
    }
    return 0;
}