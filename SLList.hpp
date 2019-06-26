#ifndef SLLIST_HPP
#define SLLIST_HPP

class SLList {
private:
  int start;
  SLList * theRest;
  unsigned int thisLength;
  
public:
  SLList(int, SLList *);
  static SLList * const NIL;

  SLList *rest();
  int first();
  void setFirst(int);
  void setRest(SLList *);
  unsigned int sum();
  unsigned int max();
  bool search(unsigned int o);
  int position(unsigned int o);

  int nth(unsigned int);
  SLList *nthRest(unsigned int);

  unsigned int length();
  SLList *remove(int i);
  SLList *reverse();
  SLList *prevList;

  SLList *sublist(int, int);
  SLList *merge(SLList *);
  SLList *mergesort();
};

#endif
