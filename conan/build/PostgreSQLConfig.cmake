########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(PostgreSQL_FIND_QUIETLY)
    set(PostgreSQL_MESSAGE_MODE VERBOSE)
else()
    set(PostgreSQL_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/PostgreSQLTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${libpq_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(PostgreSQL_VERSION_STRING "15.4")
set(PostgreSQL_INCLUDE_DIRS ${libpq_INCLUDE_DIRS_DEBUG} )
set(PostgreSQL_INCLUDE_DIR ${libpq_INCLUDE_DIRS_DEBUG} )
set(PostgreSQL_LIBRARIES ${libpq_LIBRARIES_DEBUG} )
set(PostgreSQL_DEFINITIONS ${libpq_DEFINITIONS_DEBUG} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${libpq_BUILD_MODULES_PATHS_DEBUG} )
    message(${PostgreSQL_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


