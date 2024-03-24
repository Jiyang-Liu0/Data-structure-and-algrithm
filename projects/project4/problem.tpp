#include "problem.hpp"

template<typename T>
Problem<T>::Problem():image(Image<T>(0,0))
{
    
}

template<typename T>
Problem<T>::Problem(const Image<T>& image):image(image)
{

}

template<typename T>
State Problem<T>::initial()
{
    for (int i=0;i<image.height();i++)
    {
        for (int j=0;j<image.width();j++)
        {
            if (image(i,j) == RED)
            {
                State state = {i,j, image(i,j)};
                return state;
            }
        }
    }
    throw std::logic_error("No red pixel.");
   //return state;
}

template<typename T>
bool Problem<T>::goal(const State state)
{
    if(image(state.row_idx,state.col_idx)!=WHITE)
    {
        return false;
    }

    if(state.row_idx==0 || state.row_idx==image.width()-1
        ||state.col_idx==0 || state.col_idx==image.height()-1)
    {
        return true;
    } else
    {
        return false;
    }
}

template<typename T>
std::vector<State> Problem<T>::actions(const State state)
{
    std::vector<State> stateVector;
    int r=state.row_idx;
    int c=state.col_idx;

    if(image(r-1,c)==WHITE)
    {
        State state = {r-1,c,image(r-1,c)};
        stateVector.push_back(state);
    }

    if(image(r+1,c)==WHITE)
    {
        State state={r+1,c,image(r+1,c)};
        stateVector.push_back(state);
    }

    if(image(r,c-1)==WHITE)
    {
        State state={r,c-1,image(r,c-1)};
        stateVector.push_back(state);
    }

    if(image(r,c+1)==WHITE)
    {
        State state={r,c+1,image(r,c+1)};
        stateVector.push_back(state);
    }

    return stateVector;
}

template<typename T>
bool Problem<T>::isValid()
{
    int redCount = 0;
    for (int i=0;i<image.height();i++)
    {
        for (int j=0;j<image.width();j++)
        {
            if (image(i,j) != RED && image(i,j) != BLACK && image(i,j) != WHITE)
            {
                std::cout<<"Pixel with invalid color."<<std::endl;
                return false;
            }

            if (image(i,j) == RED)
            {
                redCount++;
            }
        }
    }

    if (redCount != 1)
    {
        std::cout<<"None or more than one red pixel."<<std::endl;
        return false;
    }

    return true;
}