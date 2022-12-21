/**
 * @file coinsExchange.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the implementation of the different functions of
 * the class coinsExchange.
 * @version 0.1
 * @date 2022-12-13
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/coinsExchange.h"

/**
 * @brief Construct a new coins Exchange::coins Exchange object
 *
 */
coinsExchange::coinsExchange() {
  coins_ = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
  bills_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0,
            1.0,   0.5,   0.2,   0.1,  0.05, 0.02, 0.01};
  amount_ = 0;
  addition_ = 0;
};

/**
 * @brief This function checks if the amount is feasible.
 *
 * @return true
 * @return false
 */
bool coinsExchange::FeasibleFunction() {
  if (amount_ < 0) {
    return false;
  } else {
    return true;
  }
};

/**
 * @brief This function selects the coins that are going to be used to make the
 * change.
 *
 */
void coinsExchange::SelectionFunction() {
  for (int i = 0; i < coins_.size(); i++) {
    while (addition_ + coins_[i] <= amount_) {
      addition_ = addition_ + coins_[i];
      selected_.push_back(coins_[i]);
    }
  }
};

/**
 * @brief This function selects the bills that are going to be used to make the
 * change.
 *
 */
void coinsExchange::SelectionFunctionBills() {
  for (int i = 0; i < bills_.size(); i++) {
    while (addition_ + bills_[i] <= amount_) {
      addition_ = addition_ + bills_[i];
      selected_.push_back(bills_[i]);
    }
  }
};

/**
 * @brief This function checks the objetive of the operation.
 *
 * @return true
 * @return false
 */
bool coinsExchange::ObjectiveFunction() { return true; };

/**
 * @brief This function gets the solution of the operation.
 *
 */
void coinsExchange::SolutionFunction() {
  if (FeasibleFunction()) {
    SelectionFunction();
    if (ObjectiveFunction()) {
      /// @brief This is the basic solution.
      int small_coins_counter = 0;
      std::cout << std::endl;
      std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
      std::cout << "Monedas: " << amount_ << std::endl;
      std::cout << "Solución: ";
      for (int i = 0; i < selected_.size(); i++) {
        std::cout << selected_[i] << "€ ";
      }
      for (int i = 0; i < selected_.size(); i++) {
        if (selected_[i] <= 0.05) {
          small_coins_counter++;
        }
      }
      std::cout << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;
      std::cout << "Número de monedas pequeñas: " << small_coins_counter
                << std::endl;

      /// @brief This is the elaborated solution.
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
      std::cout << counter << "x" << previous << "€";
      std::cout << "}" << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;
      std::cout << "Número de monedas pequeñas: " << small_coins_counter
                << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida."
              << std::endl;
    std::cout << std::endl;
  }
};

void coinsExchange::SolutionFunctionBills() {
  if (FeasibleFunction()) {
    SelectionFunctionBills();
    if (ObjectiveFunction()) {
      /// @brief This is the basic solution.
      std::cout << std::endl;
      int small_coins_counter = 0;
      std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
      std::cout << "Billetes: " << amount_ << std::endl;
      std::cout << "Solución: ";
      for (int i = 0; i < selected_.size(); i++) {
        std::cout << selected_[i] << "€ ";
      }
      for (int i = 0; i < selected_.size(); i++) {
        if (selected_[i] <= 0.05) {
          small_coins_counter++;
        }
      }
      std::cout << std::endl;
      std::cout << "Número de billetes: " << selected_.size() << std::endl;
      std::cout << "Número de monedas pequeñas: " << small_coins_counter
                << std::endl;

      /// @brief This is the elaborated solution.
      int counter = 0;
      double previous = selected_[0];
      std::cout << std::endl;
      std::cout << "SOLUCIÓN ELABORADA: " << std::endl;
      std::cout << "Billetes: " << amount_ << std::endl;
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
      std::cout << counter << "x" << previous << "€";
      std::cout << "}" << std::endl;
      std::cout << "Número de billetes: " << selected_.size() << std::endl;
      std::cout << "Número de monedas pequeñas: " << small_coins_counter
                << std::endl;
      std::cout << std::endl;
    }
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida."
              << std::endl;
    std::cout << std::endl;
  }
};

void coinsExchange::setAmount(double amount) { amount_ = amount; };