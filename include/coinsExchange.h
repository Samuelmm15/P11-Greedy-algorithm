/**
* @file coinsExchange.h
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

#include <iostream>
#include <vector>
#include <list>

#pragma once

class coinsExchange {
  public:
    coinsExchange();
    SolutionFunction();
    FeasibleFunction();
    SelectionFunction();
    ObjectiveFunction();
    SetAmount();
  private:
    std::vector<int> coins_; /// Este es el conjunto de candidatos de monedas viables.
    int amount_; /// Este es el valor objetivo.
    std::vector<int> selected_; /// Este es el conjunto de soluciones.
    std::vector<int> rejected_; /// Este es el conjunto de candidatos rechazados.
};