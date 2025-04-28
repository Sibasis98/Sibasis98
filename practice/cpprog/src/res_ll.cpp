#include <iostream>

using namespace std;

struct Node_t
{
  int data;
  struct Node_t *next;
};

Node_t *reverse_node(Node_t *head)
{
  Node_t *curr = head;
  Node_t *next = nullptr;
  Node_t *prev = nullptr;

  next = head->next;
  head->next = nullptr;
  prev = head;
  while (next)
  {
    curr = next;
    next = next->next;
    curr->next = prev;
    prev = curr;
  }
  return curr;
}

Node_t *insert_node(int data)
{
  Node_t *tmp = new Node_t;
  tmp->data = data;
  tmp->next = nullptr;

  return tmp;
}

void print_node(Node_t *head)
{
  while(head)
  {
    cout << head->data << endl;
    head = head->next;
  }
}

Node_t *sort_node(Node_t *head)
{
  Node_t *curr_0 = head;
  Node_t *curr_1 = nullptr;
  Node_t *prev_0 = nullptr;
  Node_t *prev_1 = nullptr;
  Node_t *tmp = nullptr;
  int set_fst_0 = 0, set_fst_1 = 0;

  if (head == nullptr)
    return head;
  else if (head->next == nullptr)
    return head;

  while (head)
  {
    if (head->data == 0)
    {
      if (!set_fst_0)
      {
        if (curr_0 != head)
          curr_0 = head;
        set_fst_0 = 1;
      }

      tmp = head->next;
      if (prev_0)
      {
        prev_0->next = head;
        prev_0 = head;
      }
      else
        prev_0 = head;

      if (prev_1)
        prev_1->next = tmp;
      head = tmp;
    }
    else
    {
      if (!set_fst_1)
      {
        curr_1 = head;
        set_fst_1 = 1;
      }

      prev_1 = head;
      head = head->next;
    }
  }

  if ((prev_0) && (prev_0->next != curr_1))
    prev_0->next = curr_1;

  return curr_0;
}


int main()
{
  Node_t *head;

  head = insert_node(1);
  head->next = insert_node(0);
  head->next->next = insert_node(1);
  head->next->next->next = insert_node(0);

  print_node(head);
  head = reverse_node(head);
  print_node(head);

  cout <<"---------------"<< endl;
  head = sort_node(head);
  print_node(head);
  return 0;
}
