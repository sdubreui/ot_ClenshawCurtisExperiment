

ot_add_current_dir_to_include_dirs ()

ot_add_source_file ( ClenshawCurtisExperimentClass.cxx )


ot_install_header_file ( ClenshawCurtisExperimentClass.hxx )



include_directories (${INTERNAL_INCLUDE_DIRS})

add_library (clenshawcurtisexperiment ${SOURCEFILES})
set_target_properties (clenshawcurtisexperiment PROPERTIES POSITION_INDEPENDENT_CODE ON)
if (BUILD_SHARED_LIBS)
  set_target_properties (clenshawcurtisexperiment PROPERTIES COMPILE_DEFINITIONS "CLENSHAWCURTISEXPERIMENT_DLL_EXPORTS")
endif ()

if ( NOT DEFINED LIB_VERSION ) 
  set ( LIB_VERSION 0.0.0 )
endif ()
if ( NOT DEFINED LIB_SOVERSION ) 
  set ( LIB_SOVERSION 0 )
endif ()
set_target_properties ( clenshawcurtisexperiment PROPERTIES VERSION ${LIB_VERSION} )
set_target_properties ( clenshawcurtisexperiment PROPERTIES SOVERSION ${LIB_SOVERSION} )
target_link_libraries (clenshawcurtisexperiment ${OPENTURNS_LIBRARY})

# Add targets to the build-tree export set
export (TARGETS clenshawcurtisexperiment FILE ${PROJECT_BINARY_DIR}/ClenshawCurtisExperiment-Targets.cmake)

# Install the export set for use with the install-tree
install(EXPORT ClenshawCurtisExperiment-Targets
        DESTINATION "${CLENSHAWCURTISEXPERIMENT_CONFIG_CMAKE_PATH}"
        COMPONENT Development)

install(TARGETS clenshawcurtisexperiment
        EXPORT  ClenshawCurtisExperiment-Targets 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CLENSHAWCURTISEXPERIMENT_LIBRARY_PATH}
        ARCHIVE DESTINATION ${CLENSHAWCURTISEXPERIMENT_LIBRARY_PATH}
)

