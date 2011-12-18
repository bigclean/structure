### CMakeLists.txt --- 
## 
## Filename: CMakeLists.txt
## Description: CMakeLists for structure
## Author: bigclean
## Created: Aug 25 2010 16:36
## Last-Updated: Aug 27 2010 10:47
### Code:

cmake_minimum_required( VERSION 2.6 )
PROJECT( structure )
# TODO: add nmake support for vs
IF(WIN32)
    MESSAGE(STATUS "Please use Unix Makefile generator. ")
    MESSAGE(STATUS "Windows always be so devil. ")
ENDIF(WIN32)

# variable settings
SET(DOXYFILE ${PROJECT_NAME}.Doxyfile)
# CGLAGS and CPPFLAGS
SET(CMAKE_C_FLAGS "-W -Wall")

# head file directory
INCLUDE_DIRECTORIES( include )
AUX_SOURCE_DIRECTORY(. DIR_SAMPLE_SRCS)
ADD_EXECUTABLE(test ${DIR_SAMPLE_SRCS})

MESSAGE(STATUS "Using FindDoxygen.cmake module. ")
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
    MESSAGE(STATUS "Generating documents.")
    # XXX: improve doxygen integration
    ADD_CUSTOM_TARGET(doc COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
                      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                      COMMENT "Now generating document via doxygen...")
ELSE(DOXYGEN_FOUND)
    MESSAGE(SEND_ERROR "Doxygen not found, step of generating
                       document is skipped. ")
ENDIF(DOXYGEN_FOUND)

######################################################################
### CMakeLists.txt ends here
