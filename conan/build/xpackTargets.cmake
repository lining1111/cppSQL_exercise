# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/xpack-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${xpack_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${xpack_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET xpack::xpack)
    add_library(xpack::xpack INTERFACE IMPORTED)
    message(${xpack_MESSAGE_MODE} "Conan: Target declared 'xpack::xpack'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/xpack-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()