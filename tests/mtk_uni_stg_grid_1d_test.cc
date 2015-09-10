/*!
\file mtk_uni_stg_grid_1d_test.cc

\brief Test file for the mtk::UniStgGrid1D class.

\author: Eduardo J. Sanchez (ejspeiro) - esanchez at mail dot sdsu dot edu
*/
/*
Copyright (C) 2015, Computational Science Research Center, San Diego State
University. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Modifications to source code should be reported to: esanchez@mail.sdsu.edu
and a copy of the modified files should be reported once modifications are
completed. Documentation related to said modifications should be included.

2. Redistributions of source code must be done through direct
downloads from the project's GitHub page: http://www.csrc.sdsu.edu/mtk

3. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

4. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

5. Usage of the binary form on proprietary applications shall require explicit
prior written permission from the the copyright holders.

6. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

The copyright holders provide no reassurances that the source code provided does
not infringe any patent, copyright, or any other intellectual property rights of
third parties. The copyright holders disclaim any liability to any recipient for
claims brought against recipient by any third party for infringement of that
parties intellectual property rights.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#if __cplusplus == 201103L

#include <iostream>
#include <ctime>

#include "mtk.h"

void Test1() {

  mtk::Tools::BeginTestNo(1);

  mtk::UniStgGrid1D gg;

  std::cout << gg << std::endl;

  mtk::Tools::EndTestNo(1);
}

mtk::Real ScalarFieldOne(mtk::Real xx) {

  return 2.0*xx;
}

void Test2() {

  mtk::Tools::BeginTestNo(2);

  mtk::Real aa = 0.0;
  mtk::Real bb = 1.0;

  int nn = 5;

  mtk::UniStgGrid1D gg(aa, bb, nn);

  std::cout << gg << std::endl;

  gg.BindScalarField(ScalarFieldOne);

  std::cout << gg << std::endl;

  mtk::Tools::EndTestNo(2);
}

void Test3() {

  mtk::Tools::BeginTestNo(3);

  mtk::Real aa = 0.0;
  mtk::Real bb = 1.0;

  int nn = 5;

  mtk::UniStgGrid1D gg(aa, bb, nn);

  std::cout << gg << std::endl;

  gg.BindScalarField(ScalarFieldOne);

  std::cout << gg << std::endl;

  if(!gg.WriteToFile("mtk_uni_stg_grid_1d_test_03.dat", "x", "u(x)")) {
    std::cerr << "Error writing to file." << std::endl;
  }

  mtk::Tools::EndTestNo(3);
}

mtk::Real VectorFieldXComponentOne(mtk::Real xx) {

  return xx*xx;
}

void Test4() {

  mtk::Tools::BeginTestNo(4);

  mtk::Real aa = 0.0;
  mtk::Real bb = 1.0;

  int nn = 20;

  mtk::UniStgGrid1D gg(aa, bb, nn, mtk::VECTOR);

  std::cout << gg << std::endl;

  gg.BindVectorField(VectorFieldXComponentOne);

  std::cout << gg << std::endl;

  if(!gg.WriteToFile("mtk_uni_stg_grid_1d_test_04.dat", "x", "v(x)")) {
    std::cerr << "Error writing to file." << std::endl;
  }

  mtk::Tools::EndTestNo(4);
}

int main () {

  std::cout << "Testing mtk::UniStgGrid1D class." << std::endl;

  Test1();
  Test2();
  Test3();
  Test4();
}

#else
#include <iostream>
using std::cout;
using std::endl;
int main () {
  cout << "This code HAS to be compiled with support for C++11." << endl;
  cout << "Exiting..." << endl;
}
#endif