cmake_minimum_required(VERSION 3.25)
project(Cipher_App)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cipher_App
        All_Ciphers.cpp AffineCipher.h AtbashCipher.h)
