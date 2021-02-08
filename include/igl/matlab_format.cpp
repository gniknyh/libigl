// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "matlab_format.h"
#include "STR.h"
#include "find.h"

template <typename DerivedM>
IGL_INLINE const Eigen::WithFormat< DerivedM > igl::matlab_format(
  const Eigen::DenseBase<DerivedM> & M,
  const std::string name)
{
  using namespace std;
  string prefix = "";
  if(!name.empty())
  {
    prefix = name + " = ";
  }

  return M.format(Eigen::IOFormat(
    Eigen::FullPrecision,
    0,
    " ",
    "\n",
    "",
    "",
    // This seems like a bit of a hack since I would expect the rows to align
    // with out this extra spacing on the first line
    prefix + "[\n  ",
    "\n];"));
}

template <typename DerivedM>
IGL_INLINE std::string igl::matlab_format_index(
  const Eigen::MatrixBase<DerivedM> & M,
  const std::string name)
{
  // can't return WithFormat since that uses a pointer to matrix
  return STR(igl::matlab_format((M.array()+1).eval(),name));
}

template <typename DerivedS>
IGL_INLINE const std::string
igl::matlab_format(
  const Eigen::SparseMatrix<DerivedS> & S,
  const std::string name)
{
  using namespace Eigen;
  using namespace std;
  Matrix<typename Eigen::SparseMatrix<DerivedS>::Scalar,Dynamic,1> I,J,V;
  Matrix<DerivedS,Dynamic,Dynamic> SIJV;
  find(S,I,J,V);
  I.array() += 1;
  J.array() += 1;
  SIJV.resize(V.rows(),3);
  SIJV << I,J,V;
  string prefix = "";
  string suffix = "";
  if(!name.empty())
  {
    prefix = name + "IJV = ";
    suffix = "\n"+name + " = sparse("+name+"IJV(:,1),"+name+"IJV(:,2),"+name+"IJV(:,3),"+std::to_string(S.rows())+","+std::to_string(S.cols())+" );";
  }
  return STR(""<<
    SIJV.format(Eigen::IOFormat(
    Eigen::FullPrecision,
    0,
    " ",
    "\n",
    "",
    "",
    // This seems like a bit of a hack since I would expect the rows to align
    // with out this extra spacing on the first line
    prefix + "[\n  ",
    "\n];"))<<suffix);
}

IGL_INLINE Eigen::IOFormat igl::matlab_format()
{
  // M = [1 2 3;4 5 6];
  // M.format(matlab_format()) produces:
  // [
  //   1 2 3
  //   4 5 6
  // ];
  return Eigen::IOFormat(
    Eigen::FullPrecision,
    0,
    " ",
    "\n",
    "",
    "",
    // This seems like a bit of a hack since I would expect the rows to align
    // with out this extra spacing on the first line
    "[\n  ",
    "\n];");
}

IGL_INLINE const std::string igl::matlab_format(
 const double v,
 const std::string name)
{
  using namespace std;
  string prefix = "";
  if(!name.empty())
  {
    prefix = name + " = ";
  }
  return STR(prefix<<v<<";");
}

