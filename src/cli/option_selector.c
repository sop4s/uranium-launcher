#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "option_selector.h"
#include "colors.h"
#include "../config.h"
#include "input.h"

int selector_init(OptionSelector *selector) {
  selector->opt_head = NULL;
  return 0;
}
int selector_add(OptionSelector *selector, const char *option) {
  SelectorNode *new_node = malloc(sizeof(SelectorNode));
  if (new_node == NULL) {
    fprintf(stderr, "malloc error\n");
    return 1;
  }
  strncpy(new_node->data, option, SELECTOR_OPTION_MAX - 1);
  new_node->data[SELECTOR_OPTION_MAX - 1] = '\0';
  new_node->next = NULL;
  if (selector->opt_head == NULL) {
    selector->opt_head = new_node;
  } else {
    SelectorNode *current = selector->opt_head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  return 0;
}
int selector_select(OptionSelector *selector, char *option) {
  SelectorNode *current = selector->opt_head;
  int selection = 0;

  int i = 0;
  while (current != NULL) {
    printf("[" FG_MAIN "%d" FG_RESET "] %s\n", i, current->data);
    current = current->next;
    i++;
  }
  printf("> ");
  read_int(&selection);
  current = selector->opt_head;
  i = 0;
  while (current != NULL) {
    if (selection == i) {
      strncpy(option, current->data, SELECTOR_OPTION_MAX);
      return 0;
    }
    current = current->next;
    i++;
  }
  fprintf(stderr, "index out of range\n");
  return 1;
}
