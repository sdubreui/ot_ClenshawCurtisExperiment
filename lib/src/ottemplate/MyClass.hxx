//                                               -*- C++ -*-
/**
 *  @brief MyClass
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OTTEMPLATE_MYCLASS_HXX
#define OTTEMPLATE_MYCLASS_HXX

#include <TypedInterfaceObject.hxx>
#include <StorageManager.hxx>
#include <NumericalPoint.hxx>
#include "ottemplate/OTTemplateprivate.hxx"

namespace OTTEMPLATE
{

/* forward declaration */
class MyClassImplementation;

/**
 * @class MyClass
 *
 * MyClass is some myclass type to illustrate how to add some classes in Open TURNS
 */
class OTTEMPLATE_API MyClass
  : public OT::TypedInterfaceObject<MyClassImplementation>
{
  CLASSNAME;

public:

  /** Default constructor */
  MyClass();

  /** Constructor from implementation */
  MyClass(const MyClassImplementation & implementation);

  /** a func that return a point squared. **/
  OT::NumericalPoint square(OT::NumericalPoint& p) const;

  /** String converter */
  OT::String __repr__() const;

private:

}; /* class MyClass */

} /* namespace OTTEMPLATE */

#endif /* OTTEMPLATE_MYCLASS_HXX */
