cmake_minimum_required(VERSION 3.16)
project(WideOpenFHE VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# Find OpenFHE
find_path(OPENFHE_INC openfhe.h PATHS 
    ${CMAKE_SOURCE_DIR}/include/openfhe
    /usr/local/include/openfhe/pke
    /usr/local/openfhe/include/openfhe/pke
)

find_library(OPENFHE_PKE OPENFHEpke PATHS 
    /usr/local/openfhe/lib 
    /usr/local/lib
)

find_library(OPENFHE_CORE OPENFHEcore PATHS 
    /usr/local/openfhe/lib 
    /usr/local/lib
)

if(OPENFHE_PKE AND OPENFHE_CORE)
    message(STATUS "✅ OpenFHE found!")
    include_directories(${OPENFHE_INC})
    
    # Our main library
    add_library(wideopenfhe STATIC 
        src/wideopenfhe.cpp
    )
    target_link_libraries(wideopenfhe ${OPENFHE_PKE} ${OPENFHE_CORE})
    
    # Test
    add_executable(test_wide test_wide.cpp)
    target_link_libraries(test_wide wideopenfhe ${OPENFHE_PKE} ${OPENFHE_CORE})
else()
    message(WARNING "⚠️ OpenFHE libraries not found. Header-only mode.")
endif()
