#include <iostream>
#include <deque>

int main() {
    // Declaration of deque
    std::deque<int> myDeque;

    // Adding elements to the front and rear of the deque
    myDeque.push_front(3);
    myDeque.push_back(2);
    myDeque.push_front(1);

    // Displaying the elements of the deque
    std::cout << "Deque: ";
    for (int element : myDeque) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Removing elements from the front and rear of the deque
    int frontElement = myDeque.front();
    int rearElement = myDeque.back();
    myDeque.pop_front();
    myDeque.pop_back();

    // Displaying the elements after removal
    std::cout << "Removed from front: " << frontElement << std::endl;
    std::cout << "Removed from rear: " << rearElement << std::endl;

    // Displaying the updated deque
    std::cout << "Updated Deque: ";
    for (int element : myDeque) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
