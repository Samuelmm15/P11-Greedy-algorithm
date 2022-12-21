/**
 * @file coinsExchangeImprovement.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the implementation of the different functions of
 * the class coinsExchangeImprovement.
 * @version 0.1
 * @date 2022-12-20+
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/coinsExchangeImprovement.h"

/**
 * @brief Construct a new coins Exchange Improvement::coins Exchange Improvement
 * object
 *
 */
coinsExchangeImprovement::coinsExchangeImprovement() {
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
bool coinsExchangeImprovement::FeasibleFunction() {
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
void coinsExchangeImprovement::SelectionFunction() {
  double auxiliary_amount = amount_;
  for (double v : coins_) {
    int c = (auxiliary_amount - addition_) / v;
    if (c > 0) {
      for (int i = 0; i < c; i++) {
        selected_.push_back(v);
      }
      addition_ += c * v;
    }
  }
};

/**
 * @brief This function selects the bills that are going to be used to make the
 * change.
 *
 */
void coinsExchangeImprovement::SelectionFunctionBills() {
  double auxiliary_amount = amount_;
  for (double v : bills_) {
    int c = (auxiliary_amount - addition_) / v;
    if (c > 0) {
      for (int i = 0; i < c; i++) {
        selected_.push_back(v);
      }
      addition_ += c * v;
    }
  }
};

/**
 * @brief This function comprobes the objetive of the program.
 *
 * @return true
 * @return false
 */
bool coinsExchangeImprovement::ObjectiveFunction() {
  return true;
};

/**
 * @brief This fuction gets the solution of the operation.
 *
 */
void coinsExchangeImprovement::SolutionFunction() {
  if (FeasibleFunction()) {
    SelectionFunction();
  }
  if (ObjectiveFunction()) {
    /// @brief This is the basic solution.
    std::cout << std::endl;
    int small_coins_counter = 0;
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
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida."
              << std::endl;
    std::cout << std::endl;
  }
};

/**
 * @brief This function gets the solution of the operation with bills.
 *
 */
void coinsExchangeImprovement::SolutionFunctionBills() {
  if (FeasibleFunction()) {
    SelectionFunctionBills();
  }
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
    std::cout << "Número de moneadas pequeñas: " << small_coins_counter
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
    std::cout << "Número de moneadas pequeñas: " << small_coins_counter
              << std::endl;
    std::cout << std::endl;
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida."
              << std::endl;
    std::cout << std::endl;
  }
};

/**
 * @brief This function sets the amount of money to change.
 *
 * @param double
 */
void coinsExchangeImprovement::setAmount(double amount) { amount_ = amount; };