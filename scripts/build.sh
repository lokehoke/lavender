set -e

conan install -if=out -b=missing -s build_type=Debug -s cppstd=17 -s \
    compiler=gcc -s compiler.version=8 -s compiler.libcxx=libstdc++11 -e CC=gcc-8 -e CXX=g++-8 .

conan build -if=out -bf=out .
conan package -if=out -bf=out -pf=dist .
