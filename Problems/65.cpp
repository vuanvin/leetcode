#include <leetcode.h>

class Solution {
public:
    enum class State { BEGIN, INT_SIG, INT_NUM, DOT_NOT_INT, DOT_SYM, DOT_NUM, EXP_SYM, EXP_SIG, EXP_NUM, END };
    enum class CharType { DIG, EXP, DOT, SIG, ILL };
    CharType toCharType(char ch) {
        if (isdigit(ch)) {
            return CharType::DIG;
        } else if (ch == 'e' || ch == 'E') {
            return CharType::EXP;
        } else if (ch == '.') {
            return CharType::DOT;
        } else if (ch == '+' || ch == '-') {
            return CharType::SIG;
        }
        return CharType::ILL;
    }
    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {State::BEGIN, {{CharType::DIG, State::INT_NUM}, {CharType::DOT, State::DOT_NOT_INT}, {CharType::SIG, State::INT_SIG}}},
            {State::INT_SIG, {{CharType::DIG, State::INT_NUM}, {CharType::DOT, State::DOT_NOT_INT}}},
            {State::INT_NUM, {{CharType::DIG, State::INT_NUM}, {CharType::EXP, State::EXP_SYM}, {CharType::DOT, State::DOT_SYM}}},
            {State::DOT_NOT_INT, {{CharType::DIG, State::DOT_NUM}}},
            {State::DOT_SYM, {{CharType::DIG, State::DOT_NUM}, {CharType::EXP, State::EXP_SYM}}},
            {State::DOT_NUM, {{CharType::DIG, State::DOT_NUM}, {CharType::EXP, State::EXP_SYM}}},
            {State::EXP_SYM, {{CharType::DIG, State::EXP_NUM}, {CharType::SIG, State::EXP_SIG}}},
            {State::EXP_SIG, {{CharType::DIG, State::EXP_NUM}}},
            {State::EXP_NUM, {{CharType::DIG, State::EXP_NUM}}}};
        State state = State::BEGIN;
        for (auto ch : s) {
            auto char_type = toCharType(ch);
            if (transfer[state].count(char_type)) {
                state = transfer[state][char_type];
            } else {
                return false;
            }
        }
        return state == State::INT_NUM || state == State::DOT_SYM || state == State::DOT_NUM || state == State::EXP_NUM || state == State::END;
    }
};