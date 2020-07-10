# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

#set(CMAKE_C_COMPILER_WORKS ${CMAKE_C_COMPILER_WORKS})
# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

file(GLOB SOURCES
        "native-lib.cpp"
        "IRgByPixelisation/videoProcessingCL.cpp"
        "IRgByPixelisation/cvMatToArrayTocvMat.cpp"
        "IRgByPixelisation/faceDetectionVJ.cpp"
        "IRgByPixelisation/extractRoiFromImage.c"
        "IRgByPixelisation/ReadModel.c"
        "IRgByPixelisation/extractRoiFromImage.c"
        "IRgByPixelisation/NAFFD_ACCv6.c"
        )




include_directories(${OpenCV_DIR}/jni/include)
include_directories(${OpenCL_DIR}/include)

add_library(libOpenCL SHARED IMPORTED)
add_library( lib_opencv SHARED IMPORTED )
#add_library( libcutils SHARED IMPORTED )
add_library( libCB SHARED IMPORTED )

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${OpenCV_DIR}/libs/${ANDROID_ABI}/libopencv_java4.so)
set_target_properties(libOpenCL PROPERTIES IMPORTED_LOCATION ${OpenCL_DIR}/lib64/libOpenCL.so)
#set_target_properties(libcutils PROPERTIES IMPORTED_LOCATION ${NativeCopy_DIR}/libcutils.so)
set_target_properties(libCB PROPERTIES IMPORTED_LOCATION ${OpenCL_DIR}/lib64/libCB.so)


#add_library( # Sets the name of the library.
#             native-lib
#
#             # Sets the library as a shared library.
#             SHARED
#
#             # Provides a relative path to your source file(s).
#             native-lib.cpp )

add_library( native-lib SHARED ${SOURCES})
#add_library( naffd-lib  SHARED IRgByPixelisation/videoProcessing.cpp)


#message ("boost found")
#message("${CMAKE_CURRENT_BINARY_DIR}")

#add_library(opencl-lib INTERFACE)
#target_include_directories(opencl-lib INTERFACE )
#target_include_directories(opencl-lib PRIVATE "${CMAKE_CURRENT_BINARY_DIR}")
#set(SOURCES CL/*.h)
#add_executable(opencl-lib ${SOURCES})
# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log
        )


# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#


target_link_libraries( # Specifies the target library.
                       native-lib
                         libOpenCL
                         libCB
#                        libcutils
                       lib_opencv
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                                )

