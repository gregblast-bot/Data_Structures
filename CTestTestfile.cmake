# CMake generated Testfile for 
# Source directory: /home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4
# Build directory: /home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(student-tests "student-tests")
add_test(test00 "pathfinder" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/maze00.png" "output00.png")
add_test(test00-compare "compare" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/output00.png" "output00.png")
add_test(test01 "pathfinder" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/maze01.png" "output01.png")
add_test(test01-compare "compare" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/output01.png" "output01.png")
add_test(test02 "pathfinder" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/maze02.png" "output02.png")
add_test(test02-compare "compare" "/home/tailor/Desktop/$Ch00L/Data Structures and Algorithms/Projects/P4/tests/output02.png" "output02.png")
subdirs("lib")
