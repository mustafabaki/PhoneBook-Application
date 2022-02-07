#include "functions.h"


struct Node *head = NULL;
struct Node *current = NULL;

//declaration of functions

// int length = 0;
int length()
{
  int length = 0;
  struct Node *current;

  for (current = head; current != NULL; current = current->next)
  {
    length++;
  }

  return length;
}

void delete (struct Node *a)
{

  printList(a);
  struct Node *data[length()];

  struct Node *ptr = a;
  printf("\n ");
  int i = 0;
  while (ptr != NULL)
  {
    data[i] = ptr;
    ptr = ptr->next;
    i = i + 1;
  }

  printf("Please enter the number of the entry to be deleted:");

  int key;

  scanf("%d", &key);

  key = key - 1;

  struct Node *delete_node = data[key];

  printf("The entry \"%s\" will be deleted. Are you sure? (y/n)", delete_node->data.name);

  char delete_choice;

  scanf("%c", &delete_choice);
  scanf("%c", &delete_choice);

  if (delete_choice == 'y' || delete_choice == 'Y')
  {
    //start from the first link
    struct Node *current = a;
    struct Node *previous = NULL;

    //if list is empty
    if (a == NULL)
    {
      return;
    }

    //navigate through list
    while (nodeEqual(current->data, delete_node->data) == false)
    {

      //if it is last node
      if (current->next == NULL)
      {
        return;
      }
      else
      {
        //store reference to current link
        previous = current;
        //move to next link
        current = current->next;
      }
    }

    //found a match, update the link
    if (current == head)
    {
      //change first to point to next link
      head = head->next;
    }
    else
    {
      //bypass the current link
      previous->next = current->next;
    }

    free(current->data.note);

    free(current);
    printf("The entry has been deleted successfully. Total numbers of entries: %d", length());
    
  }
  else
  {
    return;
  }
}

