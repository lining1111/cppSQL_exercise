# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/module-SQLite3-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${sqlite3_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${SQLite3_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET SQLite::SQLite3)
    add_library(SQLite::SQLite3 INTERFACE IMPORTED)
    message(${SQLite3_MESSAGE_MODE} "Conan: Target declared 'SQLite::SQLite3'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/module-SQLite3-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()