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
 * PURPOSE: 
 * PARAMETERS:
 * RETURN VALUE:
*/
Node* CIS14::addLists(Node* l1, Node* l2) {
    // Get the length of each list
    const int list1Length = getListLength(l1);
    const int list2Length = getListLength(l2);

    // Initialize a variable for the max size that the sum can be. This is whichever linked list is longer + 1 since there could be a carry that increases the digit count
    const int maxSumSize = (list1Length >= list2Length) ? (list1Length + 1) : (list2Length + 1);

    // int sums[maxSumSize] = {}; // Initialize array to be all zeroes
    
    // Initialize a carry variable for sums that have a tens value that needs to be carried
    int carry = 0;

    // cout << "Returned: " << getNodeValue(l1, 0) << endl;

    // Create a temporary list for holding the sum value in reverse order
    Node tempList(0);
    Node* currentTempPos = &tempList;

    for(int i = (maxSumSize - 1); i >= 0; i--)
    {
        int digitPositionFromEnd = (maxSumSize - 1) - i;
        // cout << "pos: " << digitPositionFromEnd << endl;

        // Initialize numbers to add as 0
        int num1 = 0;
        int num2 = 0;


        if(digitPositionFromEnd < list1Length)
        {
            num1 = getNodeValue(l1,digitPositionFromEnd);
        }

        if(digitPositionFromEnd < list2Length)
        {
            num2 = getNodeValue(l2,digitPositionFromEnd);
        }

        // cout << "test " << sums[i] << endl;
        int sum = carry + num1 + num2;
        // cout << "carry: " << carry << " | num1: " << num1 << " | num2: " << num2 << " | sum: " << sum % 10 << endl; 
        carry = sum/10;
        sum = sum % 10;
        cout << "adding " << sum << " to list, after " << currentTempPos->val << endl;
        currentTempPos->next = new Node(sum);
        currentTempPos = currentTempPos->next;
    }

    Node answerList(0);
    Node* current = &answerList;

    for(int i = (maxSumSize - 1); i >= 0; i--)
    {
        int digitPositionFromEnd = (maxSumSize - 1) - i;
        cout << "digitPositionFromEnd: " << digitPositionFromEnd << endl;
        int num = getNodeValue(&tempList,digitPositionFromEnd);
        cout << "value: " << num << endl;

        if(digitPositionFromEnd == 0 && num == 0)
        {
            continue;
        }
        else
        {
            current->next = new Node(num);
            current = current->next;
            // cout << num << endl;
        }
    }
    cout << "---" << endl;

    // // cout << endl << current->val;
    // current->next = new Node(2);
    // current = current->next;
    // // cout << endl << current->val;

    // int tempListLength = getListLength(currentTempPos);
    // cout << tempListLength << endl;
    // cout << currentTempPos->val << endl;
    // currentTempPos = currentTempPos->next;
    // cout << currentTempPos->val << endl;

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

    return 0;
}