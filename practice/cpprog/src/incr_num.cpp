#include <iostream>

using namespace std;

struct Number
{
  int data;
  Number *next;

  Number(int num, Number *head)
  {
    data = num;
    next = head;
  }
};

class Number_Class
{
  public:

  Number *insert_node(int data, Number *head)
  {
    Number *tmp = new Number(data, head);
    return tmp;
  }

  Number *create_list(int num)
  {
    Number *head = nullptr;
    int data = -1;
    if (!num)
      head = new Number(num, nullptr);
    else
    {
      while(num != 0)
      {
        data = num % 10;
        num = (num - data) / 10;
        if (head == nullptr)
          head = insert_node(data, nullptr);
        else
          head = insert_node(data, head);
      }
    }

    return head;
  }

  void print_list(Number *head)
  {
    while (head)
    {
      cout << head->data;
      head = head->next;
    }

    cout << endl;
  }

  Number *update_node(Number *head)
  {
    Number *tmp = head;
    Number *prev = nullptr;

    int flag = 0;

    while (head)
    {
      if (head->data >= 10)
      {
        if (prev)
        {
          prev->data += 1;
          head->data -= 10;
          if (prev->data >= 10)
          {
            if (prev == tmp)
            {
              prev->data -= 10;
              tmp = insert_node(1, tmp);
              return tmp;
            }
            flag = 1;
          }
        }
        else
        {
          tmp = insert_node(1, tmp);
          return tmp;
        }
      }
      else if (head->next == nullptr)
      {
        head->data += 1;
        if (head->data >= 10)
          flag = 1;
      }

      if (flag)
      {
        tmp = update_node(tmp);
        break;
      }

      prev = head;
      head = head->next;
    }

    return tmp;
  }

  void del_list(Number *head)
  {
    while(head)
    {
      Number *tmp = head;
      head = head->next;
      delete tmp;
    }
  }
};

int main()
{
  int num;
  cout << "Enter the number" <<endl;
  cin >> num;

  Number_Class obj;
  Number *head = obj.create_list(num);
  //obj.print_list(head);

  head = obj.update_node(head);
  obj.print_list(head);

  obj.del_list(head);
  return 0;
}
