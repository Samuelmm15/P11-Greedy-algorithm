/**
 * @file coinsExchangeImprovement.cc
 * @author Samuel Martin Morales (alu0101359526@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-20+
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/coinsExchangeImprovement.h"

coinsExchangeImprovement::coinsExchangeImprovement() {
    coins_ = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    bills_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
    amount_ = 0;
    addition_ = 0;
};

bool coinsExchangeImprovement::FeasibleFunction() {
    if (amount_ < 0) {
        return false;
    } else {
        return true;
    }
};

void coinsExchangeImprovement::SelectionFunction() {
    // double auxiliary_amount = amount_;
    // for (int i = 0; i < coins_.size(); i++) {
    //     double c_value = std::floor(auxiliary_amount - addition_ / coins_[i]);
    //     if (c_value > 0) {
    //         selected_.insert(selected_.end(), c_value, coins_[i]);
    //         addition_ = addition_ + c_value * coins_[i];
    //         auxiliary_amount = auxiliary_amount - c_value * coins_[i];
    //     }
    // }
    double auxiliary_amount = amount_;
    for (double v : coins_) {
        int c = (auxiliary_amount - addition_) / v;
        // std::cout << "c: " << c << std::endl;
        if (c > 0) {
            for (int i = 0; i < c; i++) {
                std::cout << "v: " << v << std::endl;
                selected_.insert(v);
            }
            addition_ += c * v;
            // auxiliary_amount -= c * v;
        }
    }
    
};

void coinsExchangeImprovement::SelectionFunctionBills() {
    // double auxiliary_amount = amount_;
    // for (int i = 0; i < bills_.size(); i++) {
    //     double c_value = std::floor(auxiliary_amount / bills_[i]);
    //     if (c_value > 0) {
    //         selected_.insert(selected_.end(), c_value, coins_[i]);
    //         addition_ = addition_ + c_value * bills_[i];
    //         auxiliary_amount = auxiliary_amount - c_value * bills_[i];
    //     }
    // }
};

bool coinsExchangeImprovement::ObjectiveFunction() {
    //return addition_ == amount_;
    return true;
};

void coinsExchangeImprovement::SolutionFunction() {
    if (FeasibleFunction()) {
      SelectionFunction();
    }
    if (ObjectiveFunction()) {
      std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
      std::cout << "Monedas: " << amount_ << std::endl;
      std::cout << "Solución: ";
      std::set<double>::iterator it;
      for (it = selected_.begin(); it != selected_.end(); it++) {
        std::cout << *it << "€ ";
      }
      std::cout << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;
      std::cout << "SOLUCIÓN ELABORADA: " << std::endl;
      std::cout << "Monedas: " << amount_ << std::endl;
      std::cout << "S = {";
      int counter = 0;
      double previous = *selected_.begin();
      for (it = selected_.begin(); it != selected_.end(); it++) {
        if (*it == previous) {
          counter++;
        } else {
          if (counter > 0) {
            std::cout << counter << "x" << previous << "€, ";
          }
          counter = 1;
          previous = *it;
        }
      }
      std::cout << counter << "x" << previous << "€"; /// Para que no salga la coma al final
      std::cout << "}" << std::endl;
      std::cout << "Número de monedas: " << selected_.size() << std::endl;
      // Mostrar la solución de manera más simple
      // std::cout << std::endl;
      // std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
      // std::cout << "Monedas: " << amount_ << std::endl;
      // std::cout << "Solución: ";
      // for (int i = 0; i < selected_.size(); i++) {
      //   std::cout << selected_[i] << "€ ";
      // }
      // std::cout << std::endl;
      // std::cout << "Número de monedas: " << selected_.size() << std::endl;

      // /// Mostrar la solución de manera más compleja
      // int counter = 0;
      // double previous = selected_[0];
      // std::cout << std::endl;
      // std::cout << "SOLUCIÓN ELABORADA: " << std::endl;
      // std::cout << "Monedas: " << amount_ << std::endl;
      // std::cout << "S = {";
      // for (int i = 0; i < selected_.size(); i++) {
      //   if (selected_[i] == previous) {
      //     counter++;
      //   } else {
      //     if (counter > 0) {
      //       std::cout << counter << "x" << previous << "€, ";
      //     }
      //     counter = 1;
      //     previous = selected_[i];
      //   }
      //   }
      // std::cout << counter << "x" << previous << "€"; /// Para mostrar la última moneda
      // std::cout << "}" << std::endl;
      // std::cout << "Número de monedas: " << selected_.size() << std::endl;
  } else {
    std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida." << std::endl;
  }
};

void coinsExchangeImprovement::SolutionFunctionBills() {
  //   if (FeasibleFunction()) {
  //     SelectionFunctionBills();
  //   }
  //   if (ObjectiveFunction()) {
  //     /// Mostrar la solución de manera más simple
  //     std::cout << std::endl;
  //     std::cout << "SOLUCIÓN BÁSICA: " << std::endl;
  //     std::cout << "Billetes: " << amount_ << std::endl;
  //     std::cout << "Solución: ";
  //     for (int i = 0; i < selected_.size(); i++) {
  //       std::cout << selected_[i] << "€ ";
  //     }
  //     std::cout << std::endl;
  //     std::cout << "Número de billetes: " << selected_.size() << std::endl;

  //     /// Mostrar la solución de manera más compleja
  //     int counter = 0;
  //     double previous = selected_[0];
  //     std::cout << std::endl;
  //     std::cout << "SOLUCIÓN ELABORADA: " << std::endl;
  //     std::cout << "Billetes: " << amount_ << std::endl;
  //     std::cout << "S = {";
  //     for (int i = 0; i < selected_.size(); i++) {
  //       if (selected_[i] == previous) {
  //         counter++;
  //       } else {
  //         if (counter > 0) {
  //           std::cout << counter << "x" << previous << "€, ";
  //         }
  //         counter = 1;
  //         previous = selected_[i];
  //       }
  //       }
  //     std::cout << counter << "x" << previous << "€"; /// Para mostrar el último billete
  //     std::cout << "}" << std::endl;
  //     std::cout << "Número de billetes: " << selected_.size() << std::endl;
  // } else {
  //   std::cout << "ERROR >> La cantidad de dinero a comprobar no es válida." << std::endl;
  // }
};

void coinsExchangeImprovement::setAmount(double amount) {
    amount_ = amount;
};