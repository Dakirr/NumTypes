cmake_minimum_required(VERSION 3.5)	 
project(pi_calculation)			

set(SOURCE_PI pi.cpp)		
set(SOURCE_LIB mathlib.h LLL.h LLL.cpp frac.h frac.cpp)
set(SOURCE_TESTING test_frac.cpp)		

add_library(Frac_Lib STATIC ${SOURCE_LIB})


add_executable(Pi_Calc ${SOURCE_PI})	
set_target_properties(
	Pi_Calc PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_link_libraries(Pi_Calc Frac_Lib)

add_executable(Testing ${SOURCE_TESTING})	
set_target_properties(
	Testing PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

