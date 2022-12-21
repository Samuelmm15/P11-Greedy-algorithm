/**
 * @file coinsExchange.h
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief This file contains the declaration of the class coinsExchange.
 * @version 0.1
 * @date 2022-12-13
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

#pragma once

class coinsExchange {
 public:
  coinsExchange();
  void SolutionFunction();
  void SolutionFunctionBills();
  bool FeasibleFunction();
  void SelectionFunction();
  void SelectionFunctionBills();
  bool ObjectiveFunction();
  void setAmount(double amount);

 private:
  std::vector<double> coins_;     /// This is the set of viable coin candidates.
  std::vector<double> bills_;     /// This is the set of viable bill candidates.
  double amount_;                 /// This is the amount to be exchanged.
  double addition_;               /// This is the amount that has been added.
  std::vector<double> selected_;  /// This is the set of selected coins.
};