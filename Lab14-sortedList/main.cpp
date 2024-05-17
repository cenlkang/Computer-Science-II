#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef string ItemType;
struct NodeType;
typedef NodeType* NodePtr;

struct NodeType {
   ItemType data;
   NodePtr next;
};

// Declare the function "Insert" here

// Declare the function "Delete" here

// Declare the function "ReleaseList" here


bool IsPresent(NodePtr head, ItemType data);
void DisplayList(NodePtr head);
void BuildList(ifstream & myIn, NodePtr & head);

int main()
{
    ifstream myIn;
    ItemType item;
    NodePtr  head=NULL;  // the pointer points to the beginning of the list
    
    myIn.open("grocery.dat");
    assert(myIn);

    BuildList(myIn, head);
    DisplayList(head);

    cout << "Enter an item to be deleted from the list:";
    cin >> item;

    // call the function "IsPresent" to determine if the item is in the list
    // If the item is in the list, 
    //              call the function "Delete" to delete the item from the list
    //              call the function "DisplayList" to display the list after the deletion
    // else
    //     display a message "The item is not found in the list
    if (IsPresent(head, item))
    {
         Delete(head, item);
         cout << item << " deleted from the list." << endl;
         DisplayList(head);
    }
    else
         cout << "Item is not in the list." << endl;

    myIn.close();

    ReleaseList();

    return 0;
}

// Define the function "Insert" here. This function inserts a value into a list such that
// the list is always in sorted order, i.e., sorted in alphabetically ascending order






// Define the function "Delete" here. This function deletes a value from  the list 
// If the list is empty, show an appropriate message indicating that fact;
// The item to be deleted may be the first item in the list,
// Or it may occur in the middle or at the end of the list.
// If the item is not found in the list, show an appropriate message indicating that;





// Define the function "ReleaseList" here. This function releases the memory of all the nodes in the list





// function "BuildList" reads the values one by one from the datafile and calls
// the "Insert" function to insert each value into the linked list
void BuildList(ifstream & myIn, NodePtr & head)
{
    string item;

    while (myIn >> item)
    {
         Insert(head, item);
    }
}

// function "DisplayList" prints all the items in the list one by one
void DisplayList(NodePtr head)
{
    NodePtr cur;

    cur = head;
    cout << "The list of items are: ";
    while (cur != NULL) 
    {
        cout << cur->data <<  ' ';
        cur = cur->next;
    }
}

// Function "IsPresent" returns true if the item to search for is 
// in the list, otherwise it returns false
bool IsPresent(NodePtr head, ItemType item)
{
    NodePtr cur=head;
    while (cur != NULL)
    {
       if (cur->data == item)
       {
           return true;
       }
       cur = cur->next;
    }
    return false;
}
