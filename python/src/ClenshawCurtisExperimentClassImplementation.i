// SWIG file ClenshawCurtisExperimentClassImplementation.i

%{
#include "clenshawcurtisexperiment/ClenshawCurtisExperimentClassImplementation.hxx"
%}

%include ClenshawCurtisExperimentClassImplementation_doc.i

%template(ClenshawCurtisExperimentClassImplementationdInterfaceObject)           OT::TypedInterfaceObject<CLENSHAWCURTISEXPERIMENT::ClenshawCurtisExperimentClassImplementation>;

%include clenshawcurtisexperiment/ClenshawCurtisExperimentClassImplementation.hxx
namespace CLENSHAWCURTISEXPERIMENT { %extend ClenshawCurtisExperimentClassImplementation { ClenshawCurtisExperimentClassImplementation(const ClenshawCurtisExperimentClassImplementation & other) { return new CLENSHAWCURTISEXPERIMENT::ClenshawCurtisExperimentClassImplementation(other); } } }
