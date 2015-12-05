/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team. UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer, contact information and the GNU Lesser General Public License.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License (as published by the Free Software
 * Foundation) version 2.1 dated February 1999.
 *
 * HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision: 1.4 $
 ***********************************************************************EHEADER*/




#ifdef MLI_SUPERLU

#ifndef __MLI_SOLVER_ARPACKSUPERLU_H__
#define __MLI_SOLVER_ARPACKSUPERLU_H__

#include <stdio.h>
#include "vector/mli_vector.h"
#include "solver/mli_solver.h"
#include "matrix/mli_matrix.h"

/******************************************************************************
 * data structure for the SuperLU in ARPACK shift-and-invert procedure
 *---------------------------------------------------------------------------*/

class MLI_Solver_ARPACKSuperLU : public MLI_Solver
{
   MLI_Matrix *Amat_;
   int        nRecvs_;
   int        *recvLengs_;
   int        *recvProcs_;
   int        nSends_;
   int        *sendLengs_;
   int        *sendProcs_;
   int        *sendMap_;
   int        nSendMap_;
   int        nNodes_;
   int        *ANodeEqnList_;
   int        *SNodeEqnList_;
   int        blockSize_;

public :

   MLI_Solver_ARPACKSuperLU(char *name);
   ~MLI_Solver_ARPACKSuperLU();
   int setup(MLI_Matrix *mat);
   int solve(MLI_Vector *f, MLI_Vector *u);
   int setParams(char *paramString, int argc, char **argv);
};

#endif

#else
   int bogus;
#endif
