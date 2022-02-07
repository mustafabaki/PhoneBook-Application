#include "functions.h"
int main(int argc, char *argv[])
{

  int choice = 0;
  printf("Welcome to myPhoneBook! ");

  while (1 == 1)
  {
    printf("Select an option: \n");
    printf("1) New entry \n");
    printf("2) List all entries \n");
    printf("3) Edit \n");
    printf("4) Delete\n");
    printf("5) Search\n");
    printf("6) Save and exit\n");
    printf("7) Load \n");

    scanf("%d", &choice);

    if (choice == 1)
    {
      // new entry
      char c[1];
      scanf("%c", c);

      printf("Enter a name: ");

      char name[50];
      scanf("%[^\n]%*c", name);
      printf("Enter a number: ");
      char num[11];
      scanf(" %[^\n]%*c", num);
      printf("Enter a note: ");
      scanf(" %m[^\n]s", &note);

      struct contact contact;

      strcpy(contact.name, name);

      strcpy(contact.number, num);
      contact.note = (char *)malloc(strlen(note));
      strcpy(contact.note, note);

      free(note);

      // insert function to do the rest...
      insert(contact);
    }
    else if (choice == 2)
    {
      // list all
      printList(head);
    }
    else if (choice == 3)
    {
      //edit
      edit(head);
    }
    else if (choice == 4)
    {
      //delete
      // get all entries to an array
      delete (head);
    }
    else if (choice == 5)
    {
      //search
      // the head is passed by reference to the function.
      search(head);
    }
    else if (choice == 6)
    {
      // save and exit

      // ....

      save(head);

      break;
    }
    else if (choice == 7)
    {
      //load
      load(head);
    }
  }

  // free every node at the end ...

  freeup(head);
}
