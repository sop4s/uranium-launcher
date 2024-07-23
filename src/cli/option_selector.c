#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "option_selector.h"
#include "colors.h"
#include "../config.h"

int init_option_selector(OptionSelector *selector) {
  selector->opt_head = NULL;
  return 0;
}
int add_option(OptionSelector *selector, const char *option) {
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
int wait_selection(OptionSelector *selector, char *option) {
  SelectorNode *current = selector->opt_head;
  SelectorNode* next;
  int i = 0;
  while (current != NULL) {
    printf("[" FG_MAIN "%d" FG_RESET "] %s\n", i, current->data);
    current = current->next;
    i++;
  }
  printf("Select an option: ");
  getchar();
  return 0;
}