IGL_INLINE const std::string igl::matlab_format(
    const float v,
    const std::string name)
{
  return matlab_format(double(v),name);
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template instantiation
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, -1, 1, 0, 4, 1> > const igl::matlab_format<Eigen::Matrix<double, -1, 1, 0, 4, 1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 1, 0, 4, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, -1, 1, 0, 10, 1> > const igl::matlab_format<Eigen::Matrix<double, -1, 1, 0, 10, 1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 1, 0, 10, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Array<bool, 8, 1, 0, 8, 1> > const igl::matlab_format<Eigen::Array<bool, 8, 1, 0, 8, 1> >(Eigen::DenseBase<Eigen::Array<bool, 8, 1, 0, 8, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 2, 8, 0, 2, 8> > const igl::matlab_format<Eigen::Matrix<double, 2, 8, 0, 2, 8> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 8, 0, 2, 8> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 2, 6, 0, 2, 6> > const igl::matlab_format<Eigen::Matrix<double, 2, 6, 0, 2, 6> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 6, 0, 2, 6> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 0, 3, 0, 0, 3> > const igl::matlab_format<Eigen::Matrix<double, 0, 3, 0, 0, 3> >(Eigen::DenseBase<Eigen::Matrix<double, 0, 3, 0, 0, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 0, 2, 0, 0, 2> > const igl::matlab_format<Eigen::Matrix<double, 0, 2, 0, 0, 2> >(Eigen::DenseBase<Eigen::Matrix<double, 0, 2, 0, 0, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 1, 1, 0, 1, 1> > const igl::matlab_format<Eigen::Matrix<double, 1, 1, 0, 1, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 1, 1, 0, 1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Array<bool, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Array<bool, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Array<bool, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Array<bool, 3, 1, 0, 3, 1> > const igl::matlab_format<Eigen::Array<bool, 3, 1, 0, 3, 1> >(Eigen::DenseBase<Eigen::Array<bool, 3, 1, 0, 3, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Array<bool, 2, 1, 0, 2, 1> > const igl::matlab_format<Eigen::Array<bool, 2, 1, 0, 2, 1> >(Eigen::DenseBase<Eigen::Array<bool, 2, 1, 0, 2, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 16, 1, 0, 16, 1> > const igl::matlab_format<Eigen::Matrix<double, 16, 1, 0, 16, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 16, 1, 0, 16, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 16, 16, 0, 16, 16> > const igl::matlab_format<Eigen::Matrix<double, 16, 16, 0, 16, 16> >(Eigen::DenseBase<Eigen::Matrix<double, 16, 16, 0, 16, 16> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 15, 1, 0, 15, 1> > const igl::matlab_format<Eigen::Matrix<double, 15, 1, 0, 15, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 15, 1, 0, 15, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 15, 15, 0, 15, 15> > const igl::matlab_format<Eigen::Matrix<double, 15, 15, 0, 15, 15> >(Eigen::DenseBase<Eigen::Matrix<double, 15, 15, 0, 15, 15> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 14, 1, 0, 14, 1> > const igl::matlab_format<Eigen::Matrix<double, 14, 1, 0, 14, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 14, 1, 0, 14, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 14, 14, 0, 14, 14> > const igl::matlab_format<Eigen::Matrix<double, 14, 14, 0, 14, 14> >(Eigen::DenseBase<Eigen::Matrix<double, 14, 14, 0, 14, 14> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 13, 1, 0, 13, 1> > const igl::matlab_format<Eigen::Matrix<double, 13, 1, 0, 13, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 13, 1, 0, 13, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 13, 13, 0, 13, 13> > const igl::matlab_format<Eigen::Matrix<double, 13, 13, 0, 13, 13> >(Eigen::DenseBase<Eigen::Matrix<double, 13, 13, 0, 13, 13> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 12, 1, 0, 12, 1> > const igl::matlab_format<Eigen::Matrix<double, 12, 1, 0, 12, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 12, 1, 0, 12, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 12, 12, 0, 12, 12> > const igl::matlab_format<Eigen::Matrix<double, 12, 12, 0, 12, 12> >(Eigen::DenseBase<Eigen::Matrix<double, 12, 12, 0, 12, 12> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 11, 1, 0, 11, 1> > const igl::matlab_format<Eigen::Matrix<double, 11, 1, 0, 11, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 11, 1, 0, 11, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 11, 11, 0, 11, 11> > const igl::matlab_format<Eigen::Matrix<double, 11, 11, 0, 11, 11> >(Eigen::DenseBase<Eigen::Matrix<double, 11, 11, 0, 11, 11> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 9, 18, 1, 9, 18> > const igl::matlab_format<Eigen::Matrix<double, 9, 18, 1, 9, 18> >(Eigen::DenseBase<Eigen::Matrix<double, 9, 18, 1, 9, 18> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 8, 16, 1, 8, 16> > const igl::matlab_format<Eigen::Matrix<double, 8, 16, 1, 8, 16> >(Eigen::DenseBase<Eigen::Matrix<double, 8, 16, 1, 8, 16> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 80, 160, 1, 80, 160> > const igl::matlab_format<Eigen::Matrix<double, 80, 160, 1, 80, 160> >(Eigen::DenseBase<Eigen::Matrix<double, 80, 160, 1, 80, 160> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 7, 14, 1, 7, 14> > const igl::matlab_format<Eigen::Matrix<double, 7, 14, 1, 7, 14> >(Eigen::DenseBase<Eigen::Matrix<double, 7, 14, 1, 7, 14> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 6, 12, 1, 6, 12> > const igl::matlab_format<Eigen::Matrix<double, 6, 12, 1, 6, 12> >(Eigen::DenseBase<Eigen::Matrix<double, 6, 12, 1, 6, 12> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 5, 10, 1, 5, 10> > const igl::matlab_format<Eigen::Matrix<double, 5, 10, 1, 5, 10> >(Eigen::DenseBase<Eigen::Matrix<double, 5, 10, 1, 5, 10> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 4, 8, 1, 4, 8> > const igl::matlab_format<Eigen::Matrix<double, 4, 8, 1, 4, 8> >(Eigen::DenseBase<Eigen::Matrix<double, 4, 8, 1, 4, 8> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 40, 80, 1, 40, 80> > const igl::matlab_format<Eigen::Matrix<double, 40, 80, 1, 40, 80> >(Eigen::DenseBase<Eigen::Matrix<double, 40, 80, 1, 40, 80> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 3, 6, 1, 3, 6> > const igl::matlab_format<Eigen::Matrix<double, 3, 6, 1, 3, 6> >(Eigen::DenseBase<Eigen::Matrix<double, 3, 6, 1, 3, 6> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 20, 40, 1, 20, 40> > const igl::matlab_format<Eigen::Matrix<double, 20, 40, 1, 20, 40> >(Eigen::DenseBase<Eigen::Matrix<double, 20, 40, 1, 20, 40> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 10, 20, 1, 10, 20> > const igl::matlab_format<Eigen::Matrix<double, 10, 20, 1, 10, 20> >(Eigen::DenseBase<Eigen::Matrix<double, 10, 20, 1, 10, 20> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 9, 9, 0, 9, 9> > const igl::matlab_format<Eigen::Matrix<double, 9, 9, 0, 9, 9> >(Eigen::DenseBase<Eigen::Matrix<double, 9, 9, 0, 9, 9> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 8, 8, 0, 8, 8> > const igl::matlab_format<Eigen::Matrix<double, 8, 8, 0, 8, 8> >(Eigen::DenseBase<Eigen::Matrix<double, 8, 8, 0, 8, 8> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 80, 80, 0, 80, 80> > const igl::matlab_format<Eigen::Matrix<double, 80, 80, 0, 80, 80> >(Eigen::DenseBase<Eigen::Matrix<double, 80, 80, 0, 80, 80> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 80, 1, 0, 80, 1> > const igl::matlab_format<Eigen::Matrix<double, 80, 1, 0, 80, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 80, 1, 0, 80, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 7, 7, 0, 7, 7> > const igl::matlab_format<Eigen::Matrix<double, 7, 7, 0, 7, 7> >(Eigen::DenseBase<Eigen::Matrix<double, 7, 7, 0, 7, 7> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 6, 6, 0, 6, 6> > const igl::matlab_format<Eigen::Matrix<double, 6, 6, 0, 6, 6> >(Eigen::DenseBase<Eigen::Matrix<double, 6, 6, 0, 6, 6> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 5, 5, 0, 5, 5> > const igl::matlab_format<Eigen::Matrix<double, 5, 5, 0, 5, 5> >(Eigen::DenseBase<Eigen::Matrix<double, 5, 5, 0, 5, 5> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 40, 40, 0, 40, 40> > const igl::matlab_format<Eigen::Matrix<double, 40, 40, 0, 40, 40> >(Eigen::DenseBase<Eigen::Matrix<double, 40, 40, 0, 40, 40> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 40, 1, 0, 40, 1> > const igl::matlab_format<Eigen::Matrix<double, 40, 1, 0, 40, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 40, 1, 0, 40, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 20, 20, 0, 20, 20> > const igl::matlab_format<Eigen::Matrix<double, 20, 20, 0, 20, 20> >(Eigen::DenseBase<Eigen::Matrix<double, 20, 20, 0, 20, 20> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 20, 1, 0, 20, 1> > const igl::matlab_format<Eigen::Matrix<double, 20, 1, 0, 20, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 20, 1, 0, 20, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 10, 10, 0, 10, 10> > const igl::matlab_format<Eigen::Matrix<double, 10, 10, 0, 10, 10> >(Eigen::DenseBase<Eigen::Matrix<double, 10, 10, 0, 10, 10> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 2, 4, 1, 2, 4> > const igl::matlab_format<Eigen::Matrix<double, 2, 4, 1, 2, 4> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 4, 1, 2, 4> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 2, 0, 1, 2, 0> > const igl::matlab_format<Eigen::Matrix<double, 2, 0, 1, 2, 0> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 0, 1, 2, 0> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 0, 1, 0, 0, 1> > const igl::matlab_format<Eigen::Matrix<double, 0, 1, 0, 0, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 0, 1, 0, 0, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 0, 0, 2, 0> > const igl::matlab_format<Eigen::Matrix<double, 2, 0, 0, 2, 0> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 0, 0, 2, 0> > const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 4, 0, 2, 4> > const igl::matlab_format<Eigen::Matrix<double, 2, 4, 0, 2, 4> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 4, 0, 2, 4> > const&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 9, 1, 0, 9, 1> > const igl::matlab_format<Eigen::Matrix<double, 9, 1, 0, 9, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 9, 1, 0, 9, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 8, 1, 0, 8, 1> > const igl::matlab_format<Eigen::Matrix<double, 8, 1, 0, 8, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 8, 1, 0, 8, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 7, 1, 0, 7, 1> > const igl::matlab_format<Eigen::Matrix<double, 7, 1, 0, 7, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 7, 1, 0, 7, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 6, 1, 0, 6, 1> > const igl::matlab_format<Eigen::Matrix<double, 6, 1, 0, 6, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 6, 1, 0, 6, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 5, 1, 0, 5, 1> > const igl::matlab_format<Eigen::Matrix<double, 5, 1, 0, 5, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 5, 1, 0, 5, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 4, 1, 0, 4, 1> > const igl::matlab_format<Eigen::Matrix<double, 4, 1, 0, 4, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 4, 1, 0, 4, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 10, 1, 0, 10, 1> > const igl::matlab_format<Eigen::Matrix<double, 10, 1, 0, 10, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 10, 1, 0, 10, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 99, 99, 0, 99, 99> > const igl::matlab_format<Eigen::Matrix<double, 99, 99, 0, 99, 99> >(Eigen::DenseBase<Eigen::Matrix<double, 99, 99, 0, 99, 99> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
// generated by autoexplicit.sh
template Eigen::WithFormat<Eigen::Matrix<double, 99, 1, 0, 99, 1> > const igl::matlab_format<Eigen::Matrix<double, 99, 1, 0, 99, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 99, 1, 0, 99, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template std::basic_string<char, std::char_traits<char>, std::allocator<char> > igl::matlab_format_index<Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template std::basic_string<char, std::char_traits<char>, std::allocator<char> > igl::matlab_format_index<Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::MatrixBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
///////////////////////////////////////////////////
template Eigen::WithFormat<Eigen::Array<int, -1, 3, 0, -1, 3> > const igl::matlab_format<Eigen::Array<int, -1, 3, 0, -1, 3> >(Eigen::DenseBase<Eigen::Array<int, -1, 3, 0, -1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3> > const igl::matlab_format<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3> >(Eigen::DenseBase<Eigen::Matrix<unsigned int, -1, 3, 1, -1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, 3, 1, -1, 3> > const igl::matlab_format<Eigen::Matrix<int, -1, 3, 1, -1, 3> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 3, 1, -1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
#if EIGEN_VERSION_AT_LEAST(3,3,0)
#else
template Eigen::WithFormat<Eigen::CwiseUnaryOp<Eigen::internal::scalar_cast_op<bool, int>, Eigen::Matrix<bool, -1, 3, 0, -1, 3> const> > const igl::matlab_format<Eigen::CwiseUnaryOp<Eigen::internal::scalar_cast_op<bool, int>, Eigen::Matrix<bool, -1, 3, 0, -1, 3> const> >(Eigen::DenseBase<Eigen::CwiseUnaryOp<Eigen::internal::scalar_cast_op<bool, int>, Eigen::Matrix<bool, -1, 3, 0, -1, 3> const> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> const> const> > const igl::matlab_format<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> const> const> >(Eigen::DenseBase<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> const> const> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const> > const igl::matlab_format<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const> >(Eigen::DenseBase<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const> > const igl::matlab_format<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const> >(Eigen::DenseBase<Eigen::CwiseUnaryOp<Eigen::internal::scalar_add_op<int>, Eigen::ArrayWrapper<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, 3, 1, 0, 3, 1> > const igl::matlab_format<Eigen::Matrix<float, 3, 1, 0, 3, 1> >(Eigen::DenseBase<Eigen::Matrix<float, 3, 1, 0, 3, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Transpose<Eigen::Block<Eigen::Matrix<float, 4, 4, 0, 4, 4>, -1, -1, false> > > const igl::matlab_format<Eigen::Transpose<Eigen::Block<Eigen::Matrix<float, 4, 4, 0, 4, 4>, -1, -1, false> > >(Eigen::DenseBase<Eigen::Transpose<Eigen::Block<Eigen::Matrix<float, 4, 4, 0, 4, 4>, -1, -1, false> > > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Transpose<Eigen::Matrix<float, 3, 1, 0, 3, 1> > > const igl::matlab_format<Eigen::Transpose<Eigen::Matrix<float, 3, 1, 0, 3, 1> > >(Eigen::DenseBase<Eigen::Transpose<Eigen::Matrix<float, 3, 1, 0, 3, 1> > > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
#endif
template Eigen::WithFormat<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const igl::matlab_format<Eigen::Matrix<float, 1, 3, 1, 1, 3> >(Eigen::DenseBase<Eigen::Matrix<float, 1, 3, 1, 1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, 4, 1, 0, 4, 1> > const igl::matlab_format<Eigen::Matrix<int, 4, 1, 0, 4, 1> >(Eigen::DenseBase<Eigen::Matrix<int, 4, 1, 0, 4, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template std::basic_string<char, std::char_traits<char>, std::allocator<char> > const igl::matlab_format<double>(Eigen::SparseMatrix<double, 0, int> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const igl::matlab_format<Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, std::string);
template Eigen::WithFormat<Eigen::Array<int, -1, -1, 0, -1, -1> > const igl::matlab_format<Eigen::Array<int, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Array<int, -1, -1, 0, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const igl::matlab_format<Eigen::Matrix<int, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Matrix<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Matrix<double, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Array<int, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Array<int, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Array<int, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 4, 4, 0, 4, 4> > const igl::matlab_format<Eigen::Matrix<double, 4, 4, 0, 4, 4> >(Eigen::DenseBase<Eigen::Matrix<double, 4, 4, 0, 4, 4> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, 4, 0, -1, 4> > const igl::matlab_format<Eigen::Matrix<double, -1, 4, 0, -1, 4> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 4, 0, -1, 4> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, 2, 0, -1, 2> > const igl::matlab_format<Eigen::Matrix<double, -1, 2, 0, -1, 2> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 2, 0, -1, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 1, 0, 2, 1> > const igl::matlab_format<Eigen::Matrix<double, 2, 1, 0, 2, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 1, 0, 2, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, 1, -1, 1, 1, -1> > const igl::matlab_format<Eigen::Matrix<int, 1, -1, 1, 1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, 1, -1, 1, 1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 1, -1, 1, 1, -1> > const igl::matlab_format<Eigen::Matrix<double, 1, -1, 1, 1, -1> >(Eigen::DenseBase<Eigen::Matrix<double, 1, -1, 1, 1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 3, 3, 0, 3, 3> > const igl::matlab_format<Eigen::Matrix<double, 3, 3, 0, 3, 3> >(Eigen::DenseBase<Eigen::Matrix<double, 3, 3, 0, 3, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 2, 0, 2, 2> > const igl::matlab_format<Eigen::Matrix<double, 2, 2, 0, 2, 2> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 2, 0, 2, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, 2, 2, 0, 2, 2> > const igl::matlab_format<Eigen::Matrix<float, 2, 2, 0, 2, 2> >(Eigen::DenseBase<Eigen::Matrix<float, 2, 2, 0, 2, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 2, 1, 2, 2> > const igl::matlab_format<Eigen::Matrix<double, 2, 2, 1, 2, 2> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 2, 1, 2, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 3, 1, 0, 3, 1> > const igl::matlab_format<Eigen::Matrix<double, 3, 1, 0, 3, 1> >(Eigen::DenseBase<Eigen::Matrix<double, 3, 1, 0, 3, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, 2, 1, 0, 2, 1> > const igl::matlab_format<Eigen::Matrix<float, 2, 1, 0, 2, 1> >(Eigen::DenseBase<Eigen::Matrix<float, 2, 1, 0, 2, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, 2, 2, 1, 2, 2> > const igl::matlab_format<Eigen::Matrix<float, 2, 2, 1, 2, 2> >(Eigen::DenseBase<Eigen::Matrix<float, 2, 2, 1, 2, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, -1, -1, 0, -1, -1> > const igl::matlab_format<Eigen::Matrix<float, -1, -1, 0, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<float, -1, -1, 0, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 3, 3, 1, 3, 3> > const igl::matlab_format<Eigen::Matrix<double, 3, 3, 1, 3, 3> >(Eigen::DenseBase<Eigen::Matrix<double, 3, 3, 1, 3, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, -1, 1, -1, -1> > const igl::matlab_format<Eigen::Matrix<double, -1, -1, 1, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<double, -1, -1, 1, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, -1, 1, -1, -1> > const igl::matlab_format<Eigen::Matrix<int, -1, -1, 1, -1, -1> >(Eigen::DenseBase<Eigen::Matrix<int, -1, -1, 1, -1, -1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Array<double, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Array<double, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Array<double, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const igl::matlab_format<Eigen::Matrix<double, 1, 3, 1, 1, 3> >(Eigen::DenseBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const igl::matlab_format<Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::DenseBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, 2, 0, -1, 2> > const igl::matlab_format<Eigen::Matrix<int, -1, 2, 0, -1, 2> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 2, 0, -1, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const igl::matlab_format<Eigen::Matrix<int, -1, 3, 0, -1, 3> >(Eigen::DenseBase<Eigen::Matrix<int, -1, 3, 0, -1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const igl::matlab_format<Eigen::Matrix<double, -1, 3, 0, -1, 3> >(Eigen::DenseBase<Eigen::Matrix<double, -1, 3, 0, -1, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 2, 3, 0, 2, 3> > const igl::matlab_format<Eigen::Matrix<double, 2, 3, 0, 2, 3> >(Eigen::DenseBase<Eigen::Matrix<double, 2, 3, 0, 2, 3> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<double, 3, 2, 0, 3, 2> > const igl::matlab_format<Eigen::Matrix<double, 3, 2, 0, 3, 2> >(Eigen::DenseBase<Eigen::Matrix<double, 3, 2, 0, 3, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Matrix<float, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<float, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<int, 2, 2, 0, 2, 2> > const igl::matlab_format<Eigen::Matrix<int, 2, 2, 0, 2, 2> >(Eigen::DenseBase<Eigen::Matrix<int, 2, 2, 0, 2, 2> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<float, 4, 4, 0, 4, 4> > const igl::matlab_format<Eigen::Matrix<float, 4, 4, 0, 4, 4> >(Eigen::DenseBase<Eigen::Matrix<float, 4, 4, 0, 4, 4> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
template Eigen::WithFormat<Eigen::Matrix<bool, -1, 1, 0, -1, 1> > const igl::matlab_format<Eigen::Matrix<bool, -1, 1, 0, -1, 1> >(Eigen::DenseBase<Eigen::Matrix<bool, -1, 1, 0, -1, 1> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> >);
#endif
