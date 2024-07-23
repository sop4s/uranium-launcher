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
int selector_init(OptionSelector *selector);
int selector_add(OptionSelector *selector, const char *option);
int selector_select(OptionSelector *selector, char *option);
#endif // !OPTION_SELECTOR_H
