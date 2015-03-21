/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef COMPUTE_CLASS

ComputeStyle(em2_dphi/atom,ComputeEM2dPhiAtom)

#else

#ifndef LMP_COMPUTE_EM2_DPHI_ATOM_H
#define LMP_COMPUTE_EM2_DPHI_ATOM_H

#include "compute.h"

namespace LAMMPS_NS {

class ComputeEM2dPhiAtom : public Compute {
 public:
  ComputeEM2dPhiAtom(class LAMMPS *, int, char **);
  ~ComputeEM2dPhiAtom();
  void init();
  void compute_peratom();
  double memory_usage();

 private:
  int nmax;
  double **dphi_vec;
  class AtomVecEM2 *avec;
};

}

#endif
#endif