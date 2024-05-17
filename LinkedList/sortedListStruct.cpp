// Sorted linked list example with struct-type data
// This linked list does not use class implementation
// New values are inserted into the list such that the list is
// maintained in a sorted order

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

struct BookStruct
{
   string title;
   string author;
   float  price;
   int    year;
};
typedef BookStruct ItemType;

struct Node
{
   ItemType data;
   Node * next;
};
typedef Node * NodePtr;

void DisplayBookByAuthor(const NodePtr &head, string nameToSearch);
int BuildList(ifstream &, NodePtr &head);
void PrintList(NodePtr head);
void DestroyList(NodePtr &head);
void Delete(NodePtr & head, const ItemType & toDel);
void Insert(NodePtr & head, const ItemType & toAdd);

int main()
{
    NodePtr head;  // pointers pointing to the front and back of the list
    int     length;   // keeps track of the number of nodes in the list
    string  name;
    ifstream myIn("books.dat");
    assert(myIn);

    // initialization
    length = 0;
    head = NULL;

    // Build a list
    length = BuildList(myIn, head);

    // Display a list
    PrintList(head);

    // Delete item from a list
    //Delete(head, "Amy");
    //PrintList(head);

    // deallocate memory
    DestroyList(head);

    myIn.close();
    return 0;
}

// Insert an item "toAdd" into the list in alphabetical order
// Input: head points to the front of an existing list
//        toAdd holds the item to the added into the list
// Output: The head to the updated list is returned
void Insert(NodePtr & head, const ItemType & toAdd)
{
    NodePtr cur, prev;
    NodePtr newPtr;

    // Create a new node and put the item to be added in this new node
    newPtr = new Node;
    newPtr->data = toAdd;
    newPtr->next = NULL;

    // Determine where to insert the new node
    // If it is to be added in the front
    if (head == NULL || (head != NULL && head->data.author> toAdd.author))
    {
       newPtr->next = head;
       head = newPtr;
       return;
    }

    // If the new item is to be added in the middle or at the end of the list
    cur=prev=head;
    // Traverse to the position
    // IMPORTANT: cur pointer points to the node at "position"
    //            prev pointer points to the item at "position-1"
    prev=NULL;
    cur=head;
    while (cur != NULL && cur->data.author< toAdd.author)
    {
        prev = cur;
        cur = cur->next;
    }

    // Modify the link to add the node into the list at "position"
    prev->next = newPtr;
    newPtr->next = cur;
}

// Delete an item "toDel" from the list
// This function removes ALL the occurences of the value from the list
// Input: head points to the front of an existing list
//        toDel holds the value to be deleted from the list
// Output: The head pointing to the updated list is returned

void Delete(NodePtr & head, const ItemType & toDel)
{
     NodePtr cur, prev;

     // Determine if the list is empty or if the first node is to be deleted
     if (head != NULL && head->data.title == toDel.title)
     {
	      cur=head;
        head = head->next;
        cur->next=NULL;
        delete cur;
     }
     // Deletion from the middle or end of the list
     else if (head != NULL)
     {
        // Use two pointers to traverse down the list
        // It will traverse all the way to the end of the list
     	  cur=prev=head;
     	  while (cur != NULL)
    	   {
           // Use two pointers to traverse the list
	          //  -- cur points to the node to be deleted
           //  -- prev points to the node in the previous node
           // Remove the node by changing the link and free the memory
           if (cur->data.title == toDel.title)
           {
	            prev->next = cur->next;

              cur->next = NULL;
              delete cur;
              break;
           }
	          prev= cur;
           cur = cur->next;
        } // end while
      } // end else
}

// Display the book by author name supplied
void DisplayBookByAuthor(const NodePtr &head, string nameToSearch)
{
    NodePtr  curr;
    string name;
    // Insert new items into a list

    cout << "Enter the author name: ";
    getline(cin, name);
    while (name != "")
    {
        curr=head;
        while (curr!=NULL)
        {
           if (curr->data.author== nameToSearch)
               cout << curr->data.author<< '\t' << curr->data.title << '\t' << curr->data.year << endl;
           curr = curr->next;
        }

        cout << "Enter the author name: ";
        getline(cin, name);
    }
}

// Free the memory of all the nodes in the list
void DestroyList(NodePtr &head)
{
    NodePtr tmp;

    while (head != NULL)
    {
       cout << "Freeing one node" << endl;
       tmp=head;
       head = head->next;
       delete tmp;
    }
}


// Build a linked list
// Read names from user and add the name into the list alphabetically
// Input and Output: The pointer pointing to the front of the list
// Output: length holds the number of nodes in the list
int BuildList(ifstream & myIn, NodePtr &head)
{
    int length=0;
    string name, title;
    int year;
    float price;
    NodePtr newPtr;
    NodePtr cur, prev;
    ItemType newBook;

    while (getline(myIn, newBook.author))
    {
        getline(myIn, newBook.title);
        myIn>>newBook.year>>newBook.price;
        myIn.ignore(100, '\n');

        length++;

        // create a new node for the name
        newPtr = new Node;
        newPtr->data = newBook;  // this is an aggregated assignment, assigning all the members of a struct
        newPtr->next = NULL;

        // insert at the front of the list
        if (head == NULL || (head != NULL && newBook.author< head->data.author))
        {
           newPtr->next=head;
           head = newPtr;
        }
        else
        {
           // add the new node in the middle or at the end of the list according to alphabetical order
	          prev=NULL;
           cur=head;
           while (cur != NULL && cur->data.author< newBook.author)
           {
                prev = cur;
                cur = cur->next;
           }
           prev->next = newPtr;
           newPtr->next = cur;
        }

        PrintList(head);  // for debugging
    }

    return length;
}

// Display the list
// Print the items stored in the nodes in the list
// Input: head points to the front of the list
void PrintList(NodePtr head)
{
    NodePtr cur;

    // list traversal
    cout << "Here is the list of books:" << endl;
    cur = head;
    while (cur != NULL)
    {
	       cout << cur->data.author << "   "  << cur->data.title << endl;
         cur = cur->next;
    }
}
