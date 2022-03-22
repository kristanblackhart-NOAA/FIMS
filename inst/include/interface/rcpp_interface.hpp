
/*
 * File:   rcpp_interface.hpp
 *
 * Author: Kelli Johnson, Jim Ianelli, Tim Miller, Kathryn Doering, Matthew Supernaw
 * National Oceanic and Atmospheric Administration
 * National Marine Fisheries Service
 * Email: andrea.havron@noaa.gov
 *
 * Created on February 23, 2022
 *
 * This File is part of the NOAA, National Marine Fisheries Service
 * Fisheries Integrated Modeling System project.
 *
 * This software is a "United States Government Work" under the terms of the
 * United States Copyright Act.  It was written as part of the author's official
 * duties as a United States Government employee and thus cannot be copyrighted.
 * This software is freely available to the public for use. The National Oceanic
 * And Atmospheric Administration and the U.S. Government have not placed any
 * restriction on its use or reproduction.  Although all reasonable efforts have
 * been taken to ensure the accuracy and reliability of the software and data,
 * the National Oceanic And Atmospheric Administration and the U.S. Government
 * do not and cannot warrant the performance or results that may be obtained by
 * using this  software or data. The National Oceanic And Atmospheric
 * Administration and the U.S. Government disclaim all warranties, express or
 * implied, including warranties of performance, merchantability or fitness
 * for any particular purpose.
 *
 * Please cite the author(s) in any work or product based on this material.
 *
 */
#ifndef FIMS_RCPP_INTERFACE_HPP
#define FIMS_RCPP_INTERFACE_HPP

#define RCPP_NO_SUGAR
#include <Rcpp.h>


void addData(Rcpp::DataFrame& data){
   std::cout<<"size = "<<data.size()<<"\n";
Rcpp::DataFrame::iterator it;

  Rcpp::CharacterVector df_names = data.names();
  Rcpp::Rcout << "col names: " << df_names << std::endl;



if (data.containsElementNamed("ages")){
   Rcpp::NumericVector years = data["years"];
   std::cout<<"years = "<<ages.size()<<"\n";
   for(int i = 0; i < ages.size(); i++){
      std::cout<<"years["<<i<<"] = "<<years[i]<<"\n";
   }
}



}

RCPP_MODULE(fims) {
    //place holder for module elements
    Rcpp::function("addData", addData);
};


#endif
