/**
 * @file coinsExchange.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2022-12-13
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/coinsExchange.h"

coinsExchange::coinsExchange() {
  coins_ = {2, 1, 0.5, 0.20, 0.10, 0.05, 0.02, 0.01};
  amount_ = 0;
  selected_ = {};
  rejected_ = {};
}

coinsExchange::SolutionFunction() {
  if (FeasibleFunction()) {
    if (ObjectiveFunction()) {
      // Print the solution.
    } else {
      for (int i = 0; i < coins_.size(); i++) {
        selected_.push_back(coins_[i]);
        rejected_.erase(coins_[i]);
        SolutionFunction();
        selected_.erase(coins_[i]);
        rejected_.push_back(coins_[i]);
      }
    }
  }
}

coinsExchange::FeasibleFunction() {
  if (amount_ < 0) {
    return false;
  } else {
    return true;
  }
}

coinsExchange::SelectionFunction() {
  int i = 0;
  while (amount_ > 0) {
    if (amount_ >= coins_[i]) {
      amount_ -= coins_[i];
      selected_.push_back(coins_[i]);
    } else {
      i++;
    }
  }
}

coinsExchange::ObjectiveFunction() {
  if (amount_ == 0) {
    return true;
  } else {
    return false;
  }
}

coinsExchange::SetAmount(int amount) {
  amount_ = amount;
}