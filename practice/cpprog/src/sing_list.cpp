#include <iostream>

using namespace std;

struct Employee
{
  int emp_id;
  struct Employee *next;

};

Employee *list_create(int id)
{
  Employee *tmp = new Employee;
  tmp->emp_id = id;
  tmp->next = nullptr;

  return tmp;
}

void insert_elem(Employee *head, int id)
{
  Employee *prev = nullptr;
  while (head)
  {
    prev = head;
    head = head->next;
  }
  if (prev)
    prev->next = list_create(id);
}

void insert_elem(Employee *head, int id, int idx)
{
  Employee *prev = nullptr;
  Employee *next = nullptr;
  int i = 1;
  while (head)
  {
    if (i == idx)
    {
      next = head;
      prev->next = list_create(id);
      prev->next->next = next;
      return;
    }
    prev = head;
    head = head->next;
    i++;
  }
  if (prev)
    prev->next = list_create(id);
}

void print_list(Employee *head)
{
  while (head)
  {
    cout << "Id: " << head->emp_id << endl;
    head = head->next;
  }
}

void list_ele_del(Employee *head, int id)
{
  Employee *prev = nullptr;
  while (head)
  {
    if (head->emp_id == id)
    {
      if (prev)
      {
        prev->next = head->next;
        delete(head);
      }
      else
      {
        head = head->next;
        return;
      }
    }
    prev = head;
    head = head->next;
  }
}

void delete_list(Employee *head)
{
  Employee *ptr = nullptr;
  while (head)
  {
    ptr = head->next;
    delete(head);
    head = ptr;
  }
}

int main()
{
  Employee *emp;
  emp = list_create(1);
  insert_elem(emp, 2, 0);
  insert_elem(emp, 3, 0);
  list_ele_del(emp, 2);
  print_list(emp);
  insert_elem(emp, 2, 2);
  print_list(emp);
  delete_list(emp);

  return 0;
}
