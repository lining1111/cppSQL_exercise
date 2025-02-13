# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/rapidxml-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${rapidxml_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${rapidxml_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET rapidxml::rapidxml)
    add_library(rapidxml::rapidxml INTERFACE IMPORTED)
    message(${rapidxml_MESSAGE_MODE} "Conan: Target declared 'rapidxml::rapidxml'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/rapidxml-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()