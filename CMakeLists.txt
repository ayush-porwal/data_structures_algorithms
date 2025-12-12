cmake_minimum_required(VERSION 4.1.0)
project(data_structures_algorithms VERSION 0.1.0 LANGUAGES CXX)

# set C++ standard globally
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include template directory for all targets
# include_directories(${CMAKE_SOURCE_DIR}/template)

# Function to build a specific file with a unique target name
function(build_specific_file FILE_PATH)
    if(EXISTS "${FILE_PATH}")
        # Create a unique target name based on the relative path
        file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${FILE_PATH})
        string(REPLACE "/" "_" TARGET_NAME ${REL_PATH})
        string(REPLACE ".cpp" "" TARGET_NAME ${TARGET_NAME})
        # Remove spaces, dots and other special characters from target name
        string(REGEX REPLACE "[^a-zA-Z0-9_]" "_" TARGET_NAME ${TARGET_NAME})
        
        # Also get the filename for the output binary
        get_filename_component(FILE_NAME ${FILE_PATH} NAME_WE)
        
        # Add the executable with the unique target name
        add_executable(${TARGET_NAME} ${FILE_PATH})
        
        # Set the output name to match the file name
        set_target_properties(${TARGET_NAME} PROPERTIES OUTPUT_NAME "${FILE_NAME}")

        # Add include directories for templates
        target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/template)
    endif()
endfunction()

# Variable to specify which file to build
# Usage: cmake -DFILE_TO_BUILD=/path/to/your/file.cpp ..
if(DEFINED FILE_TO_BUILD)
    build_specific_file(${FILE_TO_BUILD})
endif()

# If no specific file is provided, build main.cpp if it exists
if(NOT DEFINED FILE_TO_BUILD AND EXISTS "${CMAKE_SOURCE_DIR}/main.cpp")
    build_specific_file("${CMAKE_SOURCE_DIR}/main.cpp")
endif()

