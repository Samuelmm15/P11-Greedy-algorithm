/**
 * @file coinsExchangeImprovement.h
 * @author Samuel Martín Morales (alu0101359526)
 * @brief This is the file that contains the code improvement implementation of
 * the coins exchange problem.
 * @version 0.1
 * @date 2022-12-20
 * @signature Computabilidad y Algoritmia.
 * @course 2022-2023.
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#pragma once

/**
 * @brief This is the class that contains the code improvement implementation of
 * the coins exchange problem.
 *
 */
class coinsExchangeImprovement {
 public:
  coinsExchangeImprovement();
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