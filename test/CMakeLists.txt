LIST(TRANSFORM SRC_FILES PREPEND ../)

add_executable(ch1 select/ch1.cpp ${SRC_FILES})
target_link_libraries(ch1 ${LIBS})

add_executable(ch2 select/ch2.cpp ${SRC_FILES})
target_link_libraries(ch2 ${LIBS})

add_executable(ch3 select/ch3.cpp ${SRC_FILES})
target_link_libraries(ch3 ${LIBS})

add_executable(ch4 select/ch4.cpp ${SRC_FILES})
target_link_libraries(ch4 ${LIBS})

add_executable(ch5 select/ch5.cpp ${SRC_FILES})
target_link_libraries(ch5 ${LIBS})

add_executable(ch6 select/ch6.cpp ${SRC_FILES})
target_link_libraries(ch6 ${LIBS})

add_executable(ch7 select/ch7.cpp ${SRC_FILES})
target_link_libraries(ch7 ${LIBS})

add_executable(ch8 insert/ch8.cpp ${SRC_FILES})
target_link_libraries(ch8 ${LIBS})

add_executable(ch9 update/ch9.cpp ${SRC_FILES})
target_link_libraries(ch9 ${LIBS})

add_executable(ch10 delete/ch10.cpp ${SRC_FILES})
target_link_libraries(ch10 ${LIBS})

add_executable(condition condition.cpp ${SRC_FILES})
target_link_libraries(condition ${LIBS})