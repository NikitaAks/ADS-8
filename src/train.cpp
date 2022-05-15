// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): countOp(0), first(nullptr) {}

void Train::addCage(bool glim) {
      Cage *cage = new Cage;
      cage->glim = glim;
      cage->next = nullptr;
      cage->prev = nullptr;
        if (first == nullptr) {
            first = cage;
        } else if (first->prev == nullptr) {
          first->prev = cage;
          cage->next = first;
          first->next = cage;
          cage->prev = first;
        } else {
          first->next->prev = cage;
          cage->next = first->next;
          first->next = cage;
          cage->prev = first;
      }
  }

int Train::getLength() {
      int len = 0;
      int count = 0;
      first->glim = true;
      Cage *temp = first;
        while (true) {
            countOp++;
            len++;
            temp = temp->prev;
            if (temp->glim) {
                temp->glim = false;
                count = 0;
                while (count < len) {
                    temp = temp->next;
                    countOp++;
                    count++;
              }
                if (!temp->glim) {
                    return len;
              }
              len = 0;
          }
      }
      return count;
  }

int Train::getOpCount() {
      return countOp;
  }
