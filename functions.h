#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct contact
{
  char name[50];
  char number[11];
  char *note;
};

struct Node
{
  struct contact data;
  struct Node *next;
};

struct Node *head;
struct Node *current;
char *filename1;
char *note;


bool nodeEqual(struct contact a, struct contact b);
int length();
void delete (struct Node *a);
void edit(struct Node *a);
void insert(struct contact contact);
void sort();
void printList(struct Node *a);
char *string_compare(const char *string1, const char *string2);
void search(struct Node *root);
void save(struct Node *node);
void load(struct Node *a);
void freeup(struct Node *a);


#endif // FUNCTIONS_H
