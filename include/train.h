// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
// Copyright 2021 NNTU-CS
#include "train.h"

class Train {
 private:
  struct Cage {
    bool light; // состояние лампочки
    Cage *next;
    Cage *prev;
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  Cage *first; // точка входа в поезд (первый вагон)
 public:
  Train();
  void addCage(bool light); // добавить вагон с начальным состоянием лампочки
  int getLength();          // вычислить длину поезда
  int getOpCount();         // вернуть число переходов (из вагона в вагон)
};
#endif  // INCLUDE_TRAIN_H_

Train::Train(): countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->prev = nullptr;
  cage->next = nullptr;
  if (first == nullptr) {
    first = cage;
  } else if (first->next == nullptr) {
    first->next = cage;
    cage->prev = first;
    first->prev = cage;
    cage->next = first;
  } else {
    first->prev->next = cage;
    cage->prev = first->prev;
    first->prev = cage;
    cage->next = first;
  }
}

int Train::getLength() {
  int dlin = 0;
  int tr_dlin;
  countOp = 0;
  first->light = true;
  Cage* temp = first;
  while (true) {
    countOp++;
    dlin++;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      tr_dlin = dlin;
      for (tr_dlin; tr_dlin > 0; tr_dlin--) {
        temp = temp->prev;
        countOp++;
      }
      if (!temp->light) {
        return dlin;
      }
      dlin = tr_dlin;
    }
  }
  return tr_dlin;
}

int Train::getOpCount() {
  return countOp;
}
