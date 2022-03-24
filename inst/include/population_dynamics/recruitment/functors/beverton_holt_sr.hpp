/*
 * File:   recruitment.hpp
 *
 * Author: Andrea Havron, Chris Legault, Kyle Shertzer, Nathan Vaughan
 * National Oceanic and Atmospheric Administration
 * National Marine Fisheries Service
 * Email: fims@noaa.gov
 *
 * Created on March 22, 2021, 12:50 PM
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
#ifndef FIMS_POPULATION_DYNAMICS_RECRUITMENT_BEVERTON_HOLT_HPP
#define FIMS_POPULATION_DYNAMICS_RECRUITMENT_BEVERTON_HOLT_HPP

#include "../../../interface/interface.hpp"
#include "../../../fims_math.hpp"
#include "recruitment_base.hpp"

namespace fims{

  template<typename Type>
  struct BevertonHolt :public RecruitmentBase<>{

    BevertonHolt():RecruitmentBase<Type>(){
    }

    virtual const Type evaluate(){
        return fims::beverton_holt_sr();
    }
  }

}

#endif /* FIMS_POPULATION_DYNAMICS_RECRUITMENT_BEVERTON_HOLT_HPP */
