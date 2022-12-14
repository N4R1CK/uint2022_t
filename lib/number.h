#pragma once
#include <cinttypes>
#include <iostream>
#include <cmath>
#include <vector> 
#include <ctime>
#include <stack>
#include <cstdio>
#include <algorithm>



struct uint2022_t {
    /*
    будем хранить число справа налево, т.е. чем больше
    block_id, тем больше число
    123 = 01111011 -> big_uint[0] = 11011110
    
    253 блока по 8 бит = 2024 бит -> 0 <= first_non_zero_bit <= 2023
    
    каждый блок - число в 8 бит, т.е. с каждым битом можно работать так:
    I. Узнать, что стоит на k-том бите одного блока
        1) = big_uint[i] & kBitByID[0];     // 128 = 0b10000000
        2) = big_uint[i] & kBitByID[1];     //  64 = 0b01000000
        3) = big_uint[i] & kBitByID[2];     //  32 = 0b00100000
        4) = big_uint[i] & kBitByID[3];     //  16 = 0b00010000
        5) = big_uint[i] & kBitByID[4];     //   8 = 0b00001000
        6) = big_uint[i] & kBitByID[5];     //   4 = 0b00000100
        7) = big_uint[i] & kBitByID[6];     //   2 = 0b00000010
        8) = big_uint[i] & kBitByID[7];     //   1 = 0b00000001

    II. Узнать k-ый бит всего числа:
        1) узнаем блок, в котором этот бит:
        block = big_uint[k / 8];
        2) узнаем номер бита:
        bit_id = (k & 7); 
        3) узнаем значение бита месте по пункту I:
        = block & kBitByID[bit_id];
    */
    uint8_t* big_uint = nullptr;
    uint16_t size_in_bytes;
    uint16_t size_in_bits;

    uint16_t first_non_zero_bit;

    uint2022_t(const uint16_t& cnt_bits = 2022) {
        size_in_bits = cnt_bits;
        size_in_bytes = ((cnt_bits + 7) >> 3);
        big_uint = new uint8_t[size_in_bytes];
        for (uint16_t i = 0; i < size_in_bytes; ++i) {
            big_uint[i] = 0;
        }
        first_non_zero_bit = 0;
    }

    uint2022_t(const uint2022_t& other) {
        size_in_bits = other.size_in_bits;
        size_in_bytes = other.size_in_bytes;
        big_uint = new uint8_t[size_in_bytes];
        for (uint16_t i = 0; i < size_in_bytes; ++i) {
            big_uint[i] = other.big_uint[i];
        }
        first_non_zero_bit = other.first_non_zero_bit;
    }

    ~uint2022_t() {
        if (big_uint != nullptr) {
            delete[] big_uint;
        }
    }

    uint2022_t& operator=(const uint2022_t& other) {
        if (other.big_uint != big_uint) { 
            delete[] big_uint;
            size_in_bits = other.size_in_bits;
            size_in_bytes = other.size_in_bytes;
            big_uint = new uint8_t[size_in_bytes];
            first_non_zero_bit = other.first_non_zero_bit;
            for (uint16_t i = 0; i < size_in_bytes; ++i) {
                big_uint[i] = other.big_uint[i];
            }
        }
        return *this;
    }

    
};

void EXTRACOUT(const uint2022_t& a);

static_assert(sizeof(uint2022_t) <= 300, "Size of uint2022_t must be no higher than 300 bytes");

uint2022_t from_uint(uint32_t i);

uint2022_t from_string(const char* buff);

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs);

uint2022_t operator<<(const uint2022_t& value, const uint16_t& len);

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs);

std::pair <uint2022_t, uint2022_t> DivisionWithRemainder(const uint2022_t& lhs, const uint2022_t& rhs);

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs);

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs);

bool operator>(const uint2022_t& lhs, const uint2022_t& rhs);

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value);