bool nodeEqual(struct contact a, struct contact b)
{
  if (strcmp(a.name, b.name) == 0 && strcmp(a.number, b.number) == 0 && strcmp(a.note, b.note) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void edit(struct Node *a)
{
  printList(a);
  struct Node *data[length()];

  struct Node *ptr = a;
  printf("\n ");
  int i = 0;
  while (ptr != NULL)
  {
    data[i] = ptr;
    ptr = ptr->next;
    i = i + 1;
  }

  printf("Please enter the number of the entry to be edited:");

  int key;

  scanf("%d", &key);

  key = key - 1;

  struct Node *edit_node = data[key];

  printf("Please re-enter the name of the chosen contact: ");
  char *rename;
  scanf(" %m[^\n]s", &rename);

  printf("Please re-enter the phone number of the chosen contact: ");
  char *rephone;
  scanf(" %m[^\n]s", &rephone);

  printf("Please re-enter the note of the chosen contact: ");
  char *renote;
  scanf(" %m[^\n]s", &renote);

  strcpy(edit_node->data.name, rename);

  strcpy(edit_node->data.number, rephone);

  strcpy(edit_node->data.note, renote);

  printf("The contact has been edited successfully.");

  free(rename);
  free(rephone);
  free(renote);
}

void insert(struct contact contact)
{

  struct contact new_contact = contact;

  struct Node *link = (struct Node *)malloc(sizeof(struct Node));

  link->data = new_contact;

  link->next = head;

  head = link;

  printf("%s %d", "Entry has been created successfully. Total number of entries:", length());
}
void sort(struct Node *a)
{

  int i, j, k;
  struct contact tempData;
  struct Node *current;
  struct Node *next;

  int size = length();
  k = size;

  for (i = 0; i < size - 1; i++, k--)
  {
    current = a;
    next = a->next;

    for (j = 1; j < k; j++)
    {

      if (strcmp(current->data.name, next->data.name) > 0)
      {
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;
      }

      current = current->next;
      next = next->next;
    }
  }
}

void printList(struct Node *a)
{

  sort(a);
  struct Node *ptr = a;
  printf("\n ");
  int i = 1;
  while (ptr != NULL)
  {
    printf("%d- %s\n%s\n%s\n ", i, ptr->data.name, ptr->data.number, ptr->data.note);
    ptr = ptr->next;
    i = i + 1;
  }

  printf(" ");
}
char *string_compare(const char *string1, const char *string2)
{

  const char *pointer1 = string1;
  const char *pointer2 = string2;
  const char *result = *pointer2 == 0 ? string1 : 0;

  while (*pointer1 != 0 && *pointer2 != 0)
  {
    if (tolower((unsigned char)*pointer1) == tolower((unsigned char)*pointer2))
    {
      if (result == 0)
      {
        result = pointer1;
      }

      pointer2++;
    }
    else
    {
      pointer2 = string2;
      if (result != 0)
      {
        pointer1 = result + 1;
      }

      if (tolower((unsigned char)*pointer1) == tolower((unsigned char)*pointer2))
      {
        result = pointer1;
        pointer2++;
      }
      else
      {
        result = 0;
      }
    }

    pointer1++;
  }

  return *pointer2 == 0 ? (char *)result : 0;
}
void search(struct Node *root)
{
  struct Node *ptr = root;

  int i = 0;
  printf("Please enter the string that you want to search for: ");
  char *search_string;

  scanf(" %m[^\n]s", &search_string);
  while (ptr != NULL)
  {

    if (string_compare(ptr->data.name, search_string) != 0 || string_compare(ptr->data.note, search_string) != 0)
    {
      break;
    }
    ptr = ptr->next;
    i = i + 1;
  }
  printf(" %s\n%s\n%s\n ", ptr->data.name, ptr->data.number, ptr->data.note);

  free(search_string);
}

void save(struct Node *node)
{
  printf("Please enter the filename that you want to save your contacts to (without file extension).\n ");
  scanf(" %m[^\n]s", &filename1);
  strcat(filename1, ".txt");

  sort(node);

  struct Node *traverse = node;

  FILE *fp = fopen(filename1, "w");
  int len = length();

  if (fp == NULL)
  {
    printf("Error opening the file %s", filename1);
  }
  for (int i = 0; i < len; i++)
  {
    fprintf(fp, "Name:%s /Phone:%s /Note:%s\n", traverse->data.name, traverse->data.number, traverse->data.note);
    traverse = traverse->next;
  }

  fclose(fp);
  free(filename1);
  //free(fp);
}

void load(struct Node *a)
{
  char *filename;

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  printf("Please enter the name of the text file you want to load into PhoneBook: (without file extension)");

  scanf(" %m[^\n]s", &filename);
  strcat(filename, ".txt");

  fp = fopen(filename, "r");

  if (fp == NULL)
  {
    printf("The file could not be read.");
  }

  while ((read = getline(&line, &len, fp)) != -1)
  {

    struct contact load;
    char *mynote = NULL;

    char *myname = strtok(line, "/");
    char *myphone = strtok(NULL, "/");
    mynote = strtok(NULL, "/");

    //tokenize name
    myname = strtok(myname, ":");
    myname = strtok(NULL, ":");

    //tokenize phone number
    myphone = strtok(myphone, ":");
    myphone = strtok(NULL, ":");

    //tokenize note

    mynote = strtok(mynote, ":");
    mynote = strtok(NULL, ":");

    strcpy(load.name, myname);
    strcpy(load.number, myphone);

    load.note = (char *)malloc(strlen(mynote));

    strcpy(load.note, mynote);

    load.note[strlen(load.note) - 1] = '\0';

    insert(load);
  }

  fclose(fp);
  free(filename);

  free(line);
}

void freeup(struct Node *a)
{

  while (a != NULL)
  {
    struct Node *tmp = a;
    a = a->next;
    free(tmp->data.note);

    free(tmp);
  }
}
