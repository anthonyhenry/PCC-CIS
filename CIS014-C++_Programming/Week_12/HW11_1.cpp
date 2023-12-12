#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class CIS14
{
public:
    Node* addLists(Node*, Node*);
};
// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class
// named CIS14 with its method and the Node class you will use.
// ------------------------------------------------------------

// Optional: you may add any global function, variables here

// Function to get the length of a linked list
int getListLength(Node* list)
{
    // initialize a list length variable for the function to return
    int listLength = 0;

    // Loop through the list until the nullptr terminator
    while(list != nullptr)
    {
        // Increment the list length variable
        listLength++;
        // Move on to the next list node
        list = list->next;
    }

    // Return the final list length value
    return listLength;
}

// Function to get node values at specific positions in the linked list
int getNodeValue(Node* list, int pos)
{
    // Iterate through the list
    int currentPosition = 1;
    int positionToReturn = getListLength(list) - pos;
    while(currentPosition < positionToReturn)
    {
        // cout << "Position " << currentPosition << ": " << list->val << endl;
        list = list->next;
        currentPosition++;
    }

    // Return the value at the specified position 
    return list->val;
}


/**
 * PURPOSE: To find the sum of two positive integers that are represented in linked lists
 * PARAMETERS: The addLists method takes in two linked list pointers as arguments
 * RETURN VALUE: The addLists method returns a linked list pointer for the linked list representing the sum
*/
Node* CIS14::addLists(Node* l1, Node* l2) {
    // Get the length of each list
    const int list1Length = getListLength(l1);
    const int list2Length = getListLength(l2);

    // Initialize a variable for the max size that the sum can be. This is whichever linked list is longer + 1 since there could be a carry that increases the digit count
    const int maxSumSize = (list1Length >= list2Length) ? (list1Length + 1) : (list2Length + 1);
    
    // Initialize a carry variable for sums that have a tens value that needs to be carried
    int carry = 0;
    // Create a temporary list for holding the sum value in reverse order
    Node tempList(0);
    Node* currentTempPos = &tempList;

    // For loop to go through the lists backwards and add the node values at each position
    for(int i = (maxSumSize - 1); i >= 0; i--)
    {
        int nodePositionFromEnd = (maxSumSize - 1) - i;
        // cout << "position from end: " << nodePositionFromEnd << endl;

        // Initialize numbers to add as 0
        int num1 = 0;
        int num2 = 0;

        // Only update the numbers to add if there is enough nodes in the linked list
        if(nodePositionFromEnd < list1Length)
        {
            num1 = getNodeValue(l1,nodePositionFromEnd);
        }
        if(nodePositionFromEnd < list2Length)
        {
            num2 = getNodeValue(l2,nodePositionFromEnd);
        }
        
        // Get the sum of the two numbers
        int sum = carry + num1 + num2;
        // cout << "carry: " << carry << " | num1: " << num1 << " | num2: " << num2 << " | sum: " << sum % 10 << endl; 
        // Separate the tens and the ones place
        carry = sum/10; // tens
        sum = sum % 10; // ones
        // cout << "adding " << sum << " to list, after " << currentTempPos->val << endl;
        // Add the ones place to the temporary linked list
        currentTempPos->next = new Node(sum);
        // Move on to the next node in the list
        currentTempPos = currentTempPos->next;
    }

    // Create a list to return
    Node answerList(0);
    Node* current = &answerList;

    // Loop through the temporary list backwards
    for(int i = (maxSumSize - 1); i >= 0; i--)
    {
        int nodePositionFromEnd = (maxSumSize - 1) - i;
        int num = getNodeValue(&tempList, nodePositionFromEnd);
        // cout << "value: " << num << endl;

        // If the first position from the end is 0, skip it
        if(nodePositionFromEnd == 0 && num == 0)
        {
            continue;
        }
        // Otherwise add the number to the answer list
        else
        {
            current->next = new Node(num);
            current = current->next;
            // cout << num << endl;
        }
    }
    delete currentTempPos;
    return answerList.next;
};

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Your target method will be tested with random input such
    // as the following example; the actual test cases will vary
    // The example uses declared node instances. You may dynamically
    // allocate your nodes as well for the same effect. If so, 
    // just remember to deallocate them after use to avoid memory
    // leaks.

    // First input list: 2->3->4->8
    Node first1(2), first2(3), first3(4), first4(8);
    first1.next = &first2;
    first2.next = &first3;
    first3.next = &first4;

    // Second input list: 9->9
    Node second1(9), second2(9);
    second1.next = &second2;
    
    // Adding:
    //    2->3->4->8
    //          9->9
    // -------------
    //    2->4->4->7
    Node* ans = cis14.addLists(&first1, &second1);

    // You may use the following code to print your list
    Node* tmp = ans;
    while (tmp != nullptr)
    {
        (tmp->next != nullptr) ? 
            cout << tmp->val << "->" : 
            cout << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;

    // If your add(...) method allocated heap memory, you
    // should deallocate them here to avoid memory leaks. 
    delete ans;

    return 0;
}