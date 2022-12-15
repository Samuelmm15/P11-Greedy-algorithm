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
//  return addition_ == amount_;
  return true;
};

void coinsExchange::SolutionFunction() {
  if (FeasibleFunction()) {
    SelectionFunction();
    if (ObjectiveFunction()) {
      /// Mostrar la solución de manera más simple
      std::cout << std::endl;
      std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
      std::cout << "Monedas: " << amount_ << std::endl;
      std::cout << "Solución: ";
      for (int i = 0; i < selected_.size(); i++) {
        std::cout << selected_[i] << "€ ";
      }
      std::cout << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;

      /// Mostrar la solución de manera más compleja
      int counter = 0;
      double previous = selected_[0];
      std::cout << std::endl;
      std::cout << "SOLUCIÓN ELABORADA: " << std::endl;
      std::cout << "Monedas: " << amount_ << std::endl;
      std::cout << "S = {";
      for (int i = 0; i < selected_.size(); i++) {
        if (selected_[i] == previous) {
          counter++;
        } else {
          if (counter > 0) {
            std::cout << counter << "x" << previous << "€, ";
          }
          counter = 1;
          previous = selected_[i];
        }
        }
      std::cout << counter << "x" << previous << "€"; /// Para mostrar la última moneda
      std::cout << "}" << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;
    }
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida." << std::endl;
  }
};

void coinsExchange::setAmount(double amount) {
  amount_ = amount;
};