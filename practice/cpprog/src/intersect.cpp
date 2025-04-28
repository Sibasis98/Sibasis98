#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the intersection node
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* ptr1 = headA;
    ListNode* ptr2 = headB;

    while (ptr1 != ptr2) {
        // Move to the next node or switch to the other list
        ptr1 = (ptr1) ? ptr1->next : headB;
        ptr2 = (ptr2) ? ptr2->next : headA;
    }

    return ptr1;  // Intersection node or nullptr if no intersection
}

// Function to find the starting index of the full intersection
int findFullIntersectionIndex(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2) return -1;

    // Get the intersection node using two pointers
    ListNode* intersection = getIntersectionNode(list1, list2);

    if (!intersection) return -1;  // No intersection

    // Find the starting index by counting steps from the beginning
    int index = 0;
    ListNode* temp = list1;
    while (temp != intersection) {
        temp = temp->next;
        index++;
    }

    return index;  // Return the starting index
}

// Helper function to create linked lists
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr1[] = {1, 3, 4, 6, 3, 4, 5, 7};  
    int arr2[] = {3, 4, 5};  

    // Create linked lists
    ListNode* list1 = createList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    ListNode* list2 = createList(arr2, sizeof(arr2) / sizeof(arr2[0]));

    // Print the lists
    cout << "List 1: "; printList(list1);
    cout << "List 2: "; printList(list2);

    // Find the starting index of full intersection
    int index = findFullIntersectionIndex(list1, list2);

    if (index != -1) {
        cout << "\n✅ Full intersection starts at index: " << index << endl;
    } else {
        cout << "\n❌ No full intersection found." << endl;
    }

    return 0;
}
