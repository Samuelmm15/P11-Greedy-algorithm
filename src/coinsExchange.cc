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
  coins_ = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
  amount_ = 0;
  selected_ = {};
  rejected_ = {};
  addition_ = 0;
};

bool coinsExchange::FeasibleFunction() {
  if (amount_ < 0) {
    return false;
  } else {
    return true;
  }
};

void coinsExchange::SelectionFunction() {
  for (int i = 0; i < coins_.size(); i++) {
    while (addition_ + coins_[i] <= amount_) {
      addition_ = addition_ + coins_[i];
      selected_.push_back(coins_[i]);
    }
  }
};

bool coinsExchange::ObjectiveFunction() {
  if (addition_ == amount_) {
    return true;
  } else {
    return false;
  }
};

void coinsExchange::SolutionFunction() {
  if (FeasibleFunction()) {
    SelectionFunction();
    if (ObjectiveFunction()) {
      std::cout << "El número de monedas que se debe de usar es: " << selected_.size() << std::endl;
    } else {
      std::cout << "No se ha encontrado una solución." << std::endl;
    }
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida." << std::endl;
  }
};

void coinsExchange::setAmount(double amount) {
  amount_ = amount;
};