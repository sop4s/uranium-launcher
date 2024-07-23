#ifndef OPTION_SELECTOR_H
#define OPTION_SELECTOR_H

#define SELECTOR_OPTION_MAX 30

struct SelectorNode {
  char data[SELECTOR_OPTION_MAX];
  struct SelectorNode *next;
};
typedef struct SelectorNode SelectorNode;

typedef struct {
  SelectorNode *opt_head;
} OptionSelector;
int init_option_selector(OptionSelector *selector);
int add_option(OptionSelector *selector, const char *option);
int wait_selection(OptionSelector *selector, char *option);
#endif // !OPTION_SELECTOR_H
