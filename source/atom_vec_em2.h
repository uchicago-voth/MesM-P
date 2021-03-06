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

/* ----------------------------------------------------------------------
   Contributing author: Aram Davtyan
------------------------------------------------------------------------- */

#ifdef ATOM_CLASS

AtomStyle(em2,AtomVecEM2)

#else

#ifndef LMP_ATOM_VEC_EM2_H
#define LMP_ATOM_VEC_EM2_H

#include "atom_vec.h"

namespace LAMMPS_NS {

class AtomVecEM2 : public AtomVec {
 public:
  struct Bonus {
    double quat[4];
  };
  struct Bonus *bonus;

  double **phi, **phi_half, **dphi;

  AtomVecEM2(class LAMMPS *);
  ~AtomVecEM2();
  virtual void grow(int);
  virtual void grow_reset();
  virtual void copy(int, int, int);
  int pack_comm(int, int *, double *, int, int *);
  int pack_comm_vel(int, int *, double *, int, int *);
  int pack_comm_hybrid(int, int *, double *);
  void unpack_comm(int, int, double *);
  void unpack_comm_vel(int, int, double *);
  int unpack_comm_hybrid(int, int, double *);
  int pack_reverse(int, int, double *);
  int pack_reverse_hybrid(int, int, double *);
  void unpack_reverse(int, int *, double *);
  int unpack_reverse_hybrid(int, int *, double *);
  virtual int pack_border(int, int *, double *, int, int *);
  virtual int pack_border_vel(int, int *, double *, int, int *);
  virtual int pack_border_hybrid(int, int *, double *);
  virtual void unpack_border(int, int, double *);
  virtual void unpack_border_vel(int, int, double *);
  virtual int unpack_border_hybrid(int, int, double *);
  virtual int pack_exchange(int, double *);
  virtual int unpack_exchange(double *);
  virtual int size_restart();
  virtual int pack_restart(int, double *);
  virtual int unpack_restart(double *);
  virtual void create_atom(int, double *);
  virtual void data_atom(double *, imageint, char **);
  virtual int data_atom_hybrid(int, char **);
  void data_vel(int, char **);
  int data_vel_hybrid(int, char **);
  virtual void pack_data(double **);
  virtual int pack_data_hybrid(int, double *);
  virtual void write_data(FILE *, int, double **);
  virtual int write_data_hybrid(FILE *, double *);
  void pack_vel(double **);
  int pack_vel_hybrid(int, double *);
  void write_vel(FILE *, int, double **);
  int write_vel_hybrid(FILE *, double *);
  virtual bigint memory_usage();

  void force_clear(int, size_t);
  int property_atom(char *);
  void pack_property_atom(int, double *, int, int);

 protected:
  tagint *tag;
  int *type,*mask;
  imageint *image;
  double **x,**v,**f;
  double *rmass;
  double **angmom,**torque;

  void copy_bonus(int, int);
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Per-processor system is too big

The number of owned atoms plus ghost atoms on a single
processor must fit in 32-bit integer.

E: Invalid atom type in Atoms section of data file

Atom types must range from 1 to specified # of types.

E: Invalid density in Atoms section of data file

Density value cannot be <= 0.0.

E: Assigning ellipsoid parameters to non-ellipsoid atom

Self-explanatory.

E: Invalid shape in Ellipsoids section of data file

Self-explanatory.

*/
