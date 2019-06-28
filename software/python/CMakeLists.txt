set(PYTHON_C_EXTENSION_SRCS
    "laser.c"
)

#add_library(python_c_extension SHARED ${PYTHON_C_EXTENSION_SRCS})
Python3_add_library (python_c_extension MODULE ${PYTHON_C_EXTENSION_SRCS})

# set_target_properties(
#     python_c_extension
#     PROPERTIES
#         PREFIX ""
#         OUTPUT_NAME ${PIFINDER_PYTHON_C_MODULE_NAME}
#         LINKER_LANGUAGE C
# )

if(WIN32)
    set_target_properties(
        python_c_extension
        PROPERTIES
        SUFFIX ".pyd"
    )   
endif()

# target_include_directories(python_c_extension PUBLIC
#     ${PYTHON_INCLUDE_DIRS}
#     )

# target_link_libraries(python_c_extension
    
#     ${PYTHON_LIBRARIES}
# )

