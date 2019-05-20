// SWIG file ClenshawCurtisExperimentClass.i

%{
#include "clenshawcurtisexperiment/ClenshawCurtisExperimentClass.hxx"
%}

%include ClenshawCurtisExperimentClass_doc.i

TypedInterfaceObjectImplementationHelper(CLENSHAWCURTISEXPERIMENT, ClenshawCurtisExperimentClass, ClenshawCurtisExperimentClassImplementation)

%include clenshawcurtisexperiment/ClenshawCurtisExperimentClass.hxx
namespace CLENSHAWCURTISEXPERIMENT { %extend ClenshawCurtisExperimentClass { ClenshawCurtisExperimentClass(const ClenshawCurtisExperimentClass & other) { return new CLENSHAWCURTISEXPERIMENT::ClenshawCurtisExperimentClass(other); } } }
