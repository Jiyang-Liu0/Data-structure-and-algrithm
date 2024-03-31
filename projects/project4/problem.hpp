#ifndef _PROBLEM_HPP_
#define _PROBLEM_HPP_

#include "lib/image.h"
#include <vector>

struct State
{
    int row_idx;
    int col_idx;
    Pixel pixel;
    // bool operator<(const State& other) const {
    //     return row_idx < other.row_idx || (row_idx == other.row_idx && col_idx < other.col_idx);
    // }
};

template <typename T>
class Problem
{
public:
    Problem();
    Problem(const Image<T>& image);
    State initial();
    bool goal(const State state);
    std::vector<State> actions(const State state);
    bool isValid();
private:
    Image<T> image;
};

#include "problem.tpp"

#endif