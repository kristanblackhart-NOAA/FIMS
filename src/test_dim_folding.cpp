#include <TMB.hpp>
#include <iostream>

#define see(object) std::cout << #object ":\n" << object << "\n";

template<class Type>
Type objective_function<Type>::operator() ()
{
  /*

  */
  DATA_VECTOR(obs); //data
  DATA_IVECTOR(years);
  int n_years = years.size();
  DATA_INTEGER(n_ages);
  PARAMETER_VECTOR(mu_age_comp); //length = n_ages -1. The predicted proportions would actually be generated from the pop mod.
  int n_obs = obs.size();
  vector<Type> nll_age_composition(n_years);
  nll_age_composition.setZero();

  vector<Type> obs_y(n_ages);
  int k = 0;
  vector<Type> pred(n_ages);
  for(int i = 0; i < n_ages-1; i++){
      pred(i) = 1/(1 + exp(-mu_age_comp(i)));
  }
  pred(n_ages-1) = 1.0 - pred.head(n_ages-1).sum();
  for(int y = 0; y < n_years; y++){
    for(int i = 0; i < n_ages; i++){
        obs_y(i) = obs(k);
        k++;
    }
    nll_age_composition(y) = -dmultinom(obs_y, pred, 1);
  }

  REPORT(nll_age_composition);
  return nll_age_composition.sum();
}

