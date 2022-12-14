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
};

bool coinsExchange::FeasibleFunction() {
  if (amount_ < 0) {
    return false;
  } else {
    return true;
  }
};

void coinsExchange::SelectionFunction() {
  int i = 0;
  while (amount_ > 0) {
    if (amount_ >= coins_[i]) {
      amount_ -= coins_[i];
      selected_.push_back(coins_[i]);
    } else {
      i++;
    }
  }
};

bool coinsExchange::ObjectiveFunction() {
  if (amount_ == 0) {
    return true;
  } else {
    return false;
  }
};

void coinsExchange::SolutionFunction() {
if (FeasibleFunction()) {
    SelectionFunction();
    if (ObjectiveFunction()) {
      std::cout << "El número total de monedas es: " << selected_.size() << std::endl;
    } else {
      std::cout << "No se ha encontrado una solución." << std::endl;
    }
  } else {
    std::cout << "No se ha encontrado una solución." << std::endl;
  }

//  if (FeasibleFunction()) {
//    if (ObjectiveFunction()) {
//      // Print the solution.
//    } else {
//      for (int i = 0; i < coins_.size(); i++) {
//        selected_.push_back(coins_[i]);
////        rejected_.erase(rejected_.begin() + i);
////        rejected_.erase(std::find(rejected_.begin(), rejected_.end(), coins_[i]));
//        SolutionFunction();
////        selected_.erase(selected_.begin() + i);
////        selected_.erase(std::find(selected_.begin(), selected_.end(), coins_[i]));
//        rejected_.push_back(coins_[i]);
//      }
//    }
//  }
};

void coinsExchange::setAmount(float amount) {
  amount_ = amount;
};