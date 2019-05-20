// SWIG file clenshawcurtisexperiment_module.i

%module(docstring="clenshawcurtisexperiment module") clenshawcurtisexperiment

%{
#include <openturns/OT.hxx>
#include <openturns/PythonWrappingFunctions.hxx>
%}

// Prerequisites needed
%include typemaps.i
%include exception.i
%ignore *::load(OT::Advocate & adv);
%ignore *::save(OT::Advocate & adv) const;

%import base_module.i
%import uncertainty_module.i

// The new classes
%include clenshawcurtisexperiment/ClenshawCurtisExperimentprivate.hxx
%include ClenshawCurtisExperimentClassImplementation.i
%include ClenshawCurtisExperimentClass.i


