#include <TMB.hpp>
#include <iostream>

#define see(object) std::cout << #object ":\n" << object << "\n";

template<class Type>
Type dmultinom(vector<Type> obs, vector<Type> p, int do_log)
{
  //multinomial
  int dim = obs.size();
  Type N = obs.sum();
  Type ll = lgamma(N + 1.0);
  for(int a = 0; a < dim; a++)
  {
    ll += -lgamma(obs(a) + 1.0);
    if(obs(a)>0) ll += obs(a) * log(squeeze(p(a)));
  }
  if(do_log == 1) return ll;
  else return exp(ll);
}

template<class Type>
Type objective_function<Type>::operator() ()
{
  DATA_VECTOR(obs); //data
  DATA_IVECTOR(years);
  n_years = years.size();
  DATA_INTEGER(n_ages);
  int n_obs = obs.size();
  vector<Type> nll_age_composition(n_years);
  nll.setZero();

  vector<Type> obs_y(n_ages);
  int k = 0;
  for(int y = 0; y < n_years){
    for(int i = 0; i < n_ages; i++){
        obs_y(i) = obs(k);
        k++;
    }
    nll(y) = -dmultinom(obs_y, obs_pred)
  }

  REPORT(mat);
  ADREPORT(a50);
  REPORT(nll);
  ADREPORT(logit_mat_at_age);
  ADREPORT(mat_at_age);
  return sum(nll);
  //return nll.sum();
}

