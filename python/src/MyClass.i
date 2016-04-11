// SWIG file MyClass.i

%{
#include "ottemplate/MyClass.hxx"
%}

%include MyClass_doc.i

TypedInterfaceObjectImplementationHelper(OTTEMPLATE, MyClass, MyClassImplementation)

%include ottemplate/MyClass.hxx
namespace OTTEMPLATE { %extend MyClass { MyClass(const MyClass & other) { return new OTTEMPLATE::MyClass(other); } } }
