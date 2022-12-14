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
#include <algorithm>

#pragma once

class coinsExchange {
  public:
    coinsExchange();
    void SolutionFunction();
    bool FeasibleFunction();
    void SelectionFunction();
    bool ObjectiveFunction();
    void setAmount(double amount);
  private:
    std::vector<double> coins_; /// Este es el conjunto de candidatos de monedas viables.
    float amount_; /// Este es el valor objetivo.
    float addition_; /// Este es el valor de la suma de las monedas seleccionadas.
    std::vector<double> selected_; /// Este es el conjunto de soluciones.
    std::vector<double> rejected_; /// Este es el conjunto de candidatos rechazados.
};