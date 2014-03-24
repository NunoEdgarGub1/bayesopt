/**  \file bayesoptbase.hpp \brief Bayesian optimization module */
/*
-------------------------------------------------------------------------
   This file is part of BayesOpt, an efficient C++ library for 
   Bayesian optimization.

   Copyright (C) 2011-2013 Ruben Martinez-Cantin <rmcantin@unizar.es>
 
   BayesOpt is free software: you can redistribute it and/or modify it 
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   BayesOpt is distributed in the hope that it will be useful, but 
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with BayesOpt.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------
*/


#ifndef  _MCMC_HPP_
#define  _MCMC_HPP_


namespace bayesopt {

  class MCMCSampler
  {
  public:
    MCMCSampler(size_t n_samples = 500);
    virtual ~MCMCSampler();

    void burnOut(vectord &x)
    void sliceSample(vectord &x);
    void sampleParticles(const vectord &initial, bool burnout);

  private:
    RBOptimizable* obj;
    size_t mDims;
    size_t nBurnOut;
    size_t nSamples;
    bool mStepOut;
    vectord mSigma;
    vecOfvec mParticles;
  };

  inline void MCMC::burnOut(vectord &x)
  {
    for(size_t i=0; i<nBurnOut; ++i)  sliceSample(x);
  }

} //namespace bayesopt


#endif