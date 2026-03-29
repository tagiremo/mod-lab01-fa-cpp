// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    if (!str) return 0;

    unsigned int count = 0;
    bool word_started = false;
    bool has_digit = false;

    for (; *str; ++str) {
        if (std::isspace(*str)) {
            if (word_started && !has_digit) ++count;
            word_started = false;
            has_digit = false;
        } else {
            if (!word_started) word_started = true;
            if (std::isdigit(*str)) has_digit = true;
        }
    }

    if (word_started && !has_digit) ++count;
    return count;
}

unsigned int faStr2(const char *str) {
    if (!str) return 0;

    unsigned int count = 0;
    bool in_word = false;
    bool valid = false;

    for (; *str; ++str) {
        if (std::isspace(*str)) {
            if (in_word && valid) ++count;
            in_word = false;
            valid = false;
        } else {
            if (!in_word) {
                in_word = true;
                valid = std::isupper(*str);
            } else if (valid) {
                valid = std::islower(*str);
            }
        }
    }

    if (in_word && valid) ++count;
    return count;
}

unsigned int faStr3(const char *str) {
    if (!str) return 0;

    unsigned int words = 0, total_len = 0, len = 0;
    bool in_word = false;

    for (; *str; ++str) {
        if (std::isspace(*str)) {
            if (in_word) {
                ++words;
                total_len += len;
                len = 0;
                in_word = false;
            }
        } else {
            if (!in_word) in_word = true;
            ++len;
        }
    }

    if (in_word) {
        ++words;
        total_len += len;
    }

    if (words == 0)
    return 0;
    else
    return static_cast<unsigned int>(static_cast<double>(total_len)/words+0.5);

}
