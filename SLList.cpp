#include <cstdlib>
#include <climits>
#include <iostream>
#include "SLList.hpp"

using namespace std;

SLList * const SLList::NIL = new SLList(0, NULL);

SLList::SLList(int i, SLList *n) {
  start = i;
  theRest = n;
}

int SLList::first() {
  return start;
}

SLList *SLList::rest() {
  return theRest;
}

void SLList::setFirst(int i) {
  start = i;
}

void SLList::setRest(SLList *n) {
  theRest = n;
}

int SLList::nth(unsigned int i) {
  if(this == NIL){
    return 0;
  }else if(i>0){
    return this->rest()->nth(i-1);
  }else{
    return this->first();
  }
}

SLList *SLList::nthRest(unsigned int i) {
  if(this == NIL){
    return NIL;
  }else if(i>0){
    return this->rest()->nthRest(i-1);
  }else{
    return this;
  }
}

unsigned int SLList::length() {
  if(this == NIL){
    return 0;
  }else{
    return 1 + this->rest()->length();
  }
}

unsigned int SLList::sum() {
  if(this == NIL){
    return 0;
  }else{
    return this->first() + this->rest()->sum();
  }
}

unsigned int SLList::max() {
  if(this == NIL){
    return 0;
  }else{
    return (this->first() > this->rest()->max()) ? this->first() : this->rest()->max();
  }
}

bool SLList::search(unsigned int o) {
  if(this == NIL){
    return false;
  }else{
    return (this->first() == o) ? true : this->rest()->search(o);
  }
}


int SLList::position(unsigned int o) {
  if(this == NIL){
    return -1;
  }else{
    return (this->first() == o) ? 0 : 1 + this->rest()->position(o);
  }
}

SLList *SLList::remove(int i) {
	if (this == NIL) {
		return NIL;
	}
	else if (i == this->first()) {
		return this->rest()->remove(i);
	}
	else {
		return new SLList(this->first(), this->rest()->remove(i));
	}
}

SLList *SLList::reverse() {
  if (this == NIL){
    return this;
  }else if(this->rest() == NIL){
    prevList = new SLList(this->first(), NIL);
    return prevList;
  }else{
    SLList * newList = this->rest()->reverse();

    prevList = this->rest()->prevList;

    SLList * curList = new SLList(this->first(), NIL);

    prevList->setRest(curList);
    prevList = curList;
    
    return newList;
  }
}

SLList *SLList::sublist(int start, int end) {

  if (start == 0 && end == 0) {
		return NIL;
	} else if (start > 0) {
		return rest()->sublist(start-1, end - 1);
	} else if (end > 0) {
		return new SLList(first(), rest()->sublist(0, end - 1));
	}
  
  
  // SLList *list = NIL;
  // SLList *next = NIL;
  // SLList *templist = this;

  // for (int i=0; i<e; i++){
  //   if(i == s){
  //     list = new SLList(templist->first(), NIL);
  //     next = list;
  //   }else if(i > s){
  //     next->setRest(new SLList(templist->first(), NIL));
  //     next = next->rest();
  //   }
  //   templist = templist->rest();
  // }

  // return list;
}

SLList *SLList::merge(SLList * list) {

  if(this == NIL){
    return list;
  }else if(list == NIL){
    return this;
  }else if(this->first() <= list->first()){
    return new SLList(this->first(), this->rest()->merge(list));
  }else{
    return new SLList(list->first(), this->merge(list->rest()));
  }

}

SLList *SLList::mergesort() {

  int len = this->length();
  
  if(len <= 1){
    return this;
  }else{
    int mid = len/2;
    SLList *left = this->sublist(0, mid)->mergesort();
    SLList *right = this->sublist(mid, len)->mergesort();
    return left->merge(right);
  }
  
}